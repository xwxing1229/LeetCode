// https://leetcode.cn/problems/next-greater-element-ii/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<pair<int,int>> stk;
        for (int i = 0; i < n-1; ++i) {
            nums.push_back(nums[i]);
        }
        for (int i = 0; i < 2*n-1; ++i) {
            int num = nums[i];
            while (!stk.empty() && stk.top().first < num) {
                auto val_idx = stk.top();
                stk.pop();
                res[(val_idx.second) % n] = num;
            }
            stk.push(make_pair(num, i));
        }
        return res;
    }
};

