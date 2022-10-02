// https://leetcode.cn/problems/lexicographical-numbers/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n, 1);
        int num = 1;
        for (int i = 0; i < n; ++i) {
            res[i] = num;

            int tmp = num * 10;
            if (tmp <= n) {
                num = tmp;
            }
            else {
                while ((num % 10 == 9) || (num + 1 > n)) {
                    num = num / 10;
                }
                num = num + 1;
            }
        }
        return res;
    }
};