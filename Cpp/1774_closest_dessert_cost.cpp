// https://leetcode.cn/problems/closest-dessert-cost/

class Solution {
public:
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        res = baseCosts[0];
        for (int b: baseCosts) {
            dfs(toppingCosts, target, 0, b);
        }
        return res;
    }

private:
    void dfs(vector<int>& toppingCosts, int target, int idx, int cur) {
        int diff_res = abs(res - target), diff_cur = abs(cur - target);
        if (diff_res > diff_cur) {
            res = cur;
        }
        else if ((diff_res == diff_cur) && (res > cur)) {
            res = cur;
        }
        else if ((diff_res < diff_cur) && (cur > target)) {
            return;
        }

        if (idx == toppingCosts.size()) {
            return;
        }

        dfs(toppingCosts, target, idx+1, cur);
        dfs(toppingCosts, target, idx+1, cur+toppingCosts[idx]);
        dfs(toppingCosts, target, idx+1, cur+toppingCosts[idx]*2);
    }

    int res;
};
