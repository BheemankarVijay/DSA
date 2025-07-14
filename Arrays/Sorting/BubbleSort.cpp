#include <iostream>
#include <vector>  // Needed for vector
using namespace std;

// Bubble Sort Function
vector<int> BubbleSort(vector<int>& arr) {
    int n = arr.size();
    bool swapped = false;  
    for (int i = 0; i < n; i++) {
        swapped = false;  // Reset for each outer loop
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break; 
    }
    return arr;
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);  // Corrected spelling: vector not vetor
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    BubbleSort(arr);

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
Enter the elements of the array: 1 4 2 3 5
Sorted array: 1 2 3 4 5 
*/