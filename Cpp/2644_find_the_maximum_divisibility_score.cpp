// https://leetcode.cn/problems/find-the-maximum-divisibility-score/

class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        unordered_map<int, int> cnt;
        for (auto num: nums) cnt[num] += 1;
        int res = divisors[0], score = 0;
        for (auto d: divisors) {
            int tmp = 0;
            for (auto it = cnt.begin(); it != cnt.end(); ++it) {
                if (it->first % d == 0) {
                    tmp += 1;
                }
            }
            if (tmp > score) {
                res = d;
                score = tmp;
            }
            else if (tmp == score && d < res) {
                res = d;
            }
        }
        return res;
    }
};
