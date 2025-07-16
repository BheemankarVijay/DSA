/*
Leetcode Problem(#283): Move Zeroes 
step1: take two pointers i and j
step2: i points to the next position of non-zero element
step3: j iterates through the array 
step4: if arr[j] is non-zero, swap arr[i] and arr[j] and increment i
step5: continue until j reaches the end of the array
*/


#include <iostream>
#include <vector>
using namespace std;

void moveZerosToFront(vector<int>& arr) {
    int i = 0;
    for (int j = 0; j < arr.size(); j++) {
        if (arr[j] != 0) {   //(arr[j] == 0) for moving zeros to the front
            // Swap non-zero element with the zero at index i
            swap(arr[i], arr[j]);
            i++;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> arr(n);

    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    moveZerosToFront(arr);

    cout << "Array after moving zeros to the front: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
/*
             OUTPUT:
Enter number of elements: 5
Enter array elements: 1 0 0 1 0
Array after moving zeros to the front: 1 1 0 0 0
*/