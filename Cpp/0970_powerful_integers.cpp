// https://leetcode.cn/problems/powerful-integers/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> powx = {1}, powy = {1};
        bool endx = false, endy = false;
        while (!(endx && endy)) {
            if (x > 1 && powx.back() <= bound / x) {
                powx.push_back(powx.back() * x);
            }
            else {
                endx = true;
            }
            if (y > 1 && powy.back() <= bound / y) {
                powy.push_back(powy.back() * y);
            }
            else {
                endy = true;
            }
        }

        unordered_set<int> s;
        for (int i: powx) {
            for (int j: powy) {
                if (i <= bound - j) {
                    s.emplace(i + j);
                }
            }
        }
        vector<int> res;
        res.insert(res.end(), s.begin(), s.end());
        return res;
    }
};
