// https://leetcode.cn/problems/contains-duplicate-ii/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> hash_set;
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k) {
                hash_set.erase(nums[i-k-1]);
            }
            if (hash_set.find(nums[i]) != hash_set.end()) {
                return true;
            }
            hash_set.emplace(nums[i]);
        }
        return false;
    }
};
