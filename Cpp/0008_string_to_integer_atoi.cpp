// https://leetcode-cn.com/problems/string-to-integer-atoi/

class Solution {
public:
	int myAtoi(string s) {
		int res = 0, positive = 1;
		int min_ = (-pow(2,31)) / 10, max_ = (pow(2,31) - 1) / 10;
		bool start = false;
		for (char c: s) {
			if ((!start) && (c == ' ')) continue;
			else if ((!start) && (c == '+')) start = true;
			else if ((!start) && (c == '-')) {
				positive = 0;
				start = true;
			}
			else if ((c >= '0') && (c <= '9')) {
				if ((positive) &&
					(res > max_ || (res == max_ && c > '7'))) {
					return pow(2,31) - 1;
				}
				else if ((!positive) &&
					(res < min_ || (res == min_ && c > '8'))) {
					return -pow(2,31);
				}
				else {
					// positive = 1 -> 2*positive-1 = 1
					// positive = 0 -> 2*positive-1 = -1
					res = res * 10 + (c-'0') * (2*positive-1);
				}
				start = true;
			}
			else break;
		}

		return res;
	}
};