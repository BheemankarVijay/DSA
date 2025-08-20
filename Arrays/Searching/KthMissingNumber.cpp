// LeetCode Problem : 1539. Kth Missing Positive Number
// This code finds the kth missing positive number in a sorted array of positive integers.
#include <vector>
#include <iostream>
using namespace std;
int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size()+k; // if not found size + k
        int low = 0,high = arr.size()-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]>(k+mid)){ //using square k+i
                n = k+mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return n;
}
int main() {
    int n, k;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the value of k: ";
    cin >> k;

    int result = findKthPositive(arr, k);
    cout << "The " << k << "th missing positive number is: " << result << endl;

    return 0;
}
// Time Complexity: O(log n) for binary search
// Space Complexity: O(1) since we are using a constant amount of extra space.
// This code finds the kth missing positive number in a sorted array of positive integers.
/*
            Output:     
Enter the number of elements in the array: 5
Enter the elements of the array: 2 3 4 7 11
Enter the value of k: 5
The 5th missing positive number is: 9
*/
