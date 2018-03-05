/*

Sort an array of integers.

Example

For sequence = [3, 6, 1, 5, 3, 6], the output should be
mergeSort(sequence) = [1, 3, 3, 5, 6, 6].

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer sequence

Guaranteed constraints:
1 = sequence.length = 100,
-100 = sequence[i] = 100.

*/
void mergeArrays(std::vector<int> &sequence, int left, int middle, int right) {
  std::vector<int> result;
  int i, j;

  for (i = left, j = middle; i < middle && j < right; ) {
    if (sequence[i] < sequence[j]) {
      result.push_back(sequence[i]);
      i++;
    }
    else {
      result.push_back(sequence[j]);
      j++;
    }
  }

  while (i < middle) {
    result.push_back(sequence[i]);
    i++;
  }

  while (j < right) {
    result.push_back(sequence[j]);
    j++;
  }

  for (i = left; i < right; i++) {
    sequence[i] = result[i - left];
  }
}

void split(std::vector<int> &sequence, int left, int right) {
  if(left==((left+right)/2)) return;
  int middle = (left + right) / 2;
  split(sequence, left, middle);
  split(sequence, middle, right);
  mergeArrays(sequence, left, middle, right);
}

std::vector<int> mergeSort(std::vector<int> sequence) {

  split(sequence, 0, sequence.size());

  return sequence;
}
