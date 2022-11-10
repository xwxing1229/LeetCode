// https://leetcode.cn/problems/shortest-path-to-get-all-keys/

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        int pick_done = (1 << 6) - 1; // "111111"
        int id_cur = -1, pick_cur = pick_done;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                char ch = grid[i][j];
                if (ch == '@') {
                    id_cur = i * cols + j;
                }
                else if (isalpha(ch) && islower(ch)) {
                    // Each key is unique.
                    pick_cur = pick_cur ^ (1 << (ch - 'a'));
                }
            }
        }

        vector<pair<int,int>> directions = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        // BFS.
        vector<int> state_cur = {id_cur, pick_cur, 0};
        queue<vector<int>> q;
        q.push(state_cur);
        unordered_set<pair<int,int>, hashFunction> visited;
        visited.emplace(make_pair(id_cur, pick_cur));
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; ++i) {
                state_cur = q.front();
                q.pop();

                pick_cur = state_cur[1];
                if (pick_cur == pick_done) { // all keys are picked up
                    return state_cur[2];
                }

                pair<int,int> cur = {state_cur[0] / cols, state_cur[0] % cols};

                for (pair<int,int>& d: directions) {
                    pair<int,int> neigh = {cur.first+d.first, cur.second+d.second};
                    if ((neigh.first < 0) || (neigh.first >= rows) ||
                        (neigh.second < 0) || (neigh.second >= cols)) {
                        continue;
                    }
                    char ch = grid[neigh.first][neigh.second];
                    if (ch == '#') continue;
                    if (isalpha(ch) && isupper(ch)) {
                        if ((pick_cur >> (ch - 'A')) % 2 == 0) { // locked
                            continue;
                        }
                    }

                    int id_neigh = neigh.first * cols + neigh.second;
                    int pick_neigh = pick_cur;
                    if (isalpha(ch) && islower(ch)) { // pick up a key
                        pick_neigh = pick_neigh | (1 << (ch - 'a'));
                    }

                    if (visited.find(make_pair(id_neigh, pick_neigh)) != visited.end()) {
                        continue;
                    }
                    vector<int> state_neigh = {id_neigh, pick_neigh, state_cur[2]+1};
                    q.push(state_neigh);
                    visited.emplace(make_pair(id_neigh, pick_neigh));
                }
            }
        }
        return -1;
    }

private:
    struct hashFunction {
        size_t operator()(const pair<int,int>& p) const {
            return p.first ^ p.second;
        }
    };
};
