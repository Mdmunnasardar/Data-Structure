#include <iostream>
using namespace std;

int binarySearch(int arr[], int size, int target) {
    int first = 0, last = size - 1;
    
    while (first <= last) {
        int mid = first + (last - first) / 2; // Avoids overflow

        if (arr[mid] == target)
            return mid; // Found the target, return index
        else if (arr[mid] < target)
            first = mid + 1; // Search in right half
        else
            last = mid - 1; // Search in left half
    }
    
    return -1; // Target not found
}

int main() {
    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    int result = binarySearch(arr, size, target);
    
    if (result != -1)
        cout << "Element found at index " << result << endl;
    else
        cout << "Element not found" << endl;

    return 0;
}
