// https://leetcode.cn/problems/tuple-with-same-product/

class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> counts;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = i+1; j < nums.size(); ++j) {
                counts[nums[i] * nums[j]] += 1;
            }
        }
        int res = 0;
        for (auto it = counts.begin(); it != counts.end(); ++it) {
            int cnt = it->second;
            if (cnt >= 2) {
                res += cnt * (cnt-1);
            }
        }
        return res * 4;
    }
};
