//LeetCode Problem #31: Next Permutation
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
void nextPermutation(vector<int>& num) {
        int pivot=-1;
        int n = num.size();
        for(int i=n-2;i>=0;i--){
            if(num[i] < num[i+1]){
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            return sort(num.begin(),num.end()); 
        }
        for(int i=n-1;i>=pivot;i--){
            if(num[i]>num[pivot]){ 
              swap(num[i],num[pivot]);
              break;
            }
        }
        sort(num.begin()+pivot+1,num.end());
        
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
    
    nextPermutation(num);
    
    cout << "Next permutation: ";
    for (int i = 0; i < n; i++) {
        cout << num[i] << " ";
    }
    cout << endl;
    
    return 0;
}
// Time Complexity: O(n) where n is the size of the array.
// Space Complexity: O(1) if we ignore the input array storage.
/*
                  OUTPUT:
Enter size of array: 5
Enter 5 elements of the array: 1 2 3 6 5
Next permutation: 1 2 5 3 6
*/