// https://leetcode.cn/problems/alternating-groups-i/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int res = 0, n = colors.size();
        for (int i = 1; i < n-1; ++i) {
            if (colors[i] != colors[i-1] && colors[i] != colors[i+1]) {
                res += 1;
            }
        }
        if (colors[0] != colors.back() && colors[0] != colors[1]) {
            res += 1;
        }
        if (colors.back() != colors[n-2] && colors.back() != colors[0]) {
            res += 1;
        }
        return res;
    }
};
