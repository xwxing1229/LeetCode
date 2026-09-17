// https://leetcode.cn/problems/find-two-non-overlapping-sub-arrays-each-with-target-sum/

#include <vector>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        // f[i]: min length of substr in arr[i:] with sum equal to target.
        vector<int> f(n, n);
        int rightmin = n;
        int right = n-1, s = 0;
        for (int left = n-1; left >= 0; --left) {
            s += arr[left];
            while (s > target) {
                s -= arr[right];
                right -= 1;
            }
            if (s == target) {
                rightmin = min(rightmin, right - left + 1);
            }
            f[left] = rightmin;
        }
        
        int res = n + 1;
        int left = 0;
        s = 0;
        for (int right = 0; right < n-1; ++right) {
            s += arr[right];
            while (s > target) {
                s -= arr[left];
                left += 1;
            }
            if (s == target) {
                int tmp = right - left + 1 + f[right+1];
                res = min(res, tmp);
            }
        }
        return res <= n ? res : -1;
    }
};