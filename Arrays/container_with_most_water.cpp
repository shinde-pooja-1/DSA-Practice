#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi = 0;
        int s = 0, e = height.size() - 1;

        while (s < e) {
            int mini = min(height[s], height[e]);
            int area = (e - s) * mini;
            maxi = max(area, maxi);

            if (height[s] < height[e])
                s++;
            else
                e--;
        }
        return maxi;
    }
};

int main() {
    Solution obj;

    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int result = obj.maxArea(height);

    cout << "Maximum Area: " << result << endl;

    return 0;
}