#include <iostream>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int n = 5;
    int pos = 2;
for(int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
cout << "Array after deletion: ";
    for(int i = 0; i < n; i++) cout << arr[i] << " ";
    return 0;
}
