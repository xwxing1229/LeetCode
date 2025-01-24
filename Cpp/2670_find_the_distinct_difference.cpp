// https://leetcode.cn/problems/find-the-distinct-difference-array/

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        vector<int> left(n+1, 0), right(n+1, 0);
        for (int i = 0; i < n; ++i) {
            if (s.find(nums[i]) != s.end()) {
                left[i+1] = left[i];
            }
            else {
                left[i+1] = left[i] + 1;
                s.insert(nums[i]);
            }
        }

        s.clear();
        for (int i = n-1; i >= 0; --i) {
            if (s.find(nums[i]) != s.end()) {
                right[i] = right[i+1];
            }
            else {
                right[i] = right[i+1] + 1;
                s.insert(nums[i]);
            }
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            res[i] = left[i+1] - right[i+1];
        }
        return res;
    }
};
