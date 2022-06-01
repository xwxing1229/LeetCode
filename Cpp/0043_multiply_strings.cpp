// https://leetcode.cn/problems/multiply-strings/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.size(), n2 = num2.size();
        vector<int> mul(n1+n2, 0);

        for (int j = n2-1; j >= 0; --j) {
            int v2 = num2[j] - '0';
            int carry_local = 0, left_local = 0, tmp_local = 0;
            int carry_global = 0, tmp_global = 0;
            for (int i = n1-1; i >= 0; --i) {
                int v1 = num1[i] - '0';

                tmp_local = v2 * v1 + carry_local;
                carry_local = tmp_local / 10;
                left_local = tmp_local - carry_local * 10;

                tmp_global = mul[i+j+1] + left_local + carry_global;
                carry_global = tmp_global / 10;
                mul[i+j+1] = tmp_global - carry_global * 10;
            }

            mul[j] = carry_local + carry_global;
        }

        string res = "";
        int idx = n1 + n2;
        for (int k = 0; k < n1+n2; ++k) {
            if (mul[k] != 0) {
                idx = k;
                break;
            }
        }

        if (idx == n1 + n2) {
            res = "0";
        }
        else {
            for (int k = idx; k < n1 + n2; ++k) {
                res = res + to_string(mul[k]);
            }
        }

        return res;
    }
};

int main()
{
    Solution solu;
    string num1 = "123";
    string num2 = "456";

    cout << solu.multiply(num1, num2) << endl;
    
    return 0;
}