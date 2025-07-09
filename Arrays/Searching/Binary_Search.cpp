#include <iostream>
using namespace std;

// Binary Search function
int binarySearch(int arr[], int n, int target) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;  // To avoid overflow

        if (arr[mid] == target)
            return mid;  // target found
        else if (arr[mid] < target)
            low = mid + 1;  // search in right half
        else
            high = mid - 1; // search in left half
    }

    return -1;  // target not found
}

// Main function
int main() {
    int n, target;
    cout << "Enter the number of elements in the sorted array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the sorted array elements in ascending order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the target element to search: ";
    cin >> target;

    int index = binarySearch(arr, n, target);

    if (index != -1)
        cout << target << " found at index " << index << "." << endl;
    else
        cout << target << " not found in the array." << endl;

    return 0;
}
// Time Complexity: O(log n) - The array is halved in each iteration.
/*                  
                    Output:
Enter the number of elements in the sorted array: 5
Enter the sorted array elements in ascending order: 1 2 3 4 5
Enter the target element to search: 3
3 found at index 2.
*/