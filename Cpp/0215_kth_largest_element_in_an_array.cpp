// https://leetcode.cn/problems/kth-largest-element-in-an-array/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        srand(time(0));
        int n = nums.size();
        quickSort(nums, k, 0, n-1);
        return nums[n-k];
    }

private:
    void quickSort(vector<int>& nums, int k, int left, int right) {
        if (left >= right) {
            return;
        }
        int pivotIdx = partition(nums, left, right);
        if (pivotIdx == nums.size() - k) {
            return;
        }
        else if (pivotIdx < nums.size() - k) {
            quickSort(nums, k, pivotIdx+1, right);
        }
        else {
            quickSort(nums, k, left, pivotIdx-1);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int pivotIdx = randPivotIdx(left, right);
        int pivot = nums[pivotIdx];
        swap(nums, left, pivotIdx);
        int i = left + 1, j = right;
        while (i <= j) {
            while ((i <= right) && (nums[i] < pivot)) {
                i = i + 1;
            }
            while ((j >= left) && (nums[j] > pivot)) {
                j = j - 1;
            }
            if (i < j) {
                swap(nums, i, j);
                i = i + 1;
                j = j - 1;
            }
            else if (i == j) {
                break;
            }
        }
        swap(nums, left, j);
        return j;
    }

    int randPivotIdx(int left, int right) {
        int pivotIdx = left + rand() % (right - left + 1);
        return pivotIdx;
    }

    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
