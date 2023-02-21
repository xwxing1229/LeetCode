// https://leetcode.cn/problems/minimum-number-of-taps-to-open-to-water-a-garden/

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> water(n+1);
        for (int i = 0; i < n+1; ++i) {
            water[i].first = max(0, i - ranges[i]);
            water[i].second = min(n, i + ranges[i]);
        }
        sort(water.begin(), water.end(),
            [](const pair<int,int> p1, const pair<int,int> p2) {
                return p1.first < p2.first || (p1.first == p2.first && p1.second > p2.second);
            });

        int left = water[0].first, right = water[0].second, right_max = water[0].second;
        if (left > 0) return -1;
        else if (right_max == n) return 1;

        int res = 1, i = 1;
        while (i < n+1) {
            while (i < n+1 && water[i].first <= right) {
                right_max = max(right_max, water[i].second);
                i += 1;
            }
            if (i == n) break;

            res += 1;
            if (right_max == n) return res;
            else if (water[i].first > right_max) return -1;
            else right = right_max;
        }

        if (right_max == n) return res + 1;
        else return -1;
    }
};
