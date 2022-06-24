// https://leetcode.cn/problems/valid-palindrome/

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int i = 0, j = n - 1;
        while (i < j) {
            while ((i < n) && (!isalnum(s[i]))) {
                i = i + 1;
            }
            while ((j >= 0) && (!isalnum(s[j]))) {
                j = j - 1;
            }

            if ((i >= n) || (j < 0)) {
                continue;
            }

            if (tolower(s[i]) == tolower(s[j])) {
                i = i + 1;
                j = j - 1;
            }
            else {
                return false;
            }
        }
        return true;
    }
};
