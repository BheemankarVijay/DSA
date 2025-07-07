#include<iostream>
#include<vector>
using namespace std;

// Using  Maths formula x =n(n+1)/2 is sum of  natural numbers then  sum of n numbers so x - sum of n numbers will give the missing number
// Time Complexity: O(n) and Space Complexity: O(1)


int MissingNum(vector<int>& num) {
     int n=num.size();
     int sum=0;
     for(int i=0;i<n;i++){
         sum+=num[i];
     }
     int x=((n)*(n+1))/2;
     return x-sum;
}

int main(){
    int n;
    cout<<"Enter the number of elements in the vector: ";
    cin>>n;
    cout<<"Enter the elements of the vector: ";
    vector<int> num(n);
    for(int i=1;i<n;i++){
        cin>>num[i];
    }
    int missing=MissingNum(num);
    cout<<"The missing number is: "<<missing<<endl;

    return 0;
}

/*
          OUTPUT:
Enter the number of elements in the vector: 5       
Enter the elements of the vector: 1 2 3 5
The missing number is: 4
*/
