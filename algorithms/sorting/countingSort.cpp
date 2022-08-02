#include <iostream>
using namespace std;

void printArray(int arr[], int size) {
  for (int i = 0; i < size; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main(void) {
  int size;
  cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    cin >> arr[i];
  }

  cout << "Before Sort: " << endl;
  printArray(arr, size);

  // counting sort
  // step 1: finding max
  int max = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  // step 2: initialization of count array
  int count[max + 1];
  for (int i = 0; i <= max; i++) {
    count[i] = 0;
  }

  // step 3: frequency calculation
  for (int i = 0; i < size; i++) {
    count[arr[i]]++;
  }

  // step 4: cumulative sum or prefix sum
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  // step 5: final array --> backward traversal of basic array
  int final[size];

  for (int i = size - 1; i >= 0; i--) {
    count[arr[i]]--;
    int k = count[arr[i]];
    final[k] = arr[i];
  }

  cout << "Before Sort: " << endl;
  printArray(final, size);

  return 0;
}
