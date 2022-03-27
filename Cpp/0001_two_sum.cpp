// https://leetcode-cn.com/problems/two-sum/

class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> table;
		for (int i = 0; i < nums.size(); ++i) {
			auto iter = table.find(target - nums[i]);
			if (iter != table.end()) {
				return {iter->second, i};
			}
			table.emplace(nums[i], i);
		}
		return {};
	}
};