// https://leetcode.cn/problems/shortest-subarray-to-be-removed-to-make-array-sorted/

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        arr_ = arr;
        int n = arr.size(), i = 0;
        int res = 0;
        while (i < n) {
            if (i + 1 < n && arr[i] > arr[i+1]) {
                int j = checkBackward(n-1, i, arr[i]); // keep arr[0], ...,  arr[i]
                res = j - i;

                while (i > 0) { // keep arr[0], ..., arr[k] with 0 < k < i
                    j = checkBackward(j, i-1, arr[i-1]);
                    res = min(res, j-i+1);
                    i -= 1;
                }
                j = checkBackward(j, 0, 0); // not keep arr[0]
                res = min(res, j+1);
                break;
            }
            i += 1;
        }
        return res;
    }

    int checkBackward(int j, int i, int start) {
        int n = arr_.size();
        while (arr_[j] >= start
            && (j == n-1
                || (j >= i && j < n-1 && arr_[j] <= arr_[j+1]))) {
            j -= 1;
        }
        return j;
    }

    vector<int> arr_;
};