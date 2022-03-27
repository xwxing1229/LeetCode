// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		unordered_map<char, int> table;
		int res = 0;
		int start = 0, end = 0;
		while (end < s.size()) {
			auto iter = table.find(s[end]);
			// s[end] already exists in table.
			if (iter != table.end()) {
				start = max(iter->second + 1, start);
				table[s[end]] = end;
			}
			// s[end] does not exist in table.
			else {
				table.emplace(s[end], end);
			}
			end = end + 1;
			res = max(res, end - start);
		}

		return res;
	}
};