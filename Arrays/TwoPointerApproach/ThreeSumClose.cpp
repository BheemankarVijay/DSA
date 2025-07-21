/*
 LeetCode Problem: 16. 3Sum Closest
 This code finds the sum of three integers in an array that is closest to a given target.
 it similar to the 3Sum problem but instead of finding triplets that sum to zero,
 we find triplets that sum closest to a target value.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stdexcept>
using namespace std;

pair<int, vector<int>> threeSumClosest(vector<int>& num, int target) {
    int n = num.size();
    if (n < 3) {
        throw invalid_argument("Need at least 3 numbers to compute 3-sum closest");
    }

    sort(num.begin(), num.end());
    int closest = num[0] + num[1] + num[2];
    vector<int> triplet = {num[0], num[1], num[2]};

    for (int i = 0; i < n - 2; i++) {
        int j = i + 1, k = n - 1;
        while (j < k) {
            int sum = num[i] + num[j] + num[k];

            if (sum == target) {
                return {sum, {num[i], num[j], num[k]}}; // exact match
            }

            if (abs(sum - target) < abs(closest - target)) {
                closest = sum;
                triplet = {num[i], num[j], num[k]};
            }

            if (sum < target) j++;
            else k--;
        }
    }
    return {closest, triplet};
}

int main() {
    int n, target;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> num(n);
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) cin >> num[i];

    cout << "Enter target sum: ";
    cin >> target;

    try {
        auto result = threeSumClosest(num, target);
        cout << "Closest sum to target is: " << result.first << endl;
        cout << "Triplet with closest sum: ";
        for (int x : result.second) cout << x << " ";
        cout << endl;
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}

/*  
                OUTPUT:
Enter number of elements: 4
Enter 4 integers: -1 -4 1 2
Enter target sum: 1
Closest sum to target is: 2
Triplet with closest sum: -1 1 2
*/      