// https://leetcode.cn/problems/letter-tile-possibilities/

class Solution {
public:
    int numTilePossibilities(string tiles) {
        res = 0;
        vector<int> used(tiles.size(), 0);
        for (int len = 1; len <= tiles.size(); ++len) {
            dfs(tiles, "", used, len);
        }
        return res;
    }

    void dfs(string tiles, string cur, vector<int> &used, int len) {
        if (cur.size() == len) {
            if (check.find(cur) == check.end()) {
                res += 1;
                check.insert(cur);
            }
            return;
        }
        for (int i = 0; i < tiles.size(); ++i) {
            if (used[i]) continue;
            used[i] = 1;
            dfs(tiles, cur+tiles[i], used, len);
            used[i] = 0;
        }
    }

    int res;
    unordered_set<string> check;
};
