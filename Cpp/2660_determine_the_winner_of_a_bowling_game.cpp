// https://leetcode.cn/problems/determine-the-winner-of-a-bowling-game/

class Solution {
public:
    int isWinner(vector<int>& player1, vector<int>& player2) {
        int score1 = checkPoints(player1), score2 = checkPoints(player2);
        if (score1 > score2) return 1;
        else if (score1 < score2) return 2;
        else return 0;
    }
    
    int checkPoints(vector<int> &player) {
        int n = player.size();
        if (n == 1) return player[0];
        else {
            int res = player[0] + player[1];
            if (player[0] == 10) {
                res += player[1];
            }
            for (int i = 2; i < n; ++i) {
                res += player[i];
                if (player[i-2] == 10 || player[i-1] == 10) {
                    res += player[i];
                }
            }
            return res;
        }
    }
};
