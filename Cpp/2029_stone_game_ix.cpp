// https://leetcode.cn/problems/stone-game-ix/

#include <vector>

using namespace std;

class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        vector<int> count(3, 0);
        for (int x: stones) count[x % 3] += 1;

        auto check = [&](vector<int> cnt) {
            if (cnt[1] == 0) return false;
            cnt[1] -= 1;
            int rounds = 1 + 2 * min(cnt[1], cnt[2])
                + (cnt[1] > cnt[2]) + cnt[0];
            return rounds < n && rounds % 2 == 1;
        };

        vector<int> count_switch = {count[0], count[2], count[1]};
        return check(count) || check(count_switch);
    }
};