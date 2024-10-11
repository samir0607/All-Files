#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <string>

using namespace std;

// Process structure
struct Process {
    string pid;          // Process ID
    int arrival;         // Arrival time
    int burst;           // Burst time (execution size)
    int priority;        // Priority
    int remaining;       // Remaining time (for preemptive algorithms)
    int start_time = -1; // Start time
    int finish_time = -1;// Finish time
    int response_time = -1; // Response time
    int waiting_time = 0;    // Waiting time
    int turnaround_time = 0; // Turnaround time
};

// Global dispatcher time
int DISP = 0;

// Function to read processes from the input file
vector<Process> readProcessesFromFile(const string& datafile1) {
    vector<Process> processes;
    ifstream infile(datafile1);
    string line;
    bool parsing_dispatcher = false;
    bool parsing_process = false;
    Process current_process;
    while (getline(infile, line)) {
        if (line == "BEGIN") {
            parsing_dispatcher = true;
            continue;
        }
        if (line == "END") {
            if (parsing_dispatcher) {
                parsing_dispatcher = false;
            }
            if (parsing_process) {
                processes.push_back(current_process);
                parsing_process = false;
            }
            continue;
        }
        if (line == "EOF") {
            break;
        }
        if (parsing_dispatcher) {
            if (line.find("DISP:") != string::npos) {
                size_t pos = line.find(":");
                DISP = stoi(line.substr(pos+1));
            }
        }
        else {
            if (line.find("ID:") != string::npos) {
                parsing_process = true;
                current_process = Process(); // Reset current process
                size_t pos = line.find(":");
                current_process.pid = line.substr(pos+1);
            }
            else if (parsing_process) {
                if (line.find("Arrive:") != string::npos) {
                    size_t pos = line.find(":");
                    current_process.arrival = stoi(line.substr(pos+1));
                }
                else if (line.find("ExecSize:") != string::npos) {
                    size_t pos = line.find(":");
                    current_process.burst = stoi(line.substr(pos+1));
                    current_process.remaining = current_process.burst; // Initialize remaining time
                }
                else if (line.find("Priority:") != string::npos) {
                    size_t pos = line.find(":");
                    current_process.priority = stoi(line.substr(pos+1));
                }
            }
        }
    }
    return processes;
}

// Helper function to calculate averages
pair<double, double> calculateAverages(const vector<Process>& processes) {
    double total_turnaround = 0;
    double total_waiting = 0;
    for (const auto& p : processes) {
        total_turnaround += p.turnaround_time;
        total_waiting += p.waiting_time;
    }
    return { total_turnaround / processes.size(), total_waiting / processes.size() };
}

// Function to display results with time-stamped format
void displayResultsWithTimestamps(const vector<Process>& processes, const string& algorithm) {
    cout << "\n" << algorithm << ":\n";

    // Display time-stamped process execution
    for (const auto& p : processes) {
        cout << "T" << p.start_time << ": " << p.pid << "(" << p.priority << ")\n";
    }

    // Display turnaround and waiting time table
    cout << "\nProcess Turnaround Time Waiting Time\n";
    for (const auto& p : processes) {
        cout << p.pid << "\t" << p.turnaround_time << "\t\t" << p.waiting_time << "\n";
    }
}

// FCFS Scheduling Algorithm
void fcfs(vector<Process> processes) {
    int time = 0;
    vector<Process> finished_processes;

    // Sort the processes by arrival time
    sort(processes.begin(), processes.end(), [](const Process& a, const Process& b){
        return a.arrival < b.arrival;
    });

    for (auto& p : processes) {
        if (time < p.arrival) {
            time = p.arrival;
        }

        // Add dispatcher time if this is not the first process
        if (&p != &processes[0]) {
            time += DISP;
        }

        p.start_time = time;
        time += p.burst;
        p.finish_time = time;

        p.turnaround_time = p.finish_time - p.arrival;
        p.waiting_time = p.start_time - p.arrival;
        p.response_time = p.start_time - p.arrival;

        finished_processes.push_back(p);
    }

    displayResultsWithTimestamps(finished_processes, "FCFS");

    pair<double, double> averages = calculateAverages(finished_processes);
    double avg_turnaround = averages.first;
    double avg_waiting = averages.second;
    cout << "Average Turnaround Time: " << avg_turnaround << "\n";
    cout << "Average Waiting Time: " << avg_waiting << "\n";
}

