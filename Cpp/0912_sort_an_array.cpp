// https://leetcode.cn/problems/sort-an-array/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        res.resize(n);
        for (int i = 0; i < n; ++i) {
            res[i] = nums[i];
        }
        mergeSorted(nums, 0, n-1);
        return res;
    }

private:
    void mergeSorted(vector<int>& nums, int left, int right) {
        if (left >= right) {
            return;
        }

        int mid = left + (right - left) / 2;
        mergeSorted(nums, left, mid);
        mergeSorted(nums, mid+1, right);
        mergeTwoSorted(nums, left, mid, right);
    }

    void mergeTwoSorted(vector<int>& nums, int left, int mid, int right) {
        // Similar to #0088.
        if (res[mid] <= res[mid+1]) {
            return;
        }

        for (int idx = left; idx <= right; ++idx) {
            nums[idx] = res[idx];
        }

        int i1 = mid, i2 = right;
        for (int idx = right; idx >= left; --idx) {
            if (i2 <= mid) {
                return;
            }
            else if ((i1 >= left) && (res[i1] > nums[i2])) {
                res[idx] = res[i1];
                i1 = i1 - 1;
            }
            else {
                res[idx] = nums[i2];
                i2 = i2 - 1;
            }
        }
    }

    vector<int> res;
};
