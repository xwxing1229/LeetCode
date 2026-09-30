// https://leetcode.cn/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        vector<int> res(seq.size(), 0);
        vector<int> cnt(2, 0);
        for (int i = 0; i < seq.size(); ++i) {
            if (seq[i] == '(') {
                if (cnt[0] <= cnt[1]) {
                    cnt[0] += 1;
                }
                else {
                    res[i] = 1;
                    cnt[1] += 1;
                }
            }
            else {
                if (cnt[0] > cnt[1]) {
                    cnt[0] -= 1;
                }
                else {
                    res[i] = 1;
                    cnt[1] -= 1;
                }
            }
        }
        return res;
    }
};