// https://leetcode.cn/problems/previous-permutation-with-one-swap/

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        int n = arr.size();
        int left = -1, right = -1;
        for (int i = n-2; i >= 0; --i) {
            if (arr[i] > arr[i+1]) {
                left = i;
                break;
            }
        }
        if (left == -1) {
            return arr;
        }

        // Find the maximum number in arr[left+1:] which is less than arr[left].
        int max_ = 0;
        for (int i = left + 1; i < n; ++i) {
            if (arr[left] > arr[i] && arr[i] > max_) {
                max_ = arr[i];
                right = i;
            }
        }
        swap(arr[left], arr[right]);
        return arr;
    }
};
