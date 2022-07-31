// https://leetcode.cn/problems/range-sum-query-immutable/

class NumArray {
public:
    NumArray(vector<int>& nums) {
        sum_to_now.resize(nums.size());
        int tmp = 0;
        for (int i = 0; i < nums.size(); ++i) {
            tmp = tmp + nums[i];
            sum_to_now[i] = tmp;
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) {
            return sum_to_now[right];
        }
        else {
            return sum_to_now[right] - sum_to_now[left-1];
        }
    }

private:
    vector<int> sum_to_now;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */