// https://leetcode.cn/problems/decode-string/

class Solution {
public:
    string decodeString(string s) {
        vector<pair<int,int>> stack_nums;
        string num;
        vector<string> stack_encodes;
        string tmp, encode;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            char ch = s[i];
            if (ch == '[') {
                stack_nums.push_back(make_pair(stoi(num), stack_encodes.size()));
                num.clear();
            }
            else if (ch == ']') {
                pair<int,int> record = stack_nums.back();
                stack_nums.pop_back();

                int n_encodes = stack_encodes.size();
                for (int j = record.second; j < n_encodes; ++j) {
                    tmp = stack_encodes.back() + tmp;
                    stack_encodes.pop_back();
                }
                tmp = tmp + encode;
                encode = tmp;
                for (int j = 1; j < record.first; ++j) {
                    tmp = tmp + encode;
                }
                stack_encodes.push_back(tmp);
                tmp.clear();
                encode.clear();
            }
            else if (isdigit(ch)) {
                if ((i > 0) && (isalpha(s[i-1]))) {
                    stack_encodes.push_back(encode);
                    encode.clear();
                }
                num = num + ch;
            }
            else {
                encode = encode + ch;
            }
        }
        
        string res;
        for (string str: stack_encodes) {
            res = res + str;
        }
        res = res + encode;
        return res;
    }
};
