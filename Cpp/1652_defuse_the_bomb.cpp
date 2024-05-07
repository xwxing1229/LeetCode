// https://leetcode.cn/problems/defuse-the-bomb/

class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        if (k == 0) return res;
        int left = 1, right = k;
        if (k < 0) {
            left = n+k;
            right = n-1;
        }
        for (int i = left; i <= right; ++i) {
            res[0] += code[i];
        }
        for (int i = 1; i < n; ++i) {
            right = (right + 1) % n;
            res[i] = res[i-1] + code[right] - code[left];
            left = (left + 1) % n;
        }
        return res;
    }
};
