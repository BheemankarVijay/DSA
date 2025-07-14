#include <iostream>
#include <vector>
using namespace std;

vector<int> InsertionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 1; i < n - 1; i++) {
        int j = i-1;

        int key = arr[i];
        // Move elements of arr[0..i-1], that are greater than key,
        while(j>0 && arr[j]> arr[key]){ // Desecnding order
            arr[j+1]=arr[j];
            j--;
            
        }
        swap(arr[j+1],arr[i]) ;
    }
    return arr;
}

int main(){
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    InsertionSort(arr);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
       OUTPUT:
Enter number of elements in the array: 5
Enter the elements of the array: 5 3 2 1 4
Sorted array: 5 3 3 1 4 
*/