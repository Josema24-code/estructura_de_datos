function hashSort(arr, maxVal) {
  const hashTable = new Array(maxVal + 1).fill(false);

  arr.forEach(num => hashTable[num] = true);

  const sorted = [];
  for (let i = 0; i <= maxVal; i++)
    if (hashTable[i]) sorted.push(i);

  return sorted;
}

let arr = [5, 2, 8, 3, 1];
console.log(hashSort(arr, 10));
