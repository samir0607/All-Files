#include <iostream>
using namespace std;

void worstFit(int memoryBlocks[], int x, int processes[], int y) {
    int allocation[y];

    for (int i = 0; i < y; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < y; i++) {
        int worstIdx = -1;
        for (int j = 0; j < x; j++) {
            if (memoryBlocks[j] >= processes[i]) {
                if (worstIdx == -1 || memoryBlocks[j] > memoryBlocks[worstIdx]) {
                    worstIdx = j;
                }
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            memoryBlocks[worstIdx] -= processes[i];
        }
    }

    cout << "\nProcess No.\tProcess Size\tBlock No.\n";
    for (int i = 0; i < y; i++) {
        cout << " " << i + 1 << "\t\t" << processes[i] << "\t\t";
        if (allocation[i] != -1)
            cout << allocation[i] + 1;
        else
            cout << "Not Allocated";
        cout << endl;
    }
}

int main() {
    int memoryBlocks[] = {300, 600, 350, 200, 750};
    int processes[] = {250, 700, 175, 500};
    int x = sizeof(memoryBlocks) / sizeof(memoryBlocks[0]);
    int y = sizeof(processes) / sizeof(processes[0]);

    worstFit(memoryBlocks, x, processes, y);

    return 0;
}
