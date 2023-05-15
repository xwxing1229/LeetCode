// https://leetcode.cn/problems/distant-barcodes/

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int, int> cnt;
        for (int code: barcodes) cnt[code] += 1;
        sort(barcodes.begin(), barcodes.end(), [&](int c1, int c2) {
            return cnt[c1] > cnt[c2] || (cnt[c1] == cnt[c2] && c1 < c2);
        });
        int left = 0, n = barcodes.size();
        vector<int> res(n);
        for (int i = 0; i < n; i=i+2) {
            res[i] = barcodes[left];
            left += 1;
        }
        for (int i = 1; i < n; i=i+2) {
            res[i] = barcodes[left];
            left += 1;
        }
        return res;
    }
};