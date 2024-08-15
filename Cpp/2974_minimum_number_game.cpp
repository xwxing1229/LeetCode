// https://leetcode.cn/problems/minimum-number-game/
        
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> res(nums.size());
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i+=2) {
            res[i] = nums[i+1];
            res[i+1] = nums[i];
        }
        return res;
    }
};
