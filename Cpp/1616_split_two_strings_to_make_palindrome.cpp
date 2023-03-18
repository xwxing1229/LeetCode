// https://leetcode.cn/problems/split-two-strings-to-make-palindrome/

class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int n = a.size();
        if (isPalindrome(a) || isPalindrome(b)) {
            return true;
        }
        bool flag1 = true, flag2 = true;
        for (int i = 1; i < n/2+1; ++i) {
            if (a[i-1] != b[n-i]) flag1 = false;
            if (b[i-1] != a[n-i]) flag2 = false;
            if (!(flag1 || flag2)) {
                string sub1 = a.substr(i-1, n-i-i+2); // middle substring of a
                string sub2 = b.substr(i-1, n-i-i+2); // middle substring of b
                if (isPalindrome(sub1) || isPalindrome(sub2)) {
                    return true;
                }
                else {
                    return false;
                }
            }
        }
        if (flag1 || flag2) return true;
        else return false;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i += 1;
            j -= 1;
        }
        return true;
    }
};