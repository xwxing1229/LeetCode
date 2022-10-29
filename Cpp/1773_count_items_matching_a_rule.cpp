// https://leetcode.cn/problems/count-items-matching-a-rule/

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int rule = 0;
        if (ruleKey[0] == 'c') {
            rule = 1;
        }
        else if (ruleKey[0] == 'n') {
            rule = 2;
        }

        int res = 0;
        for (vector<string>& i: items) {
            if (i[rule] == ruleValue) {
                res += 1;
            }
        }
        return res;
    }
};
