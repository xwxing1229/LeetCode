// https://leetcode.cn/problems/possible-bipartition/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        // people[i] = 1: first group
        // people[i] = 2: second group
        vector<int> people(n, 0);
        unordered_map<int, vector<int>> table;
        for (vector<int> dis: dislikes) {
            table[dis[0]-1].push_back(dis[1]-1);
            table[dis[1]-1].push_back(dis[0]-1);
        }
        for (int i = 0; i < n; ++i) {
            if (people[i] == 0) {
                bool tmp = dfs(people, table, i, 1);
                if (!tmp) return false;
            }
        }
        return true;
    }

private:
    bool dfs(vector<int>& people, unordered_map<int, vector<int>>& table,
        int person, int color) {
            people[person] = color;
            for (int i: table[person]) {
                if (people[i] == color) return false;
                else if (people[i] == 0) {
                    bool tmp = dfs(people, table, i, 3-color);
                    if (!tmp) return false;
                }
            }
            return true;
        }
};
