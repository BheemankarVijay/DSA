//Leetcode problem 59. Spiral Matrix II
//Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>>ans(n,vector<int>(n,0));
        int left=0,right=n-1;
        int top=0,bottom=n-1;
        int num=1;
        while(left<=right && top<=bottom){
            //left to right
            for(int i=left;i<=right;i++){
                ans[top][i]=num++;
            }
top++;
//top to bottom
for(int i=top;i<=bottom;i++){
    ans[i][right]=num++;
}
right--;
            //left to right
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    ans[bottom][i]=num++;
                }
                bottom--;
            }
            //bottom to top
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    ans[i][left]=num++;
                }
                left++;
            }
        }
        return ans;
}
int main(){
    int n;
    cout<<"Enter the size of the matrix: ";
    cin>>n;
    vector<vector<int>>result=generateMatrix(n);
    cout<<"The generated Spiral Matrix is:"<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// Time Complexity: O(n*n)
// Space Complexity: O(1)
//where n is the size of the matrix
// Space Complexity: O(1)
//where n is the size of the matrix
/*
   OUTPUT:
Enter the size of the matrix: 3
The generated Spiral Matrix is:
1 2 3 
8 9 4 
7 6 5 
*/