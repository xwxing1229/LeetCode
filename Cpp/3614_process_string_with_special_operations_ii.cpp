// https://leetcode.cn/problems/process-string-with-special-operations-ii/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        // '*': remove the last ch from the current string
        // '#': duplicate the current string and append it to itself
        // '%': reverse the current string
        // ch : append it to the current string

        vector<long long> size(s.size());
        long long curr = 0;
        for (int i = 0; i < s.size(); ++i) {
            char ch = s[i];
            if (ch == '*') curr = max(curr-1, (long long)0);
            else if (ch == '#') curr *= 2;
            else if (ch != '%') curr += 1;
            size[i] = curr;
        }

        if (k >= size.back()) return '.';

        for (int i = s.size()-1; i >= 0; --i) {
            char ch = s[i];
            long long curr = size[i];
            if (ch == '#') {
                if (k >= curr / 2) {
                    k -= curr / 2;
                }
            }
            else if (ch == '%') {
                k = curr - 1 - k;
            }
            else if (ch != '*' && k == curr - 1) {
                return ch;
            }
        }
        return '.';
    }
};

int main() {
    Solution sol;
    string s = "a#b%*";
    long long k = 1;
    cout << sol.processStr(s, k) << '\n';
    return 0;
}