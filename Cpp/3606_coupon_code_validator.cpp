// https://leetcode.cn/problems/coupon-code-validator/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        unordered_map<string, int> business_type = {
            {"electronics", 0},
            {"grocery", 1},
            {"pharmacy", 2},
            {"restaurant", 3}
        };
        vector<vector<string>> valid(4);
        for (int i = 0; i < code.size(); ++i) {
            if (!isActive[i] || business_type.find(businessLine[i]) == business_type.end()) continue;
            if (isValid(code[i])) {
                valid[business_type[businessLine[i]]].push_back(code[i]);
            }
        }
        vector<string> res;
        for (auto &val: valid) {
            sort(val.begin(), val.end());
            res.insert(res.end(), val.begin(), val.end());
        }
        return res;
    }

    bool isValid(const std::string &code) {
        if (code.empty()) return false;
        for (char ch: code) {
            if (ch != '_' && !isalnum(ch)) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<string> code = {"SAVE20", "", "PHARMA5", "SAVE@20"};
    vector<string> businessLine = {"restaurant", "grocery", "pharmacy", "restaurant"};
    vector<bool> isActive = {true, true, true, true};
    vector<string> res = sol.validateCoupons(code, businessLine, isActive);
    for (const auto &c: res) cout << c << ", ";
    cout << '\n';
    return 0;
}