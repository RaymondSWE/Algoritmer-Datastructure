#include <chrono>
#include <iostream>
void insertionSort(int *array, int size) {
  for (int step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;

    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

int main() {
  int data[]  {9, 5, 1, 4, 3, 15, 24, 33, 45, 76, 99, 230, 225, 312};
  int size{std::size(data)};
      auto start = std::chrono::high_resolution_clock::now();    
      insertionSort(data, size);
           auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(stop - start);
    std::cout << duration.count() << " nanoseconds" << '\n';

 for(int i{0}; i<std::size(data); ++i)
 std::cout << data[i] << '\n';

  return 0;
}