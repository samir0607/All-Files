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

void worstFit(vector<Block>& blocks, vector<int>& processes) {
    for (int i = 0; i < processes.size(); i++) {
        int worstIdx = -1;
        for (int j = 0; j < blocks.size(); j++) {
            if (!blocks[j].allocated && blocks[j].size >= processes[i]) {
                if (worstIdx == -1 || blocks[j].size > blocks[worstIdx].size) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            blocks[worstIdx].allocated = true;
            blocks[worstIdx].pid = i + 1;
            blocks[worstIdx].end = blocks[worstIdx].start + processes[i];
            
            int remainingSize = blocks[worstIdx].size - processes[i];
            if (remainingSize > 0) {
                Block newBlock;
                newBlock.size = remainingSize;
                newBlock.allocated = false;
                newBlock.start = blocks[worstIdx].end;
                newBlock.end = blocks[worstIdx].start + blocks[worstIdx].size;
                newBlock.pid = -1;
                blocks.insert(blocks.begin() + worstIdx + 1, newBlock);
            }

            blocks[worstIdx].size = processes[i];
        } else {
            cerr << "Warning: Cannot allocate process " << i + 1 << " to any block." << endl;
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

    vector<Block> blocks(numBlocks);
    int totalMemory = 0;

    for (int i = 0; i < numBlocks; i++) {
        cout << "Enter the size of block " << i + 1 << ": ";
        cin >> blocks[i].size;
        blocks[i].allocated = false;
        blocks[i].pid = -1;
        blocks[i].start = totalMemory;
        blocks[i].end = totalMemory + blocks[i].size;
        totalMemory += blocks[i].size;
    }

    cout << "Enter the number of processes: ";
    cin >> numProcesses;

    vector<int> processes(numProcesses);
    for (int i = 0; i < numProcesses; i++) {
        cout << "Enter the size of process " << i + 1 << ": ";
        cin >> processes[i];
    }

    worstFit(blocks, processes);

    return 0;
}
