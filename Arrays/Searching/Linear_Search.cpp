#include <iostream>
using namespace std;

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target)
            return i;  // return index
    }
    return -1; // not found
}

int main() {
    int n, target;
    cout << "Enter array size: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Enter target element to search: ";
    cin >> target;

    int index = linearSearch(arr, n, target);

    if (index != -1)
        cout << target << " found at index " << index << "." << endl;
    else
        cout << target << " is NOT found in the array." << endl;

    return 0;
}
// Time Complexity: O(n) - We traverse the array once.
/*
      OUTPUT:
Enter array size: 5 
Enter array elements: 1 2 3 4 5
Enter target element to search: 3   
3 found at index 2.
*/