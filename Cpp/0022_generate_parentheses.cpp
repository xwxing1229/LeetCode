// https://leetcode.cn/problems/generate-parentheses/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        set<string> res = {"()"};
        int k = 1;
        while (k < n) {
            set<string> res_k;
            for (auto it = res.begin(); it != res.end(); ++it) {
                string cand = *it;
                for (int i = 0; i < cand.size(); ++i) {
                    string cand_i = cand;
                    cand_i.insert(i, 1, '(');

                    for (int j = 1; j < cand_i.size()+1; ++j) {
                        string cand_ij = cand_i;
                        cand_ij.insert(j, 1, ')');

                        if (isValid(cand_ij)) {
                            res_k.insert(cand_ij);
                        }
                    }
                }
            }
            
            res = res_k;
            k = k + 1;
        }
        
        vector<string> res_vec(res.begin(), res.end());
        return res_vec;
    }
    
    bool isValid(string s) {
        int count = 0;
        for (char c: s) {
            if (c == '(') count = count + 1;
            else if (count > 0) count = count - 1;
            else return false;
        }
        return true;
    }
};