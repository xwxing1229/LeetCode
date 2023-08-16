// https://leetcode.cn/problems/find-the-losers-of-the-circular-game/
        
class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> check(n, false);
        int cur = 0, step = k;
        while (!check[cur]) {
            check[cur] = true;
            cur = (cur + step) % n;
            step += k;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!check[i]) {
                res.push_back(i+1);
            }
        }
        return res;
    }
};
