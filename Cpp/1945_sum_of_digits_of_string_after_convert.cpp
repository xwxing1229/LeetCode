// https://leetcode.cn/problems/sum-of-digits-of-string-after-convert/

class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> convert(s.size()+1, 0);
        for (int i = 0; i < s.size(); ++i) {
            convert[i] = s[i] - 'a' + 1;
        }
        int res = 0, n = convert.size();
        for (int t = 0; t < k; ++t) {
            res = 0;
            for (int i = 0; i < n; ++i) {
                int num = convert[i];
                while (num > 0) {
                    res += (num % 10);
                    num /= 10;
                }
            }
            n = 0;
            int tmp = res;
            while (tmp > 0) {
                convert[n] = tmp % 10;
                tmp /= 10;
                n += 1;
            }
        }
        return res;
    }
};
