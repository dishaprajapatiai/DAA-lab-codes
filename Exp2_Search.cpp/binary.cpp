#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int start = 0;
    int end = size - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;  // Target found, return its index
        } else if (target < arr[mid]) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return -1;  // Target not found
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int target = 5;
    int size = sizeof(arr) / sizeof(arr[0]);

    int result = binarySearch(arr, size, target);
    if (result == -1) {
        cout << "Element not found in the array." << endl;
    } else {
        cout << "Element found at index: " << result << endl;
    }

    return 0;
}
