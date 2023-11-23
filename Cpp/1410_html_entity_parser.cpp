// https://leetcode.cn/problems/html-entity-parser/

class Solution {
public:
    string entityParser(string text) {
        unordered_map<string, string> table = {
            {"&quot;", "\""},
            {"&apos;", "\'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };
        string res = "";
        int start = 0, i = 0, n = text.size();
        bool added = true;
        while (i < n) {
            while (i < n && text[i] != '&') {
                i += 1;
            }
            res += text.substr(start, i-start);
            start = i;
            i += 1;
            added = false;
            while (i < n && i - start <= 7) {
                if (text[i] == '&') {
                    res += text.substr(start, i-start);
                    start = i;
                    added = true;
                    break;
                }
                string tmp = text.substr(start, i+1-start);
                if (table.find(tmp) != table.end()) {
                    res += table[tmp];
                    start = i + 1;
                    added = true;
                    break;
                }
                i += 1;
            }
        }
        if (!added && start < n) {
            res += text.substr(start, n-start);
        }
        return res;
    }
};