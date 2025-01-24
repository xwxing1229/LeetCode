// https://leetcode.cn/problems/double-modular-exponentiation/

class Solution {
public:
    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<vector<int>> remainders(10);
        for (int i = 0; i < 10; ++i) {
            remainders[i].push_back(i);
            int val = i * i % 10;
            while (val != i) {
                remainders[i].push_back(val);
                val = val * i % 10;
            }
        }
        vector<int> res;
        for (int i = 0; i < variables.size(); ++i) {
            int ai = variables[i][0], bi = variables[i][1], ci = variables[i][2];
            int mi = variables[i][3];
            if (mi <= target) continue;
            int tmp = remainders[ai%10][(bi-1) % remainders[ai%10].size()];
            // Check if tmp ^ ci % mi == target.
            int val = 1, cnt = 0;
            while (cnt < ci) {
                val = val * tmp % mi;
                cnt += 1;
            }
            if (val % mi == target) {
                res.push_back(i);
            }
        }
        return res;
    }
};
