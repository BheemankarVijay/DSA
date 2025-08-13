// LeetCode Problem: 162. Find Peak Element
// This program finds a peak element in an array where a peak is defined as an element that is greater than its neighbors.
// A peak element is an element that is greater than its neighbors.
#include <iostream>
#include <vector>
using namespace std;
int findPeakElement(vector<int> &arr) {
    int n = arr.size(); //Size of array.

    for (int i = 0; i < n; i++) {
        //Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i])
                && (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int peakIndex = findPeakElement(arr);
    if (peakIndex != -1) {
        cout << "A peak element is at index: " << peakIndex << ", value: " << arr[peakIndex] << endl;
    } else {
        cout << "No peak element found." << endl;
    }

    return 0;
}
// Time Complexity: O(n) since we are iterating through the array once.
// Space Complexity: O(1) since we are using a constant amount of space.
/*
            OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 1 2 3 1 0
A peak element is at index: 2, value: 3
*/