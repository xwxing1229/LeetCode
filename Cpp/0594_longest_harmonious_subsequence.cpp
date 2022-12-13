// https://leetcode.cn/problems/longest-harmonious-subsequence/

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int num: nums) {
            cnt[num] += 1;
        }

        int res = 0;
        for (auto it = cnt.begin(); it != cnt.end(); ++it) {
            int num = it->first, c = it->second;
            if ((cnt.find(num+1) != cnt.end()) && (cnt[num+1] + c > res)) {
                res = cnt[num+1] + c;
            }
        }
        return res;
    }
};
