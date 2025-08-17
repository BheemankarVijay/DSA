// LeetCode 1482 - Minimum Number of Days to Make m Bouquets
// We will use binary search to find the minimum day required to make m bouquets of k flowers each.
// The function `possible` checks if it is possible to make m bouquets by a given day.
// Time Complexity: O(n log(max(bloomDay))) where n is the number of flowers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool possible(vector<int>& bloomDay, int m, int k, int day) {
    int count = 0, bouquet = 0;
    for (int i = 0; i < bloomDay.size(); i++) {
        if (bloomDay[i] <= day) {
            count++;
            if (count == k) {
                bouquet++;
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    return bouquet >= m;
}

int minDaysBruteForce(vector<int>& bloomDay, int m, int k) {
    int n = bloomDay.size();
    if ((long long)m * k > n) return -1;

    int low = *min_element(bloomDay.begin(), bloomDay.end());
    int high = *max_element(bloomDay.begin(), bloomDay.end());

    for (int day = low; day <= high; day++) {
        if (possible(bloomDay, m, k, day)) {
            return day; // first valid day found
        }
    }
    return -1;
}

int main() {
    int n, m, k;
    cout << "Enter number of flowers: ";
    cin >> n;
    vector<int> bloomDay(n);
    cout << "Enter the bloom days of the flowers: ";
    for (int i = 0; i < n; i++) {
        cin >> bloomDay[i];
    }
    cout << "Enter number of bouquets (m) and flowers per bouquet (k): ";
    cin >> m >> k;

    int result = minDaysBruteForce(bloomDay, m, k);
    if (result != -1) {
        cout << "Minimum number of days (brute force) to make " << m << " bouquets is: " << result << endl;
    } else {
        cout << "Not possible to make " << m << " bouquets with given conditions." << endl;
    }

    return 0;
}

/*  
            OUTPUT:
Enter number of flowers: 7
Enter the bloom days of the flowers: 1 10 3 10 2 5 7
Enter number of bouquets (m) and flowers per bouquet (k): 3 2
Minimum number of days to make 3 bouquets is: 10
*/