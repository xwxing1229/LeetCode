// https://leetcode.cn/problems/simplify-path/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> sp = split(path, '/');
        vector<string> stack;
        for (string s: sp) {
            if ((s == ".") || (s == "")) {
                continue;
            }
            else if (s == "..") {
                if (stack.size() > 0) {
                    stack.pop_back();
                }
            }
            else {
                stack.push_back("/" + s);
            }
        }
        
        string res;
        for (string s: stack) {
            res = res + s;
        }
        if (res.size() == 0) {
            res = "/";
        }
        return res;
    }

private:
    vector<string> split(string s, char delimiter) {
        vector<string> res;
        string tmp;
        for (char c: s) {
            if (c == delimiter) {
                res.push_back(tmp);
                tmp.clear();
            }
            else {
                tmp = tmp + c;
            }
        }
        res.push_back(tmp);
        return res;
    }
};

int main() {
    Solution solu;
    string path = "/a/./b/../../c/";
    path = "/../";
    string res = solu.simplifyPath(path);
    cout << res << endl;
    return 0;
}