// SPN Scheduling Algorithm
void spn(vector<Process> processes) {
    int time = 0;
    vector<Process> finished_processes;
    vector<Process> ready_queue;

    while (!processes.empty() || !ready_queue.empty()) {
        // Move newly arrived processes to the ready queue
        for (auto it = processes.begin(); it != processes.end();) {
            if (it->arrival <= time) {
                ready_queue.push_back(*it);
                it = processes.erase(it);
            } else {
                ++it;
            }
        }

        if (!ready_queue.empty()) {
            // Sort ready queue by burst time
            sort(ready_queue.begin(), ready_queue.end(), [](const Process& a, const Process& b) {
                return a.burst < b.burst;
            });

            if (!finished_processes.empty()) {
                time += DISP; // Add dispatcher time between context switches
            }

            Process p = ready_queue.front();
            ready_queue.erase(ready_queue.begin());

            p.start_time = time;
            time += p.burst;
            p.finish_time = time;

            p.turnaround_time = p.finish_time - p.arrival;
            p.waiting_time = p.start_time - p.arrival;
            p.response_time = p.start_time - p.arrival;

            finished_processes.push_back(p);
        } else {
            time++;
        }
    }

    displayResultsWithTimestamps(finished_processes, "SPN");

    pair<double, double> averages = calculateAverages(finished_processes);
    double avg_turnaround = averages.first;
    double avg_waiting = averages.second;
    cout << "Average Turnaround Time: " << avg_turnaround << "\n";
    cout << "Average Waiting Time: " << avg_waiting << "\n";
}

// Priority Preemptive Scheduling Algorithm
void pp(vector<Process> processes) {
    int time = 0;
    vector<Process> finished_processes;
    vector<Process*> ready_queue;
    Process* current_process = nullptr;

    while (!processes.empty() || current_process != nullptr || !ready_queue.empty()) {
        // Add newly arrived processes to the ready queue
        for (auto it = processes.begin(); it != processes.end();) {
            if (it->arrival == time) {
                ready_queue.push_back(&(*it));
                it = processes.erase(it);
            } else {
                ++it;
            }
        }

        if (current_process == nullptr || !ready_queue.empty()) {
            sort(ready_queue.begin(), ready_queue.end(), [](const Process* a, const Process* b) {
                return a->priority < b->priority;
            });

            Process* next_process = ready_queue.front();
            if (current_process == nullptr || next_process->priority < current_process->priority) {
                if (current_process != nullptr) {
                    ready_queue.push_back(current_process);
                }
                current_process = next_process;
                ready_queue.erase(ready_queue.begin());

                time += DISP;  // Context switch adds dispatcher time
                current_process->start_time = time;
            }
        }

        if (current_process) {
            current_process->remaining--;
            if (current_process->remaining == 0) {
                current_process->finish_time = time + 1;
                current_process->turnaround_time = current_process->finish_time - current_process->arrival;
                current_process->waiting_time = current_process->turnaround_time - current_process->burst;
                finished_processes.push_back(*current_process);
                current_process = nullptr;
            }
        }
        time++;
    }

    displayResultsWithTimestamps(finished_processes, "PP");

    pair<double, double> averages = calculateAverages(finished_processes);
    double avg_turnaround = averages.first;
    double avg_waiting = averages.second;
    cout << "Average Turnaround Time: " << avg_turnaround << "\n";
    cout << "Average Waiting Time: " << avg_waiting << "\n";
}

// Round Robin Scheduling Algorithm
void round_robin(vector<Process> processes, int quantum) {
    int time = 0;
    queue<Process*> ready_queue;
    vector<Process> finished_processes;

    for (auto& p : processes) {
        ready_queue.push(&p);
    }

    while (!ready_queue.empty()) {
        Process* p = ready_queue.front();
        ready_queue.pop();

        // If process has arrived
        if (p->arrival <= time) {
            if (p->remaining > quantum) {
                p->remaining -= quantum;
                time += quantum;
                ready_queue.push(p); // Re-add process to the queue
            } else {
                time += p->remaining;
                p->remaining = 0;
                p->finish_time = time;

                p->turnaround_time = p->finish_time - p->arrival;
                p->waiting_time = p->turnaround_time - p->burst;
                p->response_time = p->start_time - p->arrival;

                finished_processes.push_back(*p);
            }
        } else {
            time++;
            ready_queue.push(p);
        }
    }

    displayResultsWithTimestamps(finished_processes, "Round Robin");

    pair<double, double> averages = calculateAverages(finished_processes);
    double avg_turnaround = averages.first;
    double avg_waiting = averages.second;
    cout << "Average Turnaround Time: " << avg_turnaround << "\n";
    cout << "Average Waiting Time: " << avg_waiting << "\n";
}

int main() {
    vector<Process> processes = readProcessesFromFile("processes.txt");

    cout << "Choose Scheduling Algorithm:\n";
    cout << "1. FCFS\n";
    cout << "2. SPN\n";
    cout << "3. Priority Preemptive\n";
    cout << "4. Round Robin\n";
    
    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            fcfs(processes);
            break;
        case 2:
            spn(processes);
            break;
        case 3:
            pp(processes);
            break;
        case 4:
            int quantum;
            cout << "Enter time quantum: ";
            cin >> quantum;
            round_robin(processes, quantum);
            break;
        default:
            cout << "Invalid choice!";
            break;
    }

    return 0;
}
