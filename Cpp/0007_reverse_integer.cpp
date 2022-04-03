// https://leetcode-cn.com/problems/reverse-integer/

class Solution {
public:
	int reverse(int x) {
		int res = 0;
		int min_ = (-pow(2,31)) / 10;
		int max_ = (pow(2,31) - 1) / 10;
		while (x != 0) {
			if ((res < min_) || (x > max_)) {
				return 0;
			}
			res = res * 10 + x % 10;
			x = x / 10;
		}
		return res;
	}
};