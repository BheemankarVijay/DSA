#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int LowerBound(vector<int>&arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int main() {
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements in sorted order: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value to find lower bound: ";
    cin >> x;

    int index = LowerBound(arr, n, x);
    if (index < n) {
        cout << "Lower bound of " << x << " is at index: " << index << ", value: " << arr[index] << endl;
    } else {
        cout << "No lower bound found for " << x << endl;
    }

    return 0;
}
// Time Complexity: O(log n) where n is the number of elements in the array.
// Space Complexity: O(1) since we are using a constant amount of space.
/*
            OUTPUT:
Enter number of elements: 5         
Enter the elements in sorted order: 1 2 2 2 3
Enter the value to find lower bound: 2
Lower bound of 2 is at index: 1, value: 2
*/
