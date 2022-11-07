// https://leetcode.cn/problems/ambiguous-coordinates/

class Solution {
public:
    vector<string> ambiguousCoordinates(string s) {
        vector<string> res;
        int n = s.size();
        for (int i = 1; i < n-2; ++i) {
            string sub1 = s.substr(1, i), sub2 = s.substr(i+1, n-2-i);
            int n1 = sub1.size(), n2 = sub2.size();
            for (int i1 = 1; i1 <= n1; ++i1) { // x in coordinate (x,y)
                string sub1_int = sub1.substr(0, i1);
                if (!isValid(sub1_int, true)) continue;

                string sub1_frac = sub1.substr(i1, n1-i1);
                if ((i1 < n1) && (!isValid(sub1_frac, false))) continue;
                
                string coord_x = sub1_int;
                if (i1 < n1) {
                    coord_x += ("." + sub1_frac);
                }
                for (int i2 = 1; i2 <= n2; ++i2) { // y in coordinate (x,y)
                    string sub2_int = sub2.substr(0, i2);
                    if (!isValid(sub2_int, true)) continue;

                    string sub2_frac = sub2.substr(i2, n2-i2);
                    if ((i2 < n2) && (!isValid(sub2_frac, false))) continue;
                    
                    string coord_y = sub2_int;
                    if (i2 < n2) {
                        coord_y += ("." + sub2_frac);
                    }

                    res.push_back("(" + coord_x + ", " + coord_y + ")");
                }
            }
        }
        return res;
    }

    bool isValid(string cur, bool isInt) {
        if (isInt) { // integer part
            if ((cur.size() > 1) && (cur[0] == '0')) return false;
        }
        else { // fraction part
            if (cur.back() == '0') return false;
        }
        return true;
    }
};
