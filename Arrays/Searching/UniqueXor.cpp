// LeetCode Problem 501: Single Number
// This program finds the element that appears only once in an array where every other element appears exactly twice.
#include <iostream>
#include <vector>
using namespace std;
int singleNonDuplicate(vector<int>& num) {
        int n = num.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans ^=num[i];
        }
        return ans;
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

    int result = singleNonDuplicate(num);
    cout << "The element that appears only once is: " << result << endl;

    return 0;
}
// Time complexity is O(n) since we traverse the array once. Space complexity is O(1) since we use a constant amount of extra space.
/*
                OUTPUT:
Enter size of array: 5  
Enter 5 elements of the array: 4 1 2 1 2
The element that appears only once is: 4
*/