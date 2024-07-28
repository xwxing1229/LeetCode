// https://leetcode.cn/problems/relocate-marbles/
        
class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = 0; i < moveFrom.size(); ++i) {
            s.erase(moveFrom[i]);
            s.insert(moveTo[i]);
        }
        vector<int> res;
        res.insert(res.end(), s.begin(), s.end());
        sort(res.begin(), res.end());
        return res;
    }
};
