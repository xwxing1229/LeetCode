// https://leetcode.cn/problems/evaluate-division/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i = 0; i < equations.size(); ++i) {
            string num = equations[i][0], den = equations[i][1];
            if (table_eqs.find(num) == table_eqs.end()) {
                table_eqs[num] = (vector<string>) {den};
                table_vals[num] = (vector<double>) {values[i]};
            }
            else {
                table_eqs[num].push_back(den);
                table_vals[num].push_back(values[i]);
            }
            if (table_eqs.find(den) == table_eqs.end()) {
                table_eqs[den] = (vector<string>) {num};
                table_vals[den] = (vector<double>) {1. / values[i]};
            }
            else {
                table_eqs[den].push_back(num);
                table_vals[den].push_back(1. / values[i]);
            }
        }

        vector<double> res(queries.size());
        for (int i = 0; i < queries.size(); ++i) {
            string num = queries[i][0], den = queries[i][1];
            unordered_map<string, int> check;
            res[i] = calcOneEq(num, den, 1., check);
        }
        return res;
    }

private:
    double calcOneEq(string num, string den, double pre_quo, unordered_map<string, int>& check) {
        if ((table_eqs.find(num) == table_eqs.end()) || (table_eqs.find(den) == table_eqs.end())) {
            return -1.;
        }
        if (num == den) {
            return 1.;
        }

        vector<string> eqs = table_eqs[num];
        for (int i = 0; i < eqs.size(); ++i) {
            string cur_den = eqs[i];
            double cur_quo = table_vals[num][i];
            if (check.find(cur_den) != check.end()) {
                continue;
            }
            else if (cur_den == den) {
                return pre_quo * cur_quo;
            }
            else {
                check[num] = 1;
                double tmp = calcOneEq(cur_den, den, pre_quo*cur_quo, check);
                if (tmp > -0.5) {
                    return tmp;
                }
            }
        }
        return -1.;
    }

    unordered_map<string, vector<string>> table_eqs;
    unordered_map<string, vector<double>> table_vals;
};
