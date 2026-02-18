#include <iostream>
using namespace std;

bool hasAlternatingBits(int n) {
    if(n == 0) return true;

    long long v = 1;

    while(v < n) {
        v *= 2;
        if(n == v)
            return true;

        v = v * 2 + 1;
    }

    return (n == v) ?  true:  false;
}
// Input: n = 5
// Output: true
// Explanation: The binary representation of 5 is: 101

// Input: n = 7
// Output: false
// Explanation: The binary representation of 7 is: 111.
int main() {
    int n;
    cout << "Enter number: ";
    cin >> n;

    if(hasAlternatingBits(n))
        cout << "True";
    else
        cout << "False";

    return 0;
}
