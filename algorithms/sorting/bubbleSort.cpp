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

  // Bubble sort implimentation with extra looping optimization
  for (int i = 0; i < size; i++) {
    int flag = 0;
    for (int j = 0; j < size - i; j++) {
      if (arr[j] > arr[j + 1]) {
        int temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
        flag = 1;
      }
    }
    if (flag == 0) {
      break;
    }
  }

  cout << "After Sort: " << endl;
  printArray(arr, size);
  return 0;
}
