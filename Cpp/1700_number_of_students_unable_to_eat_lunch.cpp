// https://leetcode.cn/problems/number-of-students-unable-to-eat-lunch/

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int eat0 = 0, eat1 = 0;
        for (int i: students) {
            if (i == 0) {
                eat0 += 1;
            }
            else {
                eat1 += 1;
            }
        }
        for (int sand: sandwiches) {
            if ((sand == 0) && (eat0 > 0)) {
                eat0 -= 1;
            }
            else if ((sand == 1) && (eat1 > 0)) {
                eat1 -= 1;
            }
            else {
                break;
            }
        }
        return eat0 + eat1;
    }
};
