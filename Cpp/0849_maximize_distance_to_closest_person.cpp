// https://leetcode.cn/problems/maximize-distance-to-closest-person/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i = 0, n = seats.size();
        while (i < n && seats[i] == 0) {
            i += 1;
        }
        int res = i, pre = i;
        while (i < n) {
            if (seats[i] == 1) {
                res = max(res, (i-pre)/2);
                pre = i;
            }
            i += 1;
        }
        if (seats[n-1] == 0) {
            res = max(res, n-1-pre);
        }
        return res;
    }
};
