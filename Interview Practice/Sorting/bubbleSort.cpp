/*

Given an array of integers, sort it.

Example

For items = [2, 4, 1, 5], the output should be
bubbleSort(items) = [1, 2, 4, 5].

Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.integer items

Guaranteed constraints:
1 = items.length = 15,
-100 = items[i] = 100.

[output] array.integer

*/

std::vector<int> bubbleSort(std::vector<int> items) {

  int len =  items.size() ;

  for (int i = 0; i < len; i++) {
    for (int j = 0, stop = len - i; j < stop - 1; j++) {
      if (items[j] > items[j + 1]) {
        std::swap(items[j], items[j + 1]);
      }
    }
  }

  return items;
}

