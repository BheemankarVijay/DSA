#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;  
// Leetcode problem 1439. Find the Kth Smallest Sum of a Matrix With Sorted Rows  
int kthSmallest(vector<vector<int>>& mat, int k) {
        vector<int> flat;
    for (auto &row : mat)
        flat.insert(flat.end(), row.begin(), row.end());

    sort(flat.begin(), flat.end());
        return flat[k-1];
}
int main(){
    int m,n;
    cout<<"Enter number of rows and columns: ";
    cin>>m>>n;
    vector<vector<int>>matrix(m,vector<int>(n,0));
    cout<<"Enter the elements of the matrix row-wise: "<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;
    int result=kthSmallest(matrix,k);
    cout<<"The "<<k<<"th smallest element in the matrix is: "<<result<<endl;
    return 0;
}
// Time Complexity: O(m*n log(m*n)), where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(m*n)
/*
            OUTPUT: 
Enter number of rows and columns: 3 3
Enter the elements of the matrix row-wise: 
1 2 3
4 5 6
8 5 6
Enter the value of k: 8
The 8th smallest element in the matrix is: 6
*/