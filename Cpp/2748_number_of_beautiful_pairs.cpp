// https://leetcode.cn/problems/number-of-beautiful-pairs/
        
class Solution {
public:
    int countBeautifulPairs(vector<int>& nums) {
        int res = 0, n = nums.size();
        vector<int> last_digits(n, 0);
        for (int i = 0; i < n; ++i) {
            last_digits[i] = nums[i] % 10;
        }
        for (int i = 0; i < n; ++i) {
            int digiti = getFirstDigit(nums[i]);
            for (int j = i + 1; j < n; ++j) {
                if (gcd(digiti, last_digits[j]) == 1) {
                    res += 1;
                }
            }
        }
        return res;
    }

    int getFirstDigit(int num) {
        int digit = 0;
        while (num > 0) {
            digit = num % 10;
            num /= 10;
        }
        return digit;
    }
};