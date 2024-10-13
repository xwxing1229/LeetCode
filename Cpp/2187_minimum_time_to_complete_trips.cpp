// https://leetcode.cn/problems/minimum-time-to-complete-trips/

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        int time_min = time[0];
        for (int t: time) {
            time_min = min(time_min, t);
        }
        long long left = 1, right = (long long)totalTrips * time_min;
        long long res = right;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long tmp = 0;
            for (int t: time) {
                tmp += mid / t;
            }
            if (tmp >= (long long)totalTrips) {
                res = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return res;
    }
};