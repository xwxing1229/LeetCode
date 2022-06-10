// https://leetcode.cn/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int carry = 1;
        for (int i = n-1; i >= 0; --i) {
            if (carry == 0) {
                break;
            }
            int tmp = digits[i] + carry;
            carry = tmp / 10;
            digits[i] = tmp - carry * 10;
        }
        if (carry > 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
