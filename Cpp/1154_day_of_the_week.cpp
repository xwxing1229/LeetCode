// https://leetcode.cn/problems/day-of-the-year/

class Solution {
public:
    int dayOfYear(string date) {
        vector<int> days = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int yy = stoi(date.substr(0, 4));
        int mm = stoi(date.substr(5, 2));
        int dd = stoi(date.substr(8, 2));
        int res = dd;
        for (int i = 0; i < mm-1; ++i) {
            res += days[i];
        }
        if ((yy % 400 == 0 || (yy % 4 == 0 && yy % 100 != 0)) && mm > 2) {
            res += 1;
        }
        return res;
    }
};
