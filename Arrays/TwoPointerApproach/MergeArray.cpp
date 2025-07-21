#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void merge(vector<int>& a, int n, vector<int>& b, int m) {
    int id = n + m - 1;
    int i = n - 1;
    int j = m - 1;

    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (a[i] >= b[j]) {
            a[id--] = a[i--];
        } else {
            a[id--] = b[j--];
        }
    }

    // Copy remaining b[] if any
    while (j >= 0) {
        a[id--] = b[j--];
    }
}

int main() {
    int n, m;
    cout << "Enter size of first array: ";
    cin >> n;
    cout << "Enter size of second array: ";
    cin >> m;

    vector<int> a(n + m);
    cout << "Enter " << n << " elements of first sorted array: ";
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<int> b(m);
    cout << "Enter " << m << " elements of second sorted array: ";
    for (int i = 0; i < m; i++) cin >> b[i];

    merge(a, n, b, m);

    cout << "Merged array: ";
    for (int i = 0; i < n + m; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time Complexity: O(n + m) where n and m are the sizes of the two arrays.
// Space Complexity: O(1) if we ignore the input arrays storage.
/*
              OUTPUT:   
Enter size of first array: 5
Enter size of second array: 4
Enter 5 elements of first sorted array: 2 4 5 7 9
Enter 4 elements of second sorted array: 1 3 6 8
Merged array: 1 2 3 4 5 6 7 8 9
*/