// https://leetcode.cn/problems/number-of-burgers-with-no-waste-of-ingredients/

class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
        int x = (tomatoSlices - 2 * cheeseSlices) / 2;
        int y = (4 * cheeseSlices - tomatoSlices) / 2;
        vector<int> res;
        if (x >= 0 & y >= 0 & 4*x+2*y == tomatoSlices & x+y == cheeseSlices) {
            res.push_back(x);
            res.push_back(y);
        }
        return res;
    }
};
