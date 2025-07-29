// LeetCode Problem: 1480. Running Sum of 1d Array
// This problem can be solved by iterating through the array and maintaining a running sum.
#include<iostream>
#include<vector>
using namespace std;
vector<int> runningSum(vector<int>& num) {
        int n = num.size();
        for(int i=1;i<n;i++){
            num[i] = num[i] + num[i-1];
        } return num;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> num(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    vector<int> result = runningSum(num);
    cout << "Running sum of the array: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) since we are modifying the input array in place.
/*
                    OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 1 2 3 4 5
Running sum of the array: 1 3 6 10 15 
*/  