#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = 0, freq = 0;

        // Count frequency of each element
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
            maxi = max(maxi, mp[nums[i]]);
        }

        // Count total elements having maximum frequency
        for (auto i : mp) {
            if (i.second == maxi)
                freq += maxi;
        }

        return freq;
    }
};

int main() {
    Solution obj;
    
    vector<int> nums = {1, 2, 2, 3, 1, 4};  // Example input
    
    int result = obj.maxFrequencyElements(nums);
    
    cout << "Total frequency of elements with maximum frequency: " << result << endl;

    return 0;
}
