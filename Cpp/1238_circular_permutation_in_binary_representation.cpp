// https://leetcode.cn/problems/circular-permutation-in-binary-representation/

class Solution {
public:
    vector<int> circularPermutation(int n, int start) {
        vector<int> tmp = {0, 1};
        int len = pow(2, n), digits = 1;
        while (tmp.size() < len) {
            int len_cur = tmp.size(), base = 1 << digits;
            for (int i = len_cur-1; i >= 0; --i) {
                tmp.push_back(base + tmp[i]);
            }
            digits += 1;
        }
        
        int k = 0;
        while (tmp[k] != start) {
            k += 1;
        }
        vector<int> res(len);
        for (int i = 0; i < len; ++i) {
            res[i] = tmp[k % len];
            k += 1;
        }
        return res;
    }
};
