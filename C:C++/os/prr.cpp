#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    string id;
    int arrive_time;
    int exec_size;
    int priority;
    int waiting_time = 0;
    int turnaround_time = 0;
    int completion_time = 0;
    int remaining_time = 0;

    Process(string id, int arrive_time, int exec_size, int priority)
        : id(id), arrive_time(arrive_time), exec_size(exec_size), priority(priority) {
        remaining_time = exec_size; // Initialize remaining time with execution size
    }
};

void readInputFile(const string& filename, vector<Process>& processes, int& disp) {
    ifstream infile(filename);
    string line;
    bool inProcessSection = false;

    if (infile.is_open()) {
        while (getline(infile, line)) {
            if (line.find("DISP:") != string::npos) {
                disp = stoi(line.substr(line.find(":") + 1));
            } else if (line.find("ID:") != string::npos) {
                string id = line.substr(line.find(":") + 1);
                int arrive_time, exec_size, priority;
                
                // Read the next lines for arrival time, execution size, and priority
                while (getline(infile, line) && line != "END") {
                    if (line.find("Arrive:") != string::npos) {
                        arrive_time = stoi(line.substr(line.find(":") + 1));
                    } else if (line.find("ExecSize:") != string::npos) {
                        exec_size = stoi(line.substr(line.find(":") + 1));
                    } else if (line.find("Priority:") != string::npos) {
                        priority = stoi(line.substr(line.find(":") + 1));
                    }
                }
                processes.emplace_back(id, arrive_time, exec_size, priority);
            }
        }
        infile.close();
    } else {
        cerr << "Unable to open file." << endl;
    }
}

void calculatePP(vector<Process>& processes, int disp) {
    vector<Process> ready_queue;
    int current_time = 0;
    int completed = 0;

    cout << "PP Scheduling Gantt Chart:" << endl;
    while (completed < processes.size()) {
        // Add processes that have arrived to the ready queue
        for (auto& p : processes) {
            if (p.arrive_time <= current_time && p.remaining_time > 0 && 
                find_if(ready_queue.begin(), ready_queue.end(), [&](Process& r) { return r.id == p.id; }) == ready_queue.end()) {
                ready_queue.push_back(p);
            }
        }

        // Sort ready queue based on priority (lower number is higher priority)
        sort(ready_queue.begin(), ready_queue.end(), [](Process& a, Process& b) {
            return a.priority < b.priority || (a.priority == b.priority && a.id < b.id);
        });

        if (!ready_queue.empty()) {
            // Select the highest priority process from the ready queue
            Process& current_process = ready_queue.front();

            // Run the current process for 1 unit time
            cout << "T" << current_time + 1 << ": " << current_process.id << "(1)" << endl;

            current_process.remaining_time--;
            current_time++;
            
            // Check if the process is completed
            if (current_process.remaining_time == 0) {
                current_process.completion_time = current_time;
                completed++;
                current_process.turnaround_time = current_process.completion_time - current_process.arrive_time;
                current_process.waiting_time = current_process.turnaround_time - current_process.exec_size;
            }
        } else {
            // If no process is ready, just increment the time
            current_time++;
        }
    }

    // Output results
    cout << "Process\tTurnaround Time\tWaiting Time" << endl;
    for (const auto& p : processes) {
        cout << p.id << "\t" << p.turnaround_time << "\t\t" << p.waiting_time << endl;
    }
}

void calculatePRR(vector<Process>& processes, int disp) {
    vector<Process> ready_queue;
    int current_time = 0;
    int completed = 0;
    int time_quantum;

    cout << "PRR Scheduling Gantt Chart:" << endl;
    while (completed < processes.size()) {
        // Add processes that have arrived to the ready queue
        for (auto& p : processes) {
            if (p.arrive_time <= current_time && p.remaining_time > 0 && 
                find_if(ready_queue.begin(), ready_queue.end(), [&](Process& r) { return r.id == p.id; }) == ready_queue.end()) {
                ready_queue.push_back(p);
            }
        }

        if (!ready_queue.empty()) {
            // Determine time quantum based on process priority
            Process& current_process = ready_queue.front();
            time_quantum = (current_process.priority <= 2) ? 4 : 2;

            // Run the current process for the determined time quantum or until it finishes
            int exec_time = min(time_quantum, current_process.remaining_time);

            cout << "T" << current_time + 1 << ": " << current_process.id << "(" << exec_time << ")" << endl;

            current_process.remaining_time -= exec_time;
            current_time += exec_time;

            // Check if the process is completed
            if (current_process.remaining_time == 0) {
                current_process.completion_time = current_time;
                completed++;
                current_process.turnaround_time = current_process.completion_time - current_process.arrive_time;
                current_process.waiting_time = current_process.turnaround_time - current_process.exec_size;
                ready_queue.erase(ready_queue.begin()); // Remove completed process
            } else {
                // Move the current process to the back of the queue
                ready_queue.push_back(current_process);
                ready_queue.erase(ready_queue.begin());
            }

            // If the dispatcher time is greater than 0, simulate dispatcher time
            if (disp > 0) {
                current_time += disp; // Add dispatcher time
            }
        } else {
            // If no process is ready, just increment the time
            current_time++;
        }
    }

    // Output results
    cout << "Process\tTurnaround Time\tWaiting Time" << endl;
    for (const auto& p : processes) {
        cout << p.id << "\t" << p.turnaround_time << "\t\t" << p.waiting_time << endl;
    }
}

int main() {
    int disp = 1; // Dispatcher time
    vector<Process> processes;

    // Read processes from input file
    readInputFile("input.txt", processes, disp);

    // Calculate and display PP scheduling
    cout << "----- Preemptive Priority (PP) -----" << endl;
    calculatePP(processes, disp);
    cout << endl;

    // Reset processes for PRR calculation
    readInputFile("datafile2.txt", processes, disp); // Read again for PRR

    // Calculate and display PRR scheduling
    cout << "----- Priority Round Robin (PRR) -----" << endl;
    calculatePRR(processes, disp);
    
    return 0;
}
