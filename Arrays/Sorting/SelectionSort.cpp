#include <iostream>
#include <vector>
using namespace std;

vector<int> SelectionSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {  // 🛠️ use '<' for ascending sort
                minIndex = j;
            }
        }

        // Swap only if a new minimum is found
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }

    return arr;
}

int main() {
    int n;
    cout << "Enter number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    SelectionSort(arr);

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
Enter the elements of the array: 5 3 4 1 2  
*/