// https://leetcode.cn/problems/card-flipping-game/

class Solution {
public:
    int flipgame(vector<int>& fronts, vector<int>& backs) {
        vector<int> idxs(fronts.size());
        iota(idxs.begin(), idxs.end(), 0);
        // Place the cards that front == back to the first segment of the vector.
        sort(idxs.begin(), idxs.end(), [&](int i, int j) {
            return (fronts[i] == backs[i] && fronts[j] != backs[j]) ||
                    (fronts[i] != backs[i] && fronts[j] != backs[j] &&
                        min(fronts[i], backs[i]) < min(fronts[j], backs[j]));
        });
        
        int res = 2001;
        unordered_set<int> forbid;
        for (int i: idxs) {
            if (fronts[i] == backs[i]) {
                forbid.insert(fronts[i]);
            }
            else {
                if (res > fronts[i] && forbid.find(fronts[i]) == forbid.end()) {
                    res = fronts[i];
                }
                if (res > backs[i] && forbid.find(backs[i]) == forbid.end()) {
                    res = backs[i];
                }
            }
        }
        if (res == 2001) {
            res = 0;
        }
        return res;
    }
};
