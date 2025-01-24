// https://leetcode.cn/problems/minimum-amount-of-time-to-collect-garbage/

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size(), res = 0;
        vector<int> ends(3, 0);
        for (int i = n-1; i >= 0; --i) {
            string g = garbage[i];
            int metal = count(g.begin(), g.end(), 'M');
            int paper = count(g.begin(), g.end(), 'P');
            int glass = count(g.begin(), g.end(), 'G');
            res += metal + paper + glass;
            if (ends[0] == 0 && metal > 0) ends[0] = i;
            if (ends[1] == 0 && paper > 0) ends[1] = i;
            if (ends[2] == 0 && glass > 0) ends[2] = i;
        }
        vector<int> cumtravel(n, 0);
        for (int i = 0; i < n-1; ++i) {
            cumtravel[i+1] = cumtravel[i] + travel[i];
        }
        for (int i = 0; i < 3; ++i) {
            res += cumtravel[ends[i]];
        }
        return res;
    }
};
