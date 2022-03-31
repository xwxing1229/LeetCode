// https://leetcode-cn.com/problems/zigzag-conversion/

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) {
			return s;
		}

		int idx = 0, l = 2 * numRows - 2;
		vector<string> v(numRows);
		for (int i = 0; i < s.size(); ++i) {
			if (idx < numRows - 1) {
				v[idx] = v[idx] + s[i];
				idx = idx + 1;
			}
			else if (idx < l) {
				v[l - idx] = v[l - idx] + s[i];
				idx = idx + 1;
			}
			else {
				v[0] = v[0] + s[i];
				idx = 1;
			}
		}
		
		string res;
		for (int i = 0; i < numRows; ++i) {
			res = res + v[i];
		}
		return res;
	}
};