//Leetcode problem 74. Search a 2D Matrix using Binary Search
#include<iostream>
#include<vector>
using namespace std;
// Binary search inside a particular row
bool SearchRow(vector<vector<int>>& mat, int target, int row) {
        int n = mat[row].size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mat[row][mid] == target) {
                return true;
            } else if (target > mat[row][mid]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
}

bool searchMatrix(vector<vector<int>>& mat, int target) {
        int row = mat.size();
        int col = mat[0].size();

        int low = 0, high = row - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (target >= mat[mid][0] && target <= mat[mid][col - 1]) {
                // target must be in this row
                return SearchRow(mat, target, mid);
            } else if (target > mat[mid][col - 1]) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return false;
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
    int target;
    cout<<"Enter the target element to search: ";
    cin>>target;
    bool found=searchMatrix(matrix,target);
    if(found){
        cout<<"Element "<<target<<" is found in the matrix."<<endl;
    }else{
        cout<<"Element "<<target<<" is not found in the matrix."<<endl;
    }
    return 0;
}
// Time Complexity: O(log(m) + log(n))
// Space Complexity: O(1)
/*
   OUTPUT:
Enter number of rows and columns: 3 4
Enter the elements of the matrix row-wise:
1 3 5 7
10 11 16 20
23 30 34 60
Enter the target element to search: 3
Element 3 is found in the matrix.
*/