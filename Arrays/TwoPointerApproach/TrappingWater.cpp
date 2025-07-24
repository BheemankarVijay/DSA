// Trapping Water Problem using Two Pointer Approach
// LeetCode Problem: #42. Trapping Rain Water
#include <vector>
#include <iostream> 
#include <algorithm>
using namespace std;
int trap(vector<int>& ht) {
        int ans=0,l=0,r=ht.size()-1;
        int rmax=0,lmax=0;
        while(l<r){
            lmax=max(lmax,ht[l]);
            rmax=max(rmax,ht[r]);
            if(lmax < rmax){
                ans += lmax - ht[l];
                l++;
            }else{
                ans += rmax - ht[r];
                r--;
            }
        }return ans;
    }
int main() {
    int n;  
    cout << "Enter size of array: ";
    cin >> n;
    vector<int> ht(n);
    cout << "Enter " << n << " elements of the height array: ";
    for (int i = 0; i < n; i++) {
        cin >> ht[i];
    }
    int result = trap(ht);
    cout << "Total water trapped: " << result << endl;
    return 0;
}
// Time Complexity: O(n) where n is the size of the height array.
// Space Complexity: O(1) if we ignore the input array storage.
/*
                  OUTPUT:
Enter size of array: 5
Enter 5 elements of the height array: 4 2 0 3 5
Total water trapped: 7
*/