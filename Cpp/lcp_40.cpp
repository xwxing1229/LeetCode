// https://leetcode.cn/problems/uOAnQW/

class Solution {
public:
    int maxmiumScore(vector<int>& cards, int cnt) {
        sort(cards.rbegin(), cards.rend());
        int res = 0, even = -1, odd = -1;
        for (int i = 0; i < cnt; ++i) {
            int val = cards[i];
            res += val;
            if (val % 2 == 0) even = i;
            else odd = i;
        }
        if (res % 2 == 0) return res;

        int tmp1 = 0, tmp2 = 0;
        if (even >= 0) {
            for (int i = cnt; i < cards.size(); ++i) {
                if (cards[i] % 2 != 0) {
                    tmp1 = res - cards[even] + cards[i];
                    break;
                }
            }
        }
        if (odd >= 0) {
            for (int i = cnt; i < cards.size(); ++i) {
                if (cards[i] % 2 == 0) {
                    tmp2 = res - cards[odd] + cards[i];
                    break;
                }
            }
        }
        return max(tmp1, tmp2);
    }
};
