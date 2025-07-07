#include<iostream>
#include<vector>
#include<limits.h> // For INT_MIN
using namespace std;

int getSecondLargest(vector<int> &arr) {
    int largest = arr[0];
    int second = INT_MIN;
    for(int i = 1; i < arr.size(); i++) {
        if(arr[i] > largest) {
            second = largest;
            largest = arr[i];
        } else if(arr[i] < largest && arr[i] > second) {
            second = arr[i];
        }
    }
    return second;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = getSecondLargest(arr); // ✅ Declare result first

    if (result == INT_MIN)
        cout << "No second largest element found." << endl;
    else
        cout << "Second Largest: " << result << endl;

    return 0;
}
// Time Complexity: O(n)
/*
               OUTPUT:      
Enter the number of elements in the array: 5
Enter the elements of the array:1 2 1 2 3
Second Largest: 2
*/  