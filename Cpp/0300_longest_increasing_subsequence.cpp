// https://leetcode.cn/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // arr[i] indicates the minimum value of the last element of a
        // sequence with length i+1.
        vector<int> arr = {nums[0]};
        for (int i = 1; i < nums.size(); ++i) {
            int num = nums[i];
            if (num > arr.back()) {
                arr.push_back(num);
            }
            else {
                // Find a minimum i such that arr[i] >= num.
                int left = 0, right = arr.size() - 1;
                int tmp = arr.size() - 1;
                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (arr[mid] >= num) {
                        right = mid - 1;
                        tmp = mid;
                    }
                    else {
                        left = mid + 1;
                    }
                }
                arr[tmp] = num;
            }
        }
        return arr.size();
    }
};
