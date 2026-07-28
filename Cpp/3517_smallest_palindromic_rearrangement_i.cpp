// https://leetcode.cn/problems/smallest-palindromic-rearrangement-i/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        vector<int> count(26, 0);
        for (int i = 0; i < n/2; ++i) {
            count[s[i] - 'a'] += 1;
        }

        string res;
        for (int i = 0; i < 26; ++i) {
            res += string(count[i], 'a'+i);
        }
        res = res + string(n%2, s[n/2]) + string(res.rbegin(), res.rend());
        return res;
    }
};