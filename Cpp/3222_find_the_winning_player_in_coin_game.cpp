// https://leetcode.cn/problems/find-the-winning-player-in-coin-game/

class Solution {
public:
    string losingPlayer(int x, int y) {
        int cnt = min(x, y/4);
        string res = "Alice";
        if (cnt % 2 == 0) {
            res = "Bob";
        }
        return res;
    }
};

