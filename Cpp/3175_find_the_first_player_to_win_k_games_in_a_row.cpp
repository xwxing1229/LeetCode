// https://leetcode.cn/problems/find-the-first-player-to-win-k-games-in-a-row/

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int win = 0;
        int cur = 0, i = 1, n = skills.size();
        while (win < k) {
            if (skills[cur] > skills[i]) {
                win += 1;
            }
            else {
                cur = i;
                win = 1;
            }
            i += 1;
            if (i == n) {
                return cur;
            }
        }
        return cur;
    }
};
