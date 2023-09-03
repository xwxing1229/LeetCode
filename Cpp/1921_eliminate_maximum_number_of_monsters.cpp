// https://leetcode.cn/problems/eliminate-maximum-number-of-monsters/

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> t(n);
        for (int i = 0; i < n; ++i) {
            t[i] = (dist[i] + speed[i] - 1) / speed[i];
        }
        sort(t.begin(), t.end());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (t[i] - i > 0) {
                res += 1;
            }
            else {
                break;
            }
        }
        return res;
    }
};