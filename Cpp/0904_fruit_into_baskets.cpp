// https://leetcode.cn/problems/fruit-into-baskets/

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int res = 1;
        // dp: maximum number of fruits one can pick that end with current fruit
        // dp_pre: maximum number of fruits one can pick that end with last fruit
        int dp = 1, dp_pre = 1;
        int type1 = fruits[0], type2 = fruits[0];
        vector<int> start(fruits.size(), 0);
        for (int i = 1; i < fruits.size(); ++i) {
            int fruit = fruits[i], fruit_pre = fruits[i-1];
            if ((fruit == type1) || (fruit == type2)) {
                dp = dp_pre + 1;
                if (fruit != fruit_pre) {
                    start[fruit] = i;
                }
            }
            else {
                dp = i - start[fruit_pre] + 1;
                start[fruit] = i;
                type1 = fruit_pre;
                type2 = fruit;
            }

            if (dp > res) {
                res = dp;
            }

            dp_pre = dp;
        }
        return res;
    }
};
