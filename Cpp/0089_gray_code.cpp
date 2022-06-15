// https://leetcode.cn/problems/gray-code/

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        int tmp = 1;
        for (int i = 0; i < n; ++i) {
            for (int j = res.size()-1; j >= 0; --j) {
                res.push_back(res[j] + tmp);
            }
            tmp = tmp << 1;
        }
        return res;
    }
};
