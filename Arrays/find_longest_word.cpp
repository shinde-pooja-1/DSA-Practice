#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {

        // Sort the dictionary by descending length.
       // If two strings have the same length, sort them in lexicographical (ascending) order (a -> z).

        sort(dictionary.begin(), dictionary.end(), [](string& a, string& b) {
            if (a.size() == b.size())
                return a < b;

            return a.size() > b.size();
        });

        for (string dic : dictionary) {
            int k = 0;
            for (int j = 0; j < s.size() && k < dic.size(); j++) {
                if (dic[k] == s[j]) {
                    k++;
                }
            }
            if (k == dic.size())
                return dic;
        }
        return "";
    }
};

int main() {

    Solution obj;

    string s;
    int n;

    cout << "Enter string s: ";
    cin >> s;

    cout << "Enter number of words in dictionary: ";
    cin >> n;

    vector<string> dictionary(n);

    cout << "Enter dictionary words:\n";
    for (int i = 0; i < n; i++) {
        cin >> dictionary[i];
    }

    string result = obj.findLongestWord(s, dictionary);

    cout << "Result: " << result << endl;

    return 0;
}
