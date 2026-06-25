#include <stdio.h>
int main() {
  int rows = 5;
  for (int i = 0; i < rows; i++) {
    for (int space = 1; space <= rows - i; space++) {
      std::cout << " ";
        }
    int val = 1;
    for (int j = 0; j <= i; j++) {
      std::cout << val << " ";
      val = val * (i - j) / (j + 1);
        }
        std::cout << "\n";
    }
    return 0;
}
