//LeetCode Problem 1572: Matrix Diagonal Sum
//Given a square matrix mat, return the sum of the matrix diagonals.
#include <iostream>
#include <vector>
using namespace std;
int diagonalSum(vector<vector<int>>& mat) {
        int row=mat.size();
        int col=mat[0].size();
        int sum=0;
        for(int i=0;i<row;i++){
            sum+=mat[i][i];
            sum+=mat[i][row-i-1];
        }
        if(row%2 == 1){
            sum-=mat[row/2][row/2];
        }
        return sum;
}
int main(){
    int n;
    cout<<"Enter the size of the square matrix: ";
    cin>>n;
    vector<vector<int>>matrix(n,vector<int>(n));
    cout<<"Enter the elements of the matrix:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>matrix[i][j];
        }
    }
    int result=diagonalSum(matrix);
    cout<<"Sum of diagonals: "<<result<<endl;
    return 0;
}
// Time Complexity: O(n)
/*
            OUTPUT:
Enter the size of the square matrix: 3
Enter the elements of the matrix:
1 2 3   
4 5 6
7 8 9
Sum of diagonals: 25
*/