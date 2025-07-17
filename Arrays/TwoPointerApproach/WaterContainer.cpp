/*
LeetCode Problem(#11): Container With Most Water
This code finds the maximum area of water that can be contained between two lines.
Need find highest Area = width * height
where width is the distance between the two lines and height is the shorter of the two lines.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxArea(vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int maxWater = 0;

    while (left < right) {
        int h = min(height[left], height[right]);
        int w = right - left;
        maxWater = max(maxWater, h * w);

        // Move pointer with smaller height
        if (height[left] < height[right]) left++;
        else right--;
    }
    return maxWater;
}

int main() {
    int n;
    cout << "Enter number of heights: ";
    cin >> n;

    vector<int> height(n);
    cout << "Enter heights: ";
    for (int i = 0; i < n; i++) cin >> height[i];

    int result = maxArea(height);
    cout << "Maximum water that can be stored: " << result << endl;

    return 0;
}
/*
      OUTPUT:
Enter number of heights: 5
Enter heights: 7 2 4 6 3
Maximum water that can be stored: 18
*/