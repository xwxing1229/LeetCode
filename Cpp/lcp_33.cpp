// https://leetcode.cn/problems/o8SXZn/

class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int k_max = *max_element(vat.begin(), vat.end());
        if (k_max == 0) {
            return 0;
        }

        int res = INT_MAX;
        for (int k = 1; k <= k_max; ++k) {
            int t = 0;
            for (int i = 0; i < bucket.size(); ++i) {
                t += max(0, (vat[i]+k-1)/k - bucket[i]);
            }
            res = min(res, k+t);
            if (k >= res) {
                break;
            }
        }
        return res;
    }
};