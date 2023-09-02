// https://leetcode.cn/problems/maximum-enemy-forts-that-can-be-captured/

class Solution {
public:
    int captureForts(vector<int>& forts) {
        int res = 0;
        int i = 0, n = forts.size();
        while (i < n) {
            while (i < n && forts[i] == 0) {
                i += 1;
            }
            if (i >= n) {
                break;
            }
            int idx = i, cur = forts[i];
            i += 1;
            while (i < n && forts[i] == 0) {
                i += 1;
            }
            if (i < n && forts[i] + cur == 0) {
                res = max(res, i-idx-1);
            }
        }
        return res;
    }
};
