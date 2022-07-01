// https://leetcode.cn/problems/fraction-to-recurring-decimal/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string res = "";
        long numerator_ = (long) numerator, denominator_ = (long) denominator;
        if ((numerator_ > 0) && (denominator_ < 0)) {
            res = res + '-';
            denominator_ = -denominator_;
        }
        else if ((numerator_ < 0) && (denominator_ > 0)) {
            res = res + '-';
            numerator_ = -numerator_;
        }

        long quo = numerator_ / denominator_;
        long rem = numerator_ - denominator_ * quo;
        res = res + to_string(quo);

        if (rem == 0) {
            return res;
        }

        res = res + '.';
        int start_idx = res.size();
        unordered_map<long, int> record;
        long tmp;
        int idx = 0;
        while (true) {
            tmp = rem * 10;
            quo = tmp / denominator_;
            rem = tmp - denominator_ * quo;

            if (rem == 0) {
                res = res + to_string(quo);
                return res;
            }

            if (record.find(tmp) == record.end()) {
                res = res + to_string(quo);
                record[tmp] = idx;
                idx = idx + 1;
            }
            else {
                break;
            }
        }
        res = res.insert(start_idx+record[tmp], 1, '(');
        res.push_back(')');
        return res;
    }
};
