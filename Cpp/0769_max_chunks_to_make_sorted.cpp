// https://leetcode.cn/problems/max-chunks-to-make-sorted/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int cur_max = 0;
        int res = 0;
        for (int i = 0; i < arr.size(); ++i) {
            int cur = arr[i];
            if (cur > cur_max) {
                cur_max = cur;
            }
            if (cur_max == i) {
                res = res + 1;
            }
        }
        return res;
    }
};
