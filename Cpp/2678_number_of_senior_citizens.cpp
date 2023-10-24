// https://leetcode.cn/problems/number-of-senior-citizens/

class Solution {
public:
    int countSeniors(vector<string>& details) {
        int res = 0;
        for (auto &s: details) {
            if (stoi(s.substr(11, 2)) > 60) {
                res += 1;
            }
        }
        return res;
    }
};