// https://leetcode.cn/problems/wiggle-sort-ii/

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
            [](const int a, const int b) {return a > b;});
        vector<int> nums_sort(nums);
        
        int n = nums.size(), k = 0;
        for (int i = 1; i < n; i=i+2) {
            nums[i] = nums_sort[k];
            k = k + 1;
        }
        for (int i = 0; i < n; i=i+2) {
            nums[i] = nums_sort[k];
            k = k + 1;
        }
    }
};
