// https://leetcode.cn/problems/132-pattern/

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        // leftMin[j]: the minimum number in nums[0], nums[1], ... nums[j-1].
        vector<int> leftMin(n, nums[0]);
        for (int j = 1; j < n; ++j) {
            if (nums[j-1] < leftMin[j-1]) {
                leftMin[j] = nums[j-1];
            }
            else {
                leftMin[j] = leftMin[j-1];
            }
        }

        stack<int> stk; // monotonic stack
        stk.push(nums[n-1]);
        for (int j = n-2; j > 0; --j) {
            int J = nums[j];
            int maxLessThanJ = -1000000000;
            while ((!stk.empty()) && (stk.top() < J)) {
                maxLessThanJ = stk.top();
                stk.pop();
            }
            if (maxLessThanJ > leftMin[j]) {
                return true;
            }
            stk.push(J);
        }
        return false;
    }
};
