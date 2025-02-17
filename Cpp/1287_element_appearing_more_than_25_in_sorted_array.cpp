// https://leetcode.cn/problems/element-appearing-more-than-25-in-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int res = arr[0];
        int n = arr.size(), cnt_min = n / 4 + 1;
        int start = 0, cnt = 1;
        while (cnt < cnt_min) {
            int tar = arr[start];
            int left = start, right = n-1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                if (arr[mid] <= tar) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
            res = arr[right];
            cnt = right - start + 1;

            start = right + 1;
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1,2,2,6,6,6,6,7,10};
    // vector<int> arr = {1,2,3,3};
    cout << sol.findSpecialInteger(arr) << '\n';
    return 0;
}