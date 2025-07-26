// LeetCode Problem: 611. Valid Triangle Number
// This problem can be solved using a two-pointer approach to count the number of valid triangles that can be formed with the given side lengths.
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int triangleNumber(vector<int>& num) {
        int n= num.size();
        int count=0;
        sort(num.begin(),num.end());
        for(int i=n-1;i>=2;i--){   // loop star from the end to check the largest side
            int l=0, r =i-1;
            while(l < r){
                if(num[l]+num[r]>num[i]){  // If the sum of the two smaller sides is greater than the largest side
                    // All pairs (l, l+1, ..., r) with the current r can
                    count+=(r-l);  // Count all valid pairs
                    r--;
                }else{
                    l++;
                }
                
            }
        } return count;
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

    int result = triangleNumber(num);
    cout << "Number of valid triangles: " << result << endl;

    return 0;
}
// Time Complexity: O(n^2) where n is the size of the array.
// Space Complexity: O(1) if we ignore the input array storage.
/*
                  OUTPUT:
Enter size of array: 4
Enter 4 elements of the array: 2 2 3 4
Number of valid triangles: 3
*/