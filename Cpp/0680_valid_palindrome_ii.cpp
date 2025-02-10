// https://leetcode.cn/problems/valid-palindrome-ii/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        return dfs(s, 0, s.size()-1, 0);
    }

    bool dfs(string &s, int left, int right, int cnt) {
        if (cnt >= 2) return false;
        while (left < right) {
            if (s[left] == s[right]) {
                left += 1;
                right -= 1;
            }
            else {
                return dfs(s, left+1, right, cnt+1) || dfs(s, left, right-1, cnt+1);
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    string s = "abca";
    cout << sol.validPalindrome(s) << '\n';
    return 0;
}

