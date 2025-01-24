// https://leetcode.cn/problems/lexicographically-smallest-palindrome/
        
class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.size();
        string res(s);
        for (int i = 0; i < n/2; ++i) {
            char ch1 = s[i], ch2 = s[n-1-i];
            if (ch1 > ch2) {
                res[i] = ch2;
            }
            else {
                res[n-1-i] = ch1;
            }
        }
        return res;
    }
};