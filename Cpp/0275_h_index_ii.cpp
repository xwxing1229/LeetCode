// https://leetcode.cn/problems/h-index-ii/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int left = 0, right = n - 1;
        int res = 0;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (n - mid <= citations[mid]) {
                right = mid - 1;
                res = n - mid;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};
