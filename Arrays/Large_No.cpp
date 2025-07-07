#include <iostream>
using namespace std;

int findLargest(int arr[], int n) {
    int largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }
    return largest;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int largest = findLargest(arr, n);
    cout << "The largest element in the array is: " << largest << endl;

    return 0;
}
// Time Complexity: O(n)

/*
               OUTPUT:
Enter the number of elements in the array: 5
Enter the elements of the array:
1 2 3 1 2
The largest element in the array is: 3
      
*/