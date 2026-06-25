#include <iostream>
int main() {
  int arr[] = {10, 20, 30, 40, 50};
  int size = sizeof(arr) / sizeof(arr[0]);
  int sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
    }
    double average = static_cast<double>(sum) / size;
    std::cout << "Sum: " << sum << "\n";
    std::cout << "Average: " << average << "\n";
    return 0;
}
