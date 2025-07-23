// leetcode problem: #713. Subarray Product Less Than K and its solution using Two Pointer Approach
// This code counts the number of contiguous subarrays where the product of all elements is less than k.
#include <iostream>
#include <vector>   
#include <algorithm>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,count=0,pro=1;
        for(int r=0;r<nums.size();r++){
                if(k<=1) return 0;
                pro *= nums[r];
                while(pro >= k){
                    pro /= nums[l];
                    l++;
                }
                count += r-l+1;
            
        }return count;
    }
int main() {
    int n, k;
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter " << n << " elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter value of k: ";
    cin >> k;
    int result = numSubarrayProductLessThanK(nums, k);
    cout << "Number of contiguous subarrays with product less than " << k << ": " << result << endl;
    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) if we ignore the input array storage.
/*
              OUTPUT:   
Enter size of array: 4       
Enter 4 elements of the array: 10 5 2 6
Enter value of k: 100
Number of contiguous subarrays with product less than 100: 8
*/