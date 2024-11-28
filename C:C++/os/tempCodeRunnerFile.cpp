#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

void calculateFCFS(const vector<Process>& processes, int disp) {
    int current_time = 0;
    vector<Process> proc = processes;
    cout << "FCFS:\n";
    
    double total_turnaround_time = 0;
    double total_waiting_time = 0;

    for (size_t i = 0; i < proc.size(); ++i) {
        Process& p = proc[i];
        current_time = max(current_time, p.arrive_time);
        cout << "T" << current_time + 1 << ": " << p.id << "(" << p.priority << ")\n";
        current_time += p.exec_size + disp; // Include DISP time
        p.turnaround_time = current_time - p.arrive_time;
        p.waiting_time = p.turnaround_time - p.exec_size;

        // Accumulate totals
        total_turnaround_time += p.turnaround_time;
        total_waiting_time += p.waiting_time;
    }

    cout << "\nProcess\tTurnaround Time\tWaiting Time\n";
    for (const auto& p : proc) {
        cout << p.id << "\t" << p.turnaround_time << "\t\t" << p.waiting_time << "\n";
    }

    // Calculate and display averages
    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << (total_turnaround_time / proc.size()) << "\n";
    cout << "Average Waiting Time: " << (total_waiting_time / proc.size()) << "\n\n";
}

void calculateSPN(const vector<Process>& processes, int disp) {
    vector<Process> proc = processes;
    int current_time = 0;
    cout << "SPN:\n";
    
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
            cout << "T" << current_time + 1 << ": " << proc[idx].id << "(" << proc[idx].priority << ")\n";
            current_time += proc[idx].exec_size + disp; // Include DISP time
            proc[idx].turnaround_time = current_time - proc[idx].arrive_time;
            proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].exec_size;
            completed[idx] = true;

            // Accumulate totals
            total_turnaround_time += proc[idx].turnaround_time;
            total_waiting_time += proc[idx].waiting_time;
        }
    }

    cout << "\nProcess\tTurnaround Time\tWaiting Time\n";
    for (const auto& p : proc) {
        cout << p.id << "\t" << p.turnaround_time << "\t\t" << p.waiting_time << "\n";
    }

    // Calculate and display averages
    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << (total_turnaround_time / proc.size()) << "\n";
    cout << "Average Waiting Time: " << (total_waiting_time / proc.size()) << "\n\n";
}


void calculatePP(const vector<Process>& processes, int disp) {
    vector<Process> proc = processes;
    int current_time = disp;
    cout << "PP:\n";
    
    double total_turnaround_time = 0;
    double total_waiting_time = 0;
    vector<bool> completed(proc.size(), false);

    while (true) {
        int idx = -1;
        int min_priority = 6;

        // Find the highest priority process that has arrived
        for (int i = 0; i < proc.size(); i++) {
            // Check if the process has arrived and has not been completed
            if (!completed[i] && proc[i].arrive_time <= current_time-disp) {
                // If process has the same priority, check IDs to break tie
                if (idx == -1 || 
                    (proc[i].priority < min_priority) || 
                    (proc[i].priority == min_priority && proc[i].arrive_time < proc[idx].arrive_time)) {
                    idx = i;
                    min_priority = proc[i].priority;
                }
            }
        }

        if (idx == -1) break;

        // Execute the current process until a new process arrives or it finishes
        int next_arrival_time = INT_MAX;
        for (int i = 0; i < proc.size(); i++) {
            if (!completed[i] && proc[i].arrive_time > current_time) {
                next_arrival_time = min(next_arrival_time, proc[i].arrive_time);
            }
        }

        // Calculate the execution time (until the next process arrives or the current process completes)
        int execution_time = min(proc[idx].exec_size, next_arrival_time - current_time);
        if (execution_time <= 0) execution_time = proc[idx].exec_size;

        cout << "T" << current_time << ": " << proc[idx].id << "(" << proc[idx].priority << ")\n";
        
        current_time += execution_time;
        proc[idx].exec_size -= execution_time;

        // If the process is done
        if (proc[idx].exec_size == 0) {
            proc[idx].turnaround_time = current_time - proc[idx].arrive_time;
            proc[idx].waiting_time = proc[idx].turnaround_time - proc[idx].remaining_time;
            total_turnaround_time += proc[idx].turnaround_time;
            total_waiting_time += proc[idx].waiting_time;
            completed[idx] = true;
        }
        current_time += disp;
    }

    cout << "\nProcess\tTurnaround Time\tWaiting Time\n";
    for (const auto& p : proc) {
        cout << p.id << "\t" << p.turnaround_time << "\t\t" << p.waiting_time << "\n";
    }

    // Calculate and display averages
    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << (total_turnaround_time / proc.size()) << "\n";
    cout << "Average Waiting Time: " << (total_waiting_time / proc.size()) << "\n\n";
}
void calculatePRR(vector<Process>& processes, int disp) {
    vector<Process> proc = processes;
    int current_time = disp;
    cout << "PRR:\n";
    
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
                cout << "T" << current_time << ": " << proc[i].id << "(" << proc[i].priority << ")\n";

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
                current_time += disp;
            }
        }

        // If no process was found to execute, move time forward
        if (!found_process) {
            current_time++;
        } 
}

    // Output the results
    cout << "\nProcess\tTurnaround Time\tWaiting Time\n";
    for (const auto& p : proc) {
        cout << p.id << "\t" << p.turnaround_time << "\t\t" << p.waiting_time << "\n";
        total_turnaround_time += p.turnaround_time;
        total_waiting_time += p.waiting_time;
    }

    // Calculate and display averages
    cout << fixed << setprecision(2);
    cout << "\nAverage Turnaround Time: " << (total_turnaround_time / n) << "\n";
    cout << "Average Waiting Time: " << (total_waiting_time / n) << "\n\n";
}

int main() {
    vector<Process> processes;
    int disp = 0;
    readProcesses("datafile2.txt", processes, disp);

    calculateFCFS(processes, disp);
    calculateSPN(processes, disp);
    calculatePP(processes, disp);
    calculatePRR(processes, disp);

    return 0;
}
