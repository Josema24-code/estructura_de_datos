def hash_sort(arr, max_val):
    hash_table = [0] * (max_val + 1)

    for num in arr:
        hash_table[num] = 1

    sorted_arr = [i for i in range(len(hash_table)) if hash_table[i] == 1]
    return sorted_arr

arr = [5, 2, 8, 3, 1]
print(hash_sort(arr, 10))
