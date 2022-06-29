// https://leetcode.cn/problems/evaluate-reverse-polish-notation/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        vector<int> nums;
        for (string token: tokens) {
            if ((token.size() > 1) || ((token[0] >= '0') && (token[0] <= '9'))) {
                int num = stoi(token);
                nums.push_back(num);
            }
            else {
                int second = nums.back();
                nums.pop_back();
                int first = nums.back();
                nums.pop_back();
                int num;
                switch(token[0]) {
                    case '+': {
                        num = first + second;
                        break;
                    }
                    case '-': {
                        num = first - second;
                        break;
                    }
                    case '*': {
                        num = first * second;
                        break;
                    }
                    default: {
                        num = first / second;
                        break;
                    }
                }
                nums.push_back(num);
            }
        }
        return nums[0];
    }
};
