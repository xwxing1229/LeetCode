// https://leetcode.cn/problems/fizz-buzz/

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> res(n);
        for (int i = 0; i < n; ++i) {
            int val = i + 1;
            if (val % 3 == 0) {
                if (val % 5 == 0) {
                    res[i] = "FizzBuzz";
                }
                else {
                    res[i] = "Fizz";
                }
            }
            else if (val % 5 == 0) {
                res[i] = "Buzz";
            }
            else {
                res[i] = to_string(val);
            }
        }
        return res;
    }
};
