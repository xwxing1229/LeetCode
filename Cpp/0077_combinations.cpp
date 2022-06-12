// https://leetcode.cn/problems/combinations/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> check(n, 0);
        vector<int> tmp;
        backtrack(n, k, check, tmp, 0);
        return res;
    }

private:
    void backtrack(int n, int k, vector<int> check, vector<int> tmp,
        int idx) {
        if (tmp.size() == k) {
            res.push_back(tmp);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if ((i < idx) || (check[i] == 1)) {
                continue;
            }

            check[i] = 1;
            vector<int> comb(tmp);
            comb.push_back(i+1);
            backtrack(n, k, check, comb, i);
            check[i] = 0;
        }
    }

    vector<vector<int>> res;
};
