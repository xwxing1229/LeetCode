// https://leetcode.cn/problems/maximum-fruits-harvested-after-at-most-k-steps/

class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        leftpos = fruits[0][0];
        rightpos = fruits.back()[0];
        int n = rightpos - leftpos + 1;
        cumsum.resize(n+1, 0);
        int idx = 0;
        for (int i = 0; i < n; ++i) {
            if (i + leftpos == fruits[idx][0]) {
                cumsum[i+1] = cumsum[i] + fruits[idx][1];
                idx += 1;
            }
            else {
                cumsum[i+1] = cumsum[i];
            }
        }

        int startCnt = 0;
        int l = 0, r = fruits.size()-1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (fruits[m][0] == startPos) {
                startCnt = fruits[m][1];
                break;
            }
            else if (fruits[m][0] < startPos) l = m + 1;
            else r = m - 1;
        }

        int res = max(firstLeftThenRight(startPos, k, startCnt),
                      firstRightThenLeft(startPos, k, startCnt));
        return res;
    }

    int firstLeftThenRight(int startPos, int k, int startCnt) {
        int res = startCnt;
        for (int i = 1; i <= k; ++i) {
            int left = startPos - i - leftpos;
            left = max(left, 0);
            int right = max(startPos, startPos-i+k-i) - leftpos;
            right = min(right, rightpos-leftpos);
            if (left >= cumsum.size() || right < 0) {
                continue;
            }
            res = max(res, cumsum[right+1] - cumsum[left]);
        }
        return res;
    }

    int firstRightThenLeft(int startPos, int k, int startCnt) {
        int res = startCnt;
        for (int i = 1; i <= k; ++i) {
            int right = startPos + i - leftpos;
            right = min(right, rightpos-leftpos);
            int left = min(startPos, startPos+i-k+i) - leftpos;
            left = max(left, 0);
            if (left >= cumsum.size() || right < 0) {
                continue;
            }
            res = max(res, cumsum[right+1] - cumsum[left]);
        }
        return res;
    }

    int leftpos, rightpos;
    vector<int> cumsum;
};
