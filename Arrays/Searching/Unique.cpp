// Leetcode Problem: 540. Single Element in a Sorted Array
// This program finds the single element in a sorted array where every other element appears exactly twice.
#include <iostream>
#include <vector>
using namespace std;
int singleNonDuplicate(vector<int>& num) {
        int n = num.size();
        if(n == 1) return num[0];
        if(num[0] != num[1]) return num[0];
        if(num[n-1] != num[n-2]) return num[n-1];
        int low = 0,high=n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(num[mid]!=num[mid-1] && num[mid]!=num[mid+1]){
                return num[mid];
            }
            else if(mid%2 == 0 && num[mid] ==num[mid+1] || mid%2 == 1 && num[mid] == num[mid-1]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }return -1;
}
int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements of the sorted array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int result = singleNonDuplicate(nums);
    cout << "The single element in the sorted array is: " << result << endl;

    return 0;
}
// Time Complexity: O(log n) due to binary search.
// Space Complexity: O(1) since we are using a constant amount of space.
/*
         OUTPUT:        
Enter size of array: 7
Enter 7 elements of the sorted array: 1 1 2 3 3 4 4
The single element in the sorted array is: 2
*/