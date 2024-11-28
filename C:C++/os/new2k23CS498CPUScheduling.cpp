#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

struct Process {
    string id;
    int arrive_time;
    int exec_size;
    int priority;
    int turnaround_time;
    int waiting_time;
    int remaining_time;
};

void readProcesses(const string& filename, vector<Process>& processes, int& disp) {
    ifstream infile(filename);
    string line;

    while (getline(infile, line)) {
        if (line == "EOF") break;
        if (line.find("DISP:") != string::npos) {
            disp = stoi(line.substr(line.find(":") + 2)); // Read DISP
        }
        if (line.find("ID:") != string::npos) {
            Process p;
            p.id = line.substr(line.find(":") + 2);
            p.id.erase(p.id.find_last_not_of(" \n\r\t") + 1);
            getline(infile, line); p.arrive_time = stoi(line.substr(line.find(":") + 2));
            getline(infile, line); p.exec_size = stoi(line.substr(line.find(":") + 2));
            getline(infile, line); p.priority = stoi(line.substr(line.find(":") + 2));
            p.remaining_time = p.exec_size; // Initialize remaining time
            processes.push_back(p);
        }
    }
}

pair<double, double> calculateFCFS(ofstream& output, const vector<Process>& processes, int disp) {
    int current_time = 0;
    vector<Process> proc = processes;
    output << "\nFCFS:\n\n";

    double total_turnaround_time = 0;
    double total_waiting_time = 0;

    for (size_t i = 0; i < proc.size(); ++i) {
        Process& p = proc[i];
        current_time = max(current_time, p.arrive_time);
        output << "T" << current_time + 1 << ": " << p.id << "(" << p.priority << ")\n";
        current_time += p.exec_size + disp; // Include DISP time
        p.turnaround_time = current_time - p.arrive_time;
        p.waiting_time = p.turnaround_time - p.exec_size;

        // Accumulate totals
        total_turnaround_time += p.turnaround_time;
        total_waiting_time += p.waiting_time;
    }

    output << "\nProcess\t\tTAT\t\t\tWT\n";
    for (const auto& p : proc) {
        output << p.id << "\t\t\t" << p.turnaround_time << "\t\t\t" << p.waiting_time << "\n";
    }

    return {total_turnaround_time / proc.size(), total_waiting_time / proc.size()};
}

pair<double, double> calculateSPN(ofstream& output, const vector<Process>& processes, int disp) {
    vector<Process> proc = processes;
    int current_time = 0;
    output << "\nSPN:\n\n";

    double total_turnaround_time = 0;
    double total_waiting_time = 0;
    vector<bool> completed(proc.size(), false);

    for (int i = 0; i < proc.size(); i++) {
        int idx = -1;
        int min_exec = INT_MAX;

        for (int j = 0; j < proc.size(); j++) {
            if (!completed[j] && proc[j].arrive_time <= current_time && proc[j].exec_size < min_exec) {
                min_exec = proc[j].exec_size;
                idx = j;
            }
        }

        if (idx != -1) {
            current_time = max(current_time, proc[idx].arrive_time);
            output << "T" << current_time + 1 << ": " << proc[idx].id << "(" << proc[idx].priority << ")\n";
            current_time += proc[idx].exec_size + disp; // Include DISP time
            proc[idx].turnaround_time = current_time - proc[idx].arrive_time;
            proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].exec_size;
            completed[idx] = true;

            // Accumulate totals
            total_turnaround_time += proc[idx].turnaround_time;
            total_waiting_time += proc[idx].waiting_time;
        }
    }

    output << "\nProcess\t\tTAT\t\t\tWT\n";
    for (const auto& p : proc) {
        output << p.id << "\t\t\t" << p.turnaround_time << "\t\t\t" << p.waiting_time << "\n";
    }

    return {total_turnaround_time / proc.size(), total_waiting_time / proc.size()};
}

