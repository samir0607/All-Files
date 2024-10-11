#include <iostream>
#include <vector>

using namespace std;

struct Block {
    int size;
    bool allocated;
    int start;
    int end;
    int pid;
};

void bestFit(vector<Block>& blocks, vector<int>& processes) {
    for (int i = 0; i < processes.size(); i++) {
        int bestIdx = -1;
        int minDiff = INT_MAX;

        for (int j = 0; j < blocks.size(); j++) {
            if (!blocks[j].allocated && blocks[j].size >= processes[i]) {
                int diff = blocks[j].size - processes[i];
                if (diff < minDiff) {
                    bestIdx = j;
                    minDiff = diff;
                }
            }
        }

        if (bestIdx != -1) {
            blocks[bestIdx].allocated = true;
            blocks[bestIdx].pid = i + 1;
            blocks[bestIdx].end = blocks[bestIdx].start + processes[i];
            
            int remainingSize = blocks[bestIdx].size - processes[i];

            // Only split if the remaining size is significant
            if (remainingSize > 10) {  // Threshold can be adjusted
                Block newBlock;
                newBlock.size = remainingSize;
                newBlock.allocated = false;
                newBlock.start = blocks[bestIdx].end;
                newBlock.end = blocks[bestIdx].start + blocks[bestIdx].size;
                newBlock.pid = -1;
                blocks.insert(blocks.begin() + bestIdx + 1, newBlock);
            }

            blocks[bestIdx].size = processes[i];
        } else {
            cerr << "Warning: Cannot allocate process " << i + 1 << " (Size: " << processes[i] << ") to any block." << endl;
        }
    }

    cout << "\nMemory Allocation:" << endl;
    for (int i = 0; i < blocks.size(); i++) {
        if (blocks[i].allocated) {
            cout << "[PID: " << blocks[i].pid << ", Size: " << blocks[i].size
                 << ", Start: " << blocks[i].start << ", End: " << blocks[i].end << "], "<<endl;
        } else {
            cout << "[FREE, Size: " << blocks[i].size << ", Start: " << blocks[i].start
                 << ", End: " << blocks[i].end << "], "<<endl;
        }
    }
    cout << endl;
}

int main() {
    int numBlocks, numProcesses;

    cout << "Enter the number of blocks: ";
    cin >> numBlocks;

    if (numBlocks <= 0) {
        cerr << "Error: Number of blocks must be a positive integer." << endl;
        return 1;
    }

    vector<Block> blocks(numBlocks);
    int totalMemory = 0;

    for (int i = 0; i < numBlocks; i++) {
        cout << "Enter the size of block " << i + 1 << ": ";
        cin >> blocks[i].size;

        if (blocks[i].size <= 0) {
            cerr << "Error: Block size must be a positive integer." << endl;
            return 1;
        }

        blocks[i].allocated = false;
        blocks[i].pid = -1;
        blocks[i].start = totalMemory;
        blocks[i].end = totalMemory + blocks[i].size;
        totalMemory += blocks[i].size;
    }

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    if (numProcesses <= 0) {
        cerr << "Error: Number of processes must be a positive integer." << endl;
        return 1;
    }

    vector<int> processes(numProcesses);
    for (int i = 0; i < numProcesses; i++) {
        cout << "Enter the size of process " << i + 1 << ": ";
        cin >> processes[i];
        if (processes[i] <= 0) {
            cerr << "Error: Process size must be a positive integer." << endl;
            return 1;
        }
    }

    bestFit(blocks, processes);

    return 0;
}
