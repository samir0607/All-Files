#include <iostream>
using namespace std;

void bestFit(int memoryBlocks[], int x, int processes[], int y) {
    int allocation[y];

    for (int i = 0; i < y; i++) {
        allocation[i] = -1;
    }

    for (int i = 0; i < y; i++) {
        int bestIdx = -1;
        for (int j = 0; j < x; j++) {
            if (memoryBlocks[j] >= processes[i]) {
                if (bestIdx == -1 || memoryBlocks[j] < memoryBlocks[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            memoryBlocks[bestIdx] -= processes[i];
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

    bestFit(memoryBlocks, x, processes, y);

    return 0;
}
