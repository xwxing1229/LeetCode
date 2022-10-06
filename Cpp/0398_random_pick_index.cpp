// https://leetcode.cn/problems/random-pick-index/

class Solution {
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (idxs.find(nums[i]) == idxs.end()) {
                idxs[nums[i]] = (vector<int>) {i};
            }
            else {
                idxs[nums[i]].push_back(i);
            }
        }
    }
    
    int pick(int target) {
        vector<int> idxs_tar = idxs[target];
        return idxs_tar[rand() % idxs_tar.size()];
    }

    unordered_map<int, vector<int>> idxs;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
