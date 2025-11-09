using System;

class Hash_Sort {
    static void HashSort(int[] arr, int maxVal) {
        bool[] hashTable = new bool[maxVal + 1];

        foreach (int num in arr)
            hashTable[num] = true;

        int index = 0;
        for (int i = 0; i <= maxVal; i++)
            if (hashTable[i])
                arr[index++] = i;
    }

    static void Main() {
        int[] arr = {5, 2, 8, 3, 1};
        HashSort(arr, 10);

        foreach (int num in arr)
            Console.Write(num + " ");
    }
}
