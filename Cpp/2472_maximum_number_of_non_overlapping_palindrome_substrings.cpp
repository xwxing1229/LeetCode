// https://leetcode.cn/problems/maximum-number-of-non-overlapping-palindrome-substrings/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int maxPalindromes(string s, int k) {
        auto isPalindrome = [](const string &s) {
            int left = 0, right = s.size() - 1;
            while (left < right) {
                if (s[left] != s[right]) return false;
                left += 1;
                right -= 1;
            }
            return true;
        };
        
        int n = s.size();
        // dp[i]: number of palindromes in s[: i]
        vector<int> dp(n+1, 0);
        for (int i = k; i <= n; ++i) {
            dp[i] = dp[i-1]; // s[i-1] not used
            if (isPalindrome(s.substr(i-k, k))) {
                dp[i] = max(dp[i], dp[i-k]+1);
            }
            if (i > k && isPalindrome(s.substr(i-k-1, k+1))) {
                dp[i] = max(dp[i], dp[i-k-1]+1);
            }
        }
        return dp[n];
    }
};