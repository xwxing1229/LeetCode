// https://leetcode.cn/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int res = 0;
        int left = 0, right = 0;
        vector<int> cnt(26, 0);
        while (right < s.size()) {
            cnt[s[right] - 'A'] += 1;
            while (!isValid(cnt, k)) {
                cnt[s[left] - 'A'] -= 1;
                left += 1;
            }

            int tmp = right - left + 1;
            if (tmp > res) {
                res = tmp;
            }

            right += 1;
        }
        return res;
    }

    bool isValid(vector<int>& cnt, int k) {
        int max_cnt = 0, sum_cnt = 0;
        for (int i: cnt) {
            if (i > max_cnt) {
                max_cnt = i;
            }
            sum_cnt += i;
        }
        if (sum_cnt - max_cnt <= k) {
            return true;
        }
        else {
            return false;
        }
    }
};
