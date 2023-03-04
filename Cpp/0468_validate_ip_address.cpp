// https://leetcode.cn/problems/validate-ip-address/

class Solution {
public:
    string validIPAddress(string queryIP) {
        if (queryIP.size() < 5) return "Neither";

        for (int i = 0; i < 5; ++i) {
            if (queryIP[i] == '.') {
                return check_ipv4(split(queryIP, '.'));
            }
            else if (queryIP[i] == ':') {
                return check_ipv6(split(queryIP, ':'));
            }
        }
        return "Neither";
    }

    vector<string> split(string queryIP, char deli) {
        vector<string> res;
        string tmp;
        for (int i = 0; i < queryIP.size(); ++i) {
            char ch = queryIP[i];
            if (ch == deli) {
                res.push_back(tmp);
                tmp.clear();
            }
            else {
                tmp += ch;
            }
        }
        res.push_back(tmp);
        return res;
    }

    string check_ipv4(vector<string> address) {
        if (address.size() != 4) return "Neither";
        for (auto &ad: address) {
            if (ad.size() < 1 || ad.size() > 4) return "Neither";
            int val = 0;
            for (int i = 0; i < ad.size(); ++i) {
                char ch = ad[i];
                if (!isdigit(ch)) return "Neither";
                val = val * 10 + ch - '0';
            }
            if ((ad[0] == '0' && ad.size() > 1) || val > 255) return "Neither";
        }
        return "IPv4";
    }

    string check_ipv6(vector<string> address) {
        if (address.size() != 8) return "Neither";
        unordered_set<char> check = {
            '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
            'a', 'b', 'c', 'd', 'e', 'f',
            'A', 'B', 'C', 'D', 'E', 'F'
        };
        for (auto &ad: address) {
            if (ad.size() < 1 || ad.size() > 4) return "Neither";
            for (auto ch: ad) {
                if (check.find(ch) == check.end()) return "Neither";
            }
        }
        return "IPv6";
    }
};
