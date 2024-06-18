// https://leetcode.cn/problems/apply-discount-to-prices/

class Solution {
public:
    string discountPrices(string sentence, int discount) {
        string res = "";
        sentence += ' ';
        int start = 0;
        double k = 1 - double(discount) / 100;
        for (int i = 0; i < sentence.size(); ++i) {
            char ch = sentence[i];
            if (ch != ' ') continue;

            string word = sentence.substr(start, i-start);
            if (word[0] != '$' || !isNumber(word.substr(1, word.size()-1))) {
                res += word;
            }
            else {
                double value = k * stod(word.substr(1, word.size()-1));
                unsigned long long tmp = value * 100 + 0.5;
                string value_str = to_string(tmp);
                if (value_str.size() == 2) value_str = '0' + value_str;
                else if (value_str.size() == 1) value_str = "00" + value_str;
                value_str.insert(value_str.size()-2, ".");
                res += '$' + value_str;
            }
            res += ' ';
            start = i + 1;
        }
        return res.substr(0, res.size()-1);
    }

    bool isNumber(string s) {
        if (s.size() == 0) return false;
        for (char ch: s) {
            if (!isdigit(ch)) return false;
        }
        return true;
    }
};
