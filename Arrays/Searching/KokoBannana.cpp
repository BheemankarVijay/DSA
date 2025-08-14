// LeetCode problem: 875. Koko Eating Bananas
// This program finds the minimum eating speed Koko needs to finish all bananas in h hours.
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            long long hours = 0;
            for (int p : piles) {
                hours += (p + mid - 1) / mid; // ceil division we add mid - 1 to ensure we round up
            }

            if (hours <= h) {
                ans = mid;  // possible answer, try  find smaller value
                // to minimize the speed
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
}
int main() {
    int n, h;
    cout << "Enter number of piles: ";
    cin >> n;
    vector<int> piles(n);
    cout << "Enter the piles of bananas: ";
    for (int i = 0; i < n; i++) {
        cin >> piles[i];
    }
    cout << "Enter the number of hours: ";
    cin >> h;

    int minSpeed = minEatingSpeed(piles, h);
    cout << "Minimum eating speed Koko needs: " << minSpeed << endl;

    return 0;
}
// Time Complexity: O(n log m) where n is the number of piles and m is the maximum number of bananas in a pile.
// Space Complexity: O(1) since we are using a constant amount of space.
/*
            OUTPUT:
Enter number of piles: 4
Enter the piles of bananas: 3 6 7 11
Enter the number of hours: 8
Minimum eating speed Koko needs: 4
*/