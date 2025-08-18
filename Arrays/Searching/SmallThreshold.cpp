// LeetCode Problem: 1283. Find the Smallest Divisor Given a Threshold
// This code finds the smallest divisor such that the sum of the division results is less than or equal to a given threshold.
#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool condition(vector<int>nums,int threshold,int divisor){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum += (nums[i]+divisor-1)/divisor;
            if(sum > threshold) return false;
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = *max_element(nums.begin(),nums.end());
        while(low<high){
            int mid = low + (high-low)/2;
            if(condition(nums,threshold,mid)){
                high = mid;
            }else{
                low = mid+1;
            }
        }return low;
} 
int main() {
    int n, threshold;
    cout << "Enter number of elements: ";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    cout << "Enter the threshold: ";
    cin >> threshold;

    int result = smallestDivisor(nums, threshold);
    cout << "The smallest divisor is: " << result << endl;

    return 0;
}
// Time Complexity: O(n log(max(nums)))
// Space Complexity: O(1) since we are using a constant amount of extra space.
// This code finds the smallest divisor such that the sum of the division results is less than or equal to a given threshold.
/*
            Output:
Enter number of elements: 4
Enter the elements: 1 2 5 9
Enter the threshold: 6
The smallest divisor is: 5
*/