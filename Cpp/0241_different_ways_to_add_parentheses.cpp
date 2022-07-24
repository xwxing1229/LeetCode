// https://leetcode.cn/problems/different-ways-to-add-parentheses/

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        split(expression, nums, ops);
        vector<int> res = computeAll(0, nums.size());
        return res;
    }

private:
    void split(string expression, vector<int>& nums, vector<char>& ops) {
        int n = expression.size();
        int num = 0;
        for (int i = 0; i < n; ++i) {
            char ch = expression[i];
            if ((ch == '+') || (ch == '-') || (ch == '*')) {
                nums.push_back(num);
                ops.push_back(ch);
                num = 0;
            }
            else if (i == n-1) {
                num = num * 10 + ch - '0';
                nums.push_back(num);
                num = 0;
            }
            else {
                num = num * 10 + ch - '0';
            }
        }
    }

    vector<int> computeAll(int left, int right) {
        // Compute using {nums[left], ..., nums[right-1]} in all possible ways.
        vector<int> res;
        if (right - left == 1) {
            res.push_back(nums[left]);
            return res;
        }

        for (int i = left+1; i < right; ++i) {
            vector<int> nums_left = computeAll(left, i); // nums[left], ..., nums[i-1]
            vector<int> nums_right = computeAll(i, right); // nums[i], ..., nums[right-1]

            char ch = ops[i-1];
            for (int num_l: nums_left) {
                for (int num_r: nums_right) {
                    if (ch == '+') {
                        res.push_back(num_l + num_r);
                    }
                    else if (ch == '-') {
                        res.push_back(num_l - num_r);
                    }
                    else {
                        res.push_back(num_l * num_r);
                    }
                }
            }
        }
        return res;
    }

    vector<int> nums;
    vector<char> ops;
};
