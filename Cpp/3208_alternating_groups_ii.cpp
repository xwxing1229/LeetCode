// https://leetcode.cn/problems/alternating-groups-ii/

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        colors.insert(colors.end(), colors.begin(), colors.begin()+k-1);
        int res = 0, cnt = 1;
        for (int i = 0; i < colors.size()-1; ++i) {
            if (colors[i] != colors[i+1]) cnt += 1;
            else cnt = 1;

            if (cnt >= k) res += 1;
        }
        return res;
    }
};
