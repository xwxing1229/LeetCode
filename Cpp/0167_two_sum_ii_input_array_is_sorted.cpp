// https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0, right = numbers.size() - 1;
        vector<int> res(2,0);
        while (left < right) {
            if (numbers[left] + numbers[right] > target) {
                right = right - 1;
            }
            else if (numbers[left] + numbers[right] < target) {
                left = left + 1;
            }
            else {
                res[0] = left + 1;
                res[1] = right + 1;
                return res;
            }
        }
        return res;
    }
};
