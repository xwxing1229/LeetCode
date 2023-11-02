// https://leetcode.cn/problems/rings-and-rods/

class Solution {
public:
    int countPoints(string rings) {
        vector<vector<int>> rods(10, vector<int>(3,0));
        for (int i = 0; i < rings.size(); i+=2) {
            int rod = rings[i+1] - '0';
            if (rings[i] == 'R') rods[rod][0] = 1;
            else if (rings[i] == 'G') rods[rod][1] = 1;
            else rods[rod][2] = 1;
        }
        int res = 0;
        for (auto &r: rods) {
            if (r[0] + r[1] + r[2] == 3) res += 1;
        }
        return res;
    }
};