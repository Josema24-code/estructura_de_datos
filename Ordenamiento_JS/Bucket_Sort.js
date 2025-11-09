function bucketSort(arr) {
  const n = arr.length;
  const buckets = Array.from({ length: n }, () => []);

  // Colocar en cubetas
  for (let num of arr) {
    const index = Math.floor(n * num);
    buckets[index].push(num);
  }

  // Ordenar cada cubeta
  for (let b of buckets) {
    b.sort((a, b) => a - b);
  }

  // Unir todas
  return [].concat(...buckets);
}

const arr = [0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.23, 0.68];
console.log("Arreglo ordenado:", bucketSort(arr));
