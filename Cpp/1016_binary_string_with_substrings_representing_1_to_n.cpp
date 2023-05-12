// https://leetcode.cn/problems/binary-string-with-substrings-representing-1-to-n/

class Solution {
public:
    bool queryString(string s, int n) {
        unordered_set<int> check;
        for (int i = 0; i < s.size(); ++i) {
            int num = s[i] - '0';
            if (num <= n && num > 0) check.insert(num);
            else continue;
            for (int j = i+1; j < s.size(); ++j) {
                num = num * 2 + s[j] - '0';
                if (num <= n && num > 0) check.insert(num);
                else break;
            }
        }
        return check.size() == n? true: false;
    }
};
