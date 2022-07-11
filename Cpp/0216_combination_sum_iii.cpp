// https://leetcode.cn/problems/combination-sum-iii/

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        backtrack(k, n, tmp, 0, 1);
        return res;
    }

private:
    void backtrack(int k, int n, vector<int>& tmp, int tmp_sum, int idx) {
        if (tmp.size() == k) {
            if (tmp_sum == n) {
                res.push_back(tmp);
            }
            return;
        }

        for (int i = idx; i < 10; ++i) {
            tmp.push_back(i);
            backtrack(k, n, tmp, tmp_sum+i, i+1);
            tmp.pop_back();
        }
    }

    vector<vector<int>> res;
};
