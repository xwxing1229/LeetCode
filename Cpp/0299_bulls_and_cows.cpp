// https://leetcode.cn/problems/bulls-and-cows/

class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int> cnt_secret(10,0), cnt_guess(10,0);
        int bull = 0, cow = 0;
        for (int i = 0; i < secret.size(); ++i) {
            char ch_secret = secret[i], ch_guess = guess[i];
            if (ch_secret == ch_guess) {
                bull = bull + 1;
            }
            else {
                cnt_secret[ch_secret-'0'] = cnt_secret[ch_secret-'0'] + 1;
                cnt_guess[ch_guess-'0'] = cnt_guess[ch_guess-'0'] + 1;
            }
        }
        for (int i = 0; i < 10; ++i) {
            cow = cow + min(cnt_secret[i], cnt_guess[i]);
        }
        string res = to_string(bull) + 'A' + to_string(cow) + 'B';
        return res;
    }
};
