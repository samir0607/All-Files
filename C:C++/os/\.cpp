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
            getline(infile, line); p.arrive_time = stoi(line.substr(line.find(":") + 2));
            getline(infile, line); p.exec_size = stoi(line.substr(line.find(":") + 2));
            getline(infile, line); p.priority = stoi(line.substr(line.find(":") + 2));
            p.remaining_time = p.exec_size; // Initialize remaining time
            processes.push_back(p);
        }
    }
}

pair<double, double> calculateFCFS(const vector<Process>& processes, int disp) {
    int current_time = 0;
    vector<Process> proc = processes;
    cout << "\nFCFS:\n\n" ;
    
    double total_turnaround_time = 0;
    double total_waiting_time = 0;

    for (size_t i = 0; i < proc.size(); ++i) {
        Process& p = proc[i];
        current_time = max(current_time, p.arrive_time);
        cout << "   T" << current_time + 1 << ": " << p.id << "(" << p.priority << ")\n";
        current_time += p.exec_size + disp; // Include DISP time
        p.turnaround_time = current_time - p.arrive_time;
        p.waiting_time = p.turnaround_time - p.exec_size;

        // Accumulate totals
        total_turnaround_time += p.turnaround_time;
        total_waiting_time += p.waiting_time;
    }

    cout << "\nProcess\t\t\tTAT\t\t\tWT\n";
    for (const auto& p : proc) {
        cout << p.id << "\t\t\t" << p.turnaround_time << "\t\t\t" << p.waiting_time << "\n";
    }

    return {total_turnaround_time / proc.size(), total_waiting_time / proc.size()};
}

pair<double, double> calculateSPN(const vector<Process>& processes, int disp) {
    vector<Process> proc = processes;
    int current_time = 0;
    cout << "\nSPN:\n\n";
    
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
            cout << "   T" << current_time + 1 << ": " << proc[idx].id << "(" << proc[idx].priority << ")\n";
            current_time += proc[idx].exec_size + disp; // Include DISP time
            proc[idx].turnaround_time = current_time - proc[idx].arrive_time;
            proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].exec_size;
            completed[idx] = true;

            // Accumulate totals
            total_turnaround_time += proc[idx].turnaround_time;
            total_waiting_time += proc[idx].waiting_time;
        }
    }

 cout << "\nProcess\t\t\tTAT\t\t\tWT\n";
    for (const auto& p : proc) {
        cout << p.id << "\t\t\t" << p.turnaround_time << "\t\t\t" << p.waiting_time << "\n";
    }

    return {total_turnaround_time / proc.size(), total_waiting_time / proc.size()};
}

pair<double, double> calculatePP(const vector<Process>& processes, int disp) {
     vector<Process> proc = processes;
    int current_time = 0;
    cout << "\nPP:\n\n";

    double total_turnaround_time = 0;
    double total_waiting_time = 0;
    vector<bool> completed(proc.size(), false);

    int last_executed_idx = -1;

    while (true)
    {
        int idx = -1;
        int min_priority = 5;  
        for (int i = 0; i < proc.size(); i++)
        {
            if (!completed[i] && proc[i].arrive_time <= current_time)
            {
                if (idx == -1 || proc[i].priority < min_priority || 
                    (proc[i].priority == min_priority && proc[i].remaining_time < proc[idx].remaining_time))
                {
                    idx = i;
                    min_priority = proc[i].priority;
                }
            }
        }
        if (idx == -1)
        {
            int next_arrival = INT_MAX;
            for (int i = 0; i < proc.size(); i++)
            {
                if (!completed[i] && proc[i].arrive_time > current_time)
                {
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
            cout << "T" << current_time << ": " << proc[idx].id << "(" << proc[idx].priority << ")\n";
        }

        // Execute the process for 1 unit of time (preemption check after every unit)
        current_time++;
        proc[idx].remaining_time--;

        // If the process finishes
        if (proc[idx].remaining_time == 0)
        {
            proc[idx].turnaround_time = current_time - proc[idx].arrive_time;
            proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].exec_size;
            total_turnaround_time += proc[idx].turnaround_time;
            total_waiting_time += proc[idx].waiting_time;
            completed[idx] = true;
        }
        last_executed_idx = idx;
    }

    cout << "\nProcess\t\t\tTAT\t\t\tWT\n";
    for (const auto &p : proc)
    {
        cout << p.id << "\t\t\t" << p.turnaround_time << "\t\t\t" << p.waiting_time << "\n";
    }
    return {total_turnaround_time / proc.size(), total_waiting_time / proc.size()};
}


pair<double, double> calculatePRR(vector<Process>& processes, int disp) {
    vector<Process> proc = processes;
    int current_time = disp;
    cout << "\nPRR:\n\n";
    
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
                cout << "   T" << current_time << ": " << proc[i].id << "(" << proc[i].priority << ")\n";

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

        // If no process was found to execute, move time forward
        if (!found_process) {
            current_time++;
        } 
    }

    // Output the results
    cout << "\nProcess\t\t\tTAT\t\t\tWT\n";
    for (const auto& p : proc) {
        cout << p.id << "\t\t\t" << p.turnaround_time << "\t\t\t" << p.waiting_time << "\n";
        total_turnaround_time += p.turnaround_time;
        total_waiting_time += p.waiting_time;
    }

    return {total_turnaround_time / n, total_waiting_time / n};
}


void schedulingDisplay(vector<Process>& processes, int disp) {
    auto fcfs = calculateFCFS(processes, disp);
    auto spn = calculateSPN(processes, disp);
    auto pp = calculatePP(processes, disp);
    auto prr = calculatePRR(processes, disp);
    cout << "\nSummary\n";
    cout << "Algorithm\t\tAverage TAT\t\tAverage WT\n";
    cout << "FCFS\t\t\t" << fixed << setprecision(2) << fcfs.first << "\t\t\t" << fixed << setprecision(2) << fcfs.second << "\n";
    cout << "SPN\t\t\t" << fixed << setprecision(2) << spn.first << "\t\t\t" << fixed << setprecision(2) << spn.second << "\n";
    cout << "PP\t\t\t" << fixed << setprecision(2) << pp.first << "\t\t\t" << fixed << setprecision(2) << pp.second << "\n";
    cout << "PRR\t\t\t" << fixed << setprecision(2) << prr.first << "\t\t\t" << fixed << setprecision(2) << prr.second << "\n";
}

int main() {
    vector<Process> processes;

    int disp = 0;
    string input;

    cout << "Enter file name(eg. datafile1.txt): ";
    cin >> input;

    readProcesses(input, processes, disp);
    schedulingDisplay(processes, disp);

    return 0;
}