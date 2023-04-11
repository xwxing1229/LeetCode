// https://leetcode.cn/problems/check-distances-between-same-letters/

class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        bool res = true;
        vector<int> first_appear(26, -1);
        for (int i = 0; i < s.size(); ++i) {
            int idx = s[i] - 'a';
            if (first_appear[idx] < 0) {
                first_appear[idx] = i;
            }
            else if (i - first_appear[idx] - 1 != distance[idx]) {
                res = false;
                break;
            }
        }
        return res;
    }
};
