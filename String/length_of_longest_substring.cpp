#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
// using sliding window
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> last(256, -1);   // ASCII characters

        int start = 0;
        int maxLen = 0;

        for (int end = 0; end < s.size(); end++) {

            if (last[s[end]] >= start) {
                start = last[s[end]] + 1;
            }

            last[s[end]] = end;

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};

int main() {
    Solution obj;
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int result = obj.lengthOfLongestSubstring(s);

    cout << "Length of longest substring without repeating characters: "
         << result << endl;

    return 0;
}
