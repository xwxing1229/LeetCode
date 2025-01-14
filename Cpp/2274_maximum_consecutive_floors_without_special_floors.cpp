// https://leetcode.cn/problems/minimum-rounds-to-complete-all-tasks/

class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(), special.end());
        int res = max(special[0] - bottom, top - special.back());
        for (int i = 1; i < special.size(); ++i) {
            res = max(res, special[i] - special[i-1] - 1);
        }
        return res;
    }
};
