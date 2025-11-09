using System;
using System.Collections.Generic;

class Bucket_Sort {
    static void BucketSort(float[] arr) {
        int n = arr.Length;
        List<float>[] buckets = new List<float>[n];
        for (int i = 0; i < n; i++)
            buckets[i] = new List<float>();

        // Distribuir en cubetas
        foreach (float num in arr) {
            int index = (int)(n * num);
            buckets[index].Add(num);
        }

        // Ordenar cada cubeta
        for (int i = 0; i < n; i++)
            buckets[i].Sort();

        // Unir todas las cubetas
        int k = 0;
        foreach (var bucket in buckets)
            foreach (float num in bucket)
                arr[k++] = num;
    }

    static void Main() {
        float[] arr = {0.78f, 0.17f, 0.39f, 0.26f, 0.72f, 0.94f, 0.21f, 0.12f, 0.23f, 0.68f};
        BucketSort(arr);
        Console.WriteLine("Arreglo ordenado: " + string.Join(", ", arr));
    }
}
