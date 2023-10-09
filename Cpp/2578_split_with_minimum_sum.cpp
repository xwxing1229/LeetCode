// https://leetcode.cn/problems/split-with-minimum-sum/

class Solution {
public:
    int splitNum(int num) {
        vector<int> digits;
        int n = num;
        while (n > 0) {
            digits.push_back(n % 10);
            n /= 10;
        }
        sort(digits.begin(), digits.end());
        int num1 = 0, num2 = 0;
        for (int i = 1; i < digits.size(); i=i+2) {
            num1 = 10 * num1 + digits[i-1];
            num2 = 10 * num2 + digits[i];
        }
        if (digits.size() % 2 == 1) {
            num1 = 10 * num1 + digits.back();
        }
        return num1 + num2;
    }
};
