// https://leetcode.cn/problems/find-the-highest-altitude/

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, cur = 0;
        for (int g: gain) {
            cur += g;
            if (res < cur) {
                res = cur;
            }
        }
        return res;
    }
};
