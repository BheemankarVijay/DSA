//Leetcode problem 867. Transpose Matrix
//Given a 2D integer array matrix, return the transpose of matrix.
#include<iostream>
#include<vector>    
using namespace std;
vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();
        vector<vector<int>>T(col,vector<int>(row));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                T[j][i]=matrix[i][j];
            }
        }
        return T;
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
    vector<vector<int>>result=transpose(matrix);
    cout<<"Transposed Matrix is:"<<endl;
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// Time Complexity: O(m*n)
/*
            OUTPUT:
Enter the number of rows and columns of the matrix: 2 3
Enter the elements of the matrix:               
1 2 3
4 5 6
Transposed Matrix is:
1 4 
2 5
3 6 
*/  