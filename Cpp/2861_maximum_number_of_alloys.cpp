// https://leetcode.cn/problems/maximum-number-of-alloys/
        
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int res = 0, left = 0, right = stock[0];
        for (int s: stock) {
            right = min(right, s);
        }
        right += budget;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bool valid = false;
            for (auto &com: composition) {
                long long spend = 0;
                for (int i = 0; i < n; ++i) {
                    spend += max((long long)com[i]*mid-stock[i], 0LL) * cost[i];
                }
                if (spend <= budget) {
                    valid = true;
                    break;
                }
            }
            if (valid) {
                left = mid + 1;
                res = mid;
            }
            else {
                right = mid - 1;
            }
        }
        return res;
    }
};
