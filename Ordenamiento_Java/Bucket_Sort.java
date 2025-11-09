import java.util.*;

public class Bucket_Sort {
    public static void bucketSort(float[] arr) {
        int n = arr.length;
        ArrayList<Float>[] buckets = new ArrayList[n];

        for (int i = 0; i < n; i++)
            buckets[i] = new ArrayList<>();

        for (float num : arr) {
            int index = (int)(n * num);
            buckets[index].add(num);
        }

        for (ArrayList<Float> bucket : buckets)
            Collections.sort(bucket);

        int k = 0;
        for (ArrayList<Float> bucket : buckets)
            for (float num : bucket)
                arr[k++] = num;
    }

    public static void main(String[] args) {
        float[] arr = {0.78f, 0.17f, 0.39f, 0.26f, 0.72f, 0.94f, 0.21f, 0.12f, 0.23f, 0.68f};
        bucketSort(arr);
        System.out.println("Arreglo ordenado: " + Arrays.toString(arr));
    }
}
