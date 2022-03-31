// https://leetcode-cn.com/problems/longest-palindromic-substring/

class Solution {
public:
	string longestPalindrome(string s) {
		// // Dynamic programming.
		// // If s[i] == s[j] and (s[i+1], s[i+2], ..., s[j-1]) is a palindrome,
		// // then (s[i], s[i+1], ..., s[j]) is also a palindrome.
		// int n = s.size();
		// int start = 0, max_len = 1;
		// vector<vector<int>> dp(n, vector<int>(n));
		// for (int j = 1; j < n; ++j) {
		// 	dp[j-1][j-1] = 1;
		// 	for (int i = 0; i < j; ++i) {
		// 		if (s[i] != s[j]) {
		// 			dp[i][j] = 0;
		// 		}
		// 		else {
		// 			if (i + 1 >= j - 1) {
		// 				dp[i][j] = 1;
		// 			}
		// 			else {
		// 				dp[i][j] = dp[i+1][j-1];
		// 			}
		// 		}
		// 		if ((j - i + 1 > max_len) && (dp[i][j])) {
		// 			start = i;
		// 			max_len = j - i + 1;
		// 		}
		// 	}
		// }
		// return s.substr(start, max_len);

		// To get a palindrome, expand the string from one char to both sides.
		int n = s.size();
		int start = 0, max_len = 0;
		for (int i = 0; i < n; ++i) {
			int len_odd = expandFromCenter(s, n, i, i);
			int len_even = expandFromCenter(s, n, i, i+1);
			int len = max(len_odd, len_even);
			if (len > max_len) {
				start = i - (len + 1) / 2 + 1;
				max_len = len;
			}
		}
		return s.substr(start, max_len);
	}

private:
	int expandFromCenter(string s, int n, int start, int end) {
		while ((start >= 0) && (end < n) && (s[start] == s[end])) {
			start = start - 1;
			end = end + 1;
		}
		return end - start - 1;
	}
};