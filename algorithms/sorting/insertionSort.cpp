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

  // insertion sort
  for (int i =0; i< size; i++) {
    int key = arr[i];
    int j = i-1;
    while (arr[j] > key && j>=0) {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }

  cout << "After Sort: " << endl;
  printArray(arr, size);
  return 0;
}
