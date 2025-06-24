// https://leetcode.cn/problems/find-all-k-distant-indices-in-an-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> res;
		int n = nums.size();
		for (int j = 0; j < n; ++j) {
			if (nums[j] == key) {
				for (int i = max(0, j-k); i < min(n, j+k+1); ++i) {
					if (res.size() == 0 || i > res.back()) {
						res.push_back(i);
					}
				}
			}
		}
		return res;
    }
};

int main() {
	Solution sol;
	// vector<int> nums = {3,4,9,1,3,9,5};
	// int key = 9;
	// int k = 1;
	vector<int> nums = {2,2,2,2,2};
	int key = 2;
	int k = 2;
	auto res = sol.findKDistantIndices(nums, key, k);
	for (auto &val: res) cout << val << ", ";
	cout << '\n';
	return 0;
}