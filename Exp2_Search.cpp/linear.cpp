#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i;  // Target found, return index
        }
    }
    return -1;  // Target not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int target = 5;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = linearSearch(arr, size, target);
    if (result == -1) {
        cout << "Element not found in the array." << endl;
    } else {
        cout << "Element found at index: " << result << endl;
    }

    return 0;
}

