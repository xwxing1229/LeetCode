// https://leetcode.cn/problems/k-th-symbol-in-grammar/

class Solution {
public:
    int kthGrammar(int n, int k) {
        if (n == 1) {
            return 0;
        }

        int tmp = (1 << (n-2));
        if (k <= tmp) {
            return kthGrammar(n-1, k);
        }
        else {
            return 1 - kthGrammar(n-1, k-tmp);
        }
    }
};
