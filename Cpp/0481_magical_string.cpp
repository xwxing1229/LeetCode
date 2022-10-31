// https://leetcode.cn/problems/magical-string/

class Solution {
public:
    int magicalString(int n) {
        string magi(n, '1');
        magi[1] = '2';
        int res = 1, idx = 1, cnt = 1;
        for (int i = 2; i < n; ++i) {
            char pre = magi[i-1], cur;
            if (magi[idx] == '1') {
                cur = '0' + 3 - (pre - '0');
                idx += 1;
                cnt = 0;
            }
            else {
                if (cnt == 0) {
                    cur = '0' + 3 - (pre - '0');
                    cnt += 1;
                }
                else {
                    cur = pre;
                    idx += 1;
                    cnt = 0;
                }
            }
            magi[i] = cur;
            
            if (cur == '1') {
                res += 1;
            }
        }
        return res;
    }
};
