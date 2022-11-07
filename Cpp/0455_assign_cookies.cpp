// https://leetcode.cn/problems/assign-cookies/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end(),
            [](const int g1, const int g2) {
                return g1 < g2;
            });
        sort(s.begin(), s.end(),
            [](const int s1, const int s2) {
                return s1 < s2;
            });
        int res = 0;
        int i = 0, n = s.size();
        for (int child: g) {
            while ((i < n) && (child > s[i])) {
                i += 1;
            }
            if (i == n) {
                break;
            }
            else {
                res += 1;
                i += 1;
            }
        }
        return res;
    }
};
