// https://leetcode.cn/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        // // Time complexity: O(n*log(n)), space complexity: O(n*log(n)).
        // sort(citations.begin(), citations.end());
        // int n = citations.size();
        // int res = 0;
        // for (int i = 0; i < n; ++i) {
        //     if (n - i <= citations[i]) {
        //         res = n - i;
        //         break;
        //     }
        // }
        // return res;

        // Time complexity: O(n), space complexity: O(n).
        int n = citations.size();
        vector<int> counts(n+1, 0);
        for (int cita: citations) {
            if (cita >= n) {
                counts[n] = counts[n] + 1;
            }
            else {
                counts[cita] = counts[cita] + 1;
            }
        }

        int cnt = 0, res = 0;
        for (int i = n; i >= 0; --i) {
            cnt = cnt + counts[i];
            if (cnt >= i) {
                res = i;
                break;
            }
        }
        return res;
    }
};
