// https://leetcode.cn/problems/triples-with-bitwise-and-equal-to-zero/

class Solution {
public:
    int countTriplets(vector<int>& nums) {
        unordered_map<int, int> cnt;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                cnt[nums[i] & nums[j]] += 1;
            }
        }
        int res = 0;
        for (int k = 0; k < nums.size(); ++k) {
            for (auto it = cnt.begin(); it != cnt.end(); ++it) {
                if ((it->first & nums[k]) == 0) {
                    res += it->second;
                }
            }
        }
        return res;
    }
};
