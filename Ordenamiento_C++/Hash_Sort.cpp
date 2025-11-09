#include <iostream>
#include <vector>
using namespace std;

void hashSort(vector<int>& arr, int maxVal) {
    vector<int> hashTable(maxVal + 1, 0);

    for (int num : arr)
        hashTable[num] = 1;

    arr.clear();
    for (int i = 0; i <= maxVal; i++)
        if (hashTable[i] == 1)
            arr.push_back(i);
}

int main() {
    vector<int> arr = {5, 2, 8, 3, 1};
    hashSort(arr, 10);

    for (int num : arr)
        cout << num << " ";
    return 0;
}
