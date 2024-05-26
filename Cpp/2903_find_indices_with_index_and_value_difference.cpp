// https://leetcode.cn/problems/find-indices-with-index-and-value-difference-i/
        
class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int num_min = nums[0], index_min = 0;
        int num_max = nums[0], index_max = 0;
        vector<int> res(2, -1);
        for (int j = indexDifference; j < nums.size(); ++j) {
            int i = j-indexDifference;
            if (nums[i] < num_min) {
                num_min = nums[i];
                index_min = i;
            }
            else if (nums[i] > num_max) {
                num_max = nums[i];
                index_max = i;
            }
            if (nums[j] - num_min >= valueDifference) {
                res[0] = index_min;
                res[1] = j;
                return res;
            }
            else if (num_max - nums[j] >= valueDifference) {
                res[0] = index_max;
                res[1] = j;
                return res;
            }
        }
        return res;
    }
};
