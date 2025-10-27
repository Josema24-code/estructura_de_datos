import java.util.*;

public class Hash_Sort {
    public static void hashSort(int[] arr, int maxVal) {
        boolean[] hashTable = new boolean[maxVal + 1];

        for (int num : arr)
            hashTable[num] = true;

        int index = 0;
        for (int i = 0; i <= maxVal; i++)
            if (hashTable[i])
                arr[index++] = i;
    }

    public static void main(String[] args) {
        int[] arr = {5, 2, 8, 3, 1};
        hashSort(arr, 10);

        for (int num : arr)
            System.out.print(num + " ");
    }
}
