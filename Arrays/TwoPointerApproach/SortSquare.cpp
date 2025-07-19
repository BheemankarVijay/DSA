/*
LeetCode Problem: 977. Squares of a Sorted Array
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
This is a two-pointer approach to solve the problem efficiently.

Logic: We use two pointers, one starting at the beginning (left) and one at the end (right) of the array.
We compare the absolute values of the elements at these pointers and square them, placing the larger square
which left or right pointer then push into new array at the end.
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int> sortedSquares(vector<int>& num) {
        int n=num.size();
        vector<int>ans(n);
        int i=n-1;
        int left=0,right=n-1;
        while(left<=right){
            int low=abs(num[left]);
            int high=abs(num[right]);
            if(low< high){
                ans[i]=high * high;
                right--;
            }else{
                ans[i]=low*low;
                left++;
            }
            i--;
    }return ans;
}
int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> num(n);
    cout << "Enter " << n << " elements (sorted in non-decreasing order): ";
    for (int i = 0; i < n; i++) cin >> num[i];

    vector<int> result = sortedSquares(num);

    cout << "Sorted squares output: ";
    for (int val : result) cout << val << " ";
    cout << endl;

    return 0;
}

/*
              OUTPUT:  
Enter number of elements: 5
Enter 5 elements (sorted in non-decreasing order): -4 -3 0 1 9
Sorted squares output: 0 1 9 16 81 
*/