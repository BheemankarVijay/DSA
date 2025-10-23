#include<iostream>
#include<vector>
using namespace std;
// Leetcode problem 240. Search a 2D Matrix II using Staircase Search
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int low=0,high=col-1;
        while(low<row && high>=0){
            if(target == matrix[low][high]){
                return true;
            }else if(target> matrix[low][high]){
                low++;
            }else{
                high--;
            }
        }return false;
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
// Time Complexity: O(m + n), where m is the number of rows and n is the number of columns in the matrix.
// Space Complexity: O(1)

/*
            OUTPUT:
Enter number of rows and columns: 3 4
Enter the elements of the matrix row-wise:
1 3 5 7
10 11 16 20
23 30 34 50
Enter the target element to search: 3
Element 3 is found in the matrix.
*/