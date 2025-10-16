//Leetcode problem 54. Spiral Matrix
//Given an m x n matrix, return all elements of the matrix in spiral order.
//We need take care of the boundaries while traversing the matrix in spiral order.
#include<iostream>
#include<vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int top=0,bottom=r-1;
        int left=0,right=c-1;
        vector<int>ans;
        while(top<=bottom && left<=right){
            //Left to right
            for(int i=left;i<=right;i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            //top to bottom 
            for(int i=top;i<=bottom;i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            //right to left
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            //bottom to top
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return ans;
}
int main(){
    int row,col;
    cout<<"Enter the number of rows and columns of the matrix: ";
    cin>>row>>col;
    vector<vector<int>>matrix(row,vector<int>(col));
    cout<<"Enter the elements of the matrix:"<<endl;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            cin>>matrix[i][j];
        }
    }
    vector<int>result=spiralOrder(matrix);
    cout<<"Spiral Order of the Matrix is:"<<endl;
    for(int i=0;i<result.size();i++){
        cout<<result[i]<<" ";
    }
    return 0;
}
// Time Complexity: O(m*n)
/*
            OUTPUT:
Enter the number of rows and columns of the matrix: 3 3
Enter the elements of the matrix:
1 2 3
4 5 6
7 8 9
Spiral Order of the Matrix is:
1 2 3 6 9 8 7 4 5 
*/