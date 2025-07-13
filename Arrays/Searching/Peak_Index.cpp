/*
LeetCode#162 :- find the peak index in an array using binary search.
step 1: if  mid element next is greater  then assign right is mid ( avoid mid + 1)
step 2: else assign left is mid + 1
step 3 : out of while loop return left;
*/
#include <iostream>
#include <vector>
using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] > nums[mid + 1]) {
            // Peak is in the left half (including mid)
            right = mid;
        } else {
            // Peak is in the right half
            left = mid + 1;
        }
    }

    // left == right is the peak index
    return left;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> nums(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int peakIndex = findPeakElement(nums);
    cout << "Peak element is at index: " << peakIndex << " and value: " << nums[peakIndex] << endl;

    return 0;
}
/*
                OUTPUT:
Enter number of elements: 5
Enter 5 elements: 1 3 2 1 0     
Peak element is at index: 1 and value: 3
*/