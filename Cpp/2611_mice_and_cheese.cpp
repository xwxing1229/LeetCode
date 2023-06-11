// https://leetcode.cn/problems/mice-and-cheese/

class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<int> idx(n);
        for (int i = 0; i < n; ++i) {
            idx[i] = i;
        }
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return reward1[i] - reward2[i] > reward1[j] - reward2[j];
        });
        int res = 0;
        for (int i = 0; i < k; ++i) {
            res += reward1[idx[i]];
        }
        for (int i = k; i < n; ++i) {
            res += reward2[idx[i]];
        }
        return res;
    }
};