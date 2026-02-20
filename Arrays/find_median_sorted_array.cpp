#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n = nums1.size(), m = nums2.size();
        vector<int> nums3;

        // Merge both arrays
        while (i < n && j < m) {
            if (nums1[i] <= nums2[j]) {
                nums3.push_back(nums1[i]);
                i++;
            } else {
                nums3.push_back(nums2[j]);
                j++;
            }
        }

        while (i < n) {
            nums3.push_back(nums1[i]);
            i++;
        }

        while (j < m) {
            nums3.push_back(nums2[j]);
            j++;
        }

        // Find median
        int mid = nums3.size() / 2;
        double med;

        if (nums3.size() % 2 == 0)
            med = (nums3[mid] + nums3[mid - 1]) / 2.0;
        else
            med = nums3[mid];

        return med;
    }
};

int main() {
    Solution obj;

    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};

    double result = obj.findMedianSortedArrays(nums1, nums2);

    cout << "Median: " << result << endl;

    return 0;
}