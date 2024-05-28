// https://leetcode.cn/problems/find-the-peaks/
        
class Solution {
public:
    vector<int> findPeaks(vector<int>& mountain) {
        vector<int> res;
        int i = 1, n = mountain.size();
        while (i < n-1) {
            int cur = mountain[i];
            if (cur > mountain[i-1] && cur > mountain[i+1]) {
                res.push_back(i);
                i += 2;
            }
            else {
                i += 1;
            }
        }
        return res;
    }
};
