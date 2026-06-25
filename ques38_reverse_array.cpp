#include <iostream>
int main() {
    int arr[] = {34, 15, 88, 2, 7, 61};
    int size = sizeof(arr) / sizeof(arr[0]);
  int smallest = arr[0];
  int largest = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < smallest) smallest = arr[i];
        if (arr[i] > largest) largest = arr[i];
    }
    std::cout << "Smallest element: " << smallest << "\n";
    std::cout << "Largest element: " << largest << "\n";
    return 0;
}
