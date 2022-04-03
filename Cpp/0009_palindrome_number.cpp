// https://leetcode-cn.com/problems/palindrome-number/

class Solution {
public:
	bool isPalindrome(int x) {
		if ((x != 0) && (x % 10 == 0)) return false;

		int sym = 0;
		while (x > sym) {
			sym = sym * 10 + x % 10;
			x = x / 10;
		}
		if ((x == sym) || (x == sym / 10)) return true;
		else return false;
	}
};