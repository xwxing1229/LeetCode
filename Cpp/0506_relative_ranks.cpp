// https://leetcode.cn/problems/relative-ranks/

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> ranks(n);
        for (int i = 0; i < n; ++i) {
            ranks[i] = i;
        }
        sort(ranks.begin(), ranks.end(), [&](int i, int j) {
            return score[i] > score[j];
        });
        vector<string> res(n);
        for(int i = 0; i < n; ++i){
            if(i == 0) res[ranks[i]] = "Gold Medal";
            else if(i == 1) res[ranks[i]] = "Silver Medal";
            else if(i == 2) res[ranks[i]] = "Bronze Medal";
            else res[ranks[i]] = to_string(i+1);
        }
        return res;
    }
};
