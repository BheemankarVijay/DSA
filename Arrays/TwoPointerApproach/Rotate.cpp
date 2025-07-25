//LeetCode Problem #189: Rotate Array
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void rotate(vector<int>& num, int k) {
        int n=num.size();
        k%=n;
        reverse(num.begin(),num.end());  // Reverse the entire array
        reverse(num.begin(),num.begin()+k); // Reverse the first k elements  // This will place the last k elements at the front
        // Now the first k elements are in the correct position
        reverse(num.begin()+k,num.end());  // Reverse the remaining n-k elements
        
}
int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> num(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cout << "Enter the number of rotations: ";
    cin >> k;

    rotate(num, k);

    cout << "Array after rotation: ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) if we ignore the input array storage.
/*
                  OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 1 2 3 4 5
Enter the number of rotations: 2
Array after rotation: 4 5 1 2 3
*/