// https://leetcode.cn/problems/distance-between-bus-stops/

class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        auto distance_a2b = [&](int a, int b) -> int {
            int res = 0;
            int cur = a, n = distance.size();
            while (cur != b) {
                res += distance[cur];
                cur = (cur + 1) % n;
            }
            return res;
        };

        int d1 = distance_a2b(start, destination);
        int d2 = distance_a2b(destination, start);
        return min(d1, d2);
    }
};