pair<double, double> calculatePP(ofstream& output, const vector<Process>& processes, int disp) {
    vector<Process> proc = processes;
    int current_time = 0;
    output << "\nPP:\n\n";

    double total_turnaround_time = 0;
    double total_waiting_time = 0;
    vector<bool> completed(proc.size(), false);

    int last_executed_idx = -1;

    while (true) {
        int idx = -1;
        int min_priority = 5;  
        for (int i = 0; i < proc.size(); i++) {
            if (!completed[i] && proc[i].arrive_time <= current_time) {
                if (idx == -1 || proc[i].priority < min_priority || 
                    (proc[i].priority == min_priority && proc[i].remaining_time < proc[idx].remaining_time)) {
                    idx = i;
                    min_priority = proc[i].priority;
                }
            }
        }
        if (idx == -1) {
            int next_arrival = INT_MAX;
            for (int i = 0; i < proc.size(); i++) {
                if (!completed[i] && proc[i].arrive_time > current_time) {
                    next_arrival = min(next_arrival, proc[i].arrive_time);
                }
            }
            if (next_arrival == INT_MAX) break;
            current_time = next_arrival;
            continue;
        }
        // If we're switching to a different process, account for dispatcher time
        if (last_executed_idx != idx) {
            current_time += disp;
            output << "T" << current_time << ": " << proc[idx].id << "(" << proc[idx].priority << ")\n";
        }

        // Execute the process for 1 unit of time (preemption check after every unit)
        current_time++;
        proc[idx].remaining_time--;

        // If the process finishes
        if (proc[idx].remaining_time == 0) {
            proc[idx].turnaround_time = current_time - proc[idx].arrive_time;
            proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].exec_size;
            total_turnaround_time += proc[idx].turnaround_time;
            total_waiting_time += proc[idx].waiting_time;
            completed[idx] = true;
        }
        last_executed_idx = idx;
    }

    output << "\nProcess\t\tTAT\t\t\tWT\n";
    for (const auto &p : proc) {
        output << p.id << "\t\t\t" << p.turnaround_time << "\t\t\t" << p.waiting_time << "\n";
    }
    return {total_turnaround_time / proc.size(), total_waiting_time / proc.size()};
}

pair<double, double> calculatePRR(ofstream& output, vector<Process>& processes, int disp) {
    vector<Process> proc = processes;
    int current_time = disp;
    output << "\nPRR:\n\n";

    double total_turnaround_time = 0;
    double total_waiting_time = 0;
    int completed_count = 0; // Count of completed processes
    int n = proc.size();

    while (completed_count < n) {
        bool found_process = false;

        for (size_t i = 0; i < proc.size(); ++i) {
            if (proc[i].remaining_time > 0 && proc[i].arrive_time <= current_time-disp) {
                found_process = true;

                // Determine time quantum based on priority
                int quantum = (proc[i].priority <= 2) ? 4 : 2;

                // Output process execution
                output << "T" << current_time << ": " << proc[i].id << "(" << proc[i].priority << ")\n";

                // Execute for the minimum of quantum or remaining time
                int exec_time = min(quantum, proc[i].remaining_time);
                current_time += exec_time;
                proc[i].remaining_time -= exec_time;

                // If process finishes, update turnaround and waiting times
                if (proc[i].remaining_time == 0) {
                    proc[i].turnaround_time = current_time - proc[i].arrive_time;
                    proc[i].waiting_time = proc[i].turnaround_time - proc[i].exec_size;
                    completed_count++; // Increment completed count
                }

                // Only add DISP time if there is a context switch needed
                if (completed_count < n) {
                    current_time += disp;
                }
            }
        }

        // If no process was found to execute, increment current_time
        if (!found_process) {
            current_time++;
        }
    }

    // Output the results
    output << "\nProcess\t\tTAT\t\t\tWT\n";
    for (const auto& p : proc) {
        output << p.id << "\t\t\t" << p.turnaround_time << "\t\t\t" << p.waiting_time << "\n";
        total_turnaround_time += p.turnaround_time;
        total_waiting_time += p.waiting_time;
    }

    return {total_turnaround_time / n, total_waiting_time / n};
}

void schedulingDisplay(ofstream& output, vector<Process>& processes, int disp) {
    auto fcfs = calculateFCFS(output, processes, disp);
    auto spn = calculateSPN(output, processes, disp);
    auto pp = calculatePP(output, processes, disp);
    auto prr = calculatePRR(output, processes, disp);

    output << "\nSummary\n";
    output << "Algorithm\tAverage TAT\tAverage WT\n";
    output << "FCFS\t\t" << fixed << setprecision(2) << fcfs.first << "\t\t\t" << fixed << setprecision(2) << fcfs.second << "\n";
    output << "SPN\t\t\t" << fixed << setprecision(2) << spn.first << "\t\t\t" << fixed << setprecision(2) << spn.second << "\n";
    output << "PP\t\t\t" << fixed << setprecision(2) << pp.first << "\t\t\t" << fixed << setprecision(2) << pp.second << "\n";
    output << "PRR\t\t\t" << fixed << setprecision(2) << prr.first << "\t\t\t" << fixed << setprecision(2) << prr.second << "\n";
}

int main() {
    vector<Process> processes;
    int disp = 0;
    string input;

    cout << "Enter input file name(eg. datafile1.txt): ";
    cin >> input;

    // Create or open the output file in append mode
    ofstream output(input+"_output.txt", ios::app);
    if (!output) {
        cerr << "Error opening file for writing.\n";
        return 1;
    }

    output << "Input File: " << input << "\n";

    readProcesses(input, processes, disp);
    schedulingDisplay(output, processes, disp);
    
    cout << "Output file is created and all output is appended in file: " << input << "_output.txt";
    
    output.close();
    return 0;
}
