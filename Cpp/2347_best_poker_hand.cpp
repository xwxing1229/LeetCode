// https://leetcode.cn/problems/best-poker-hand/

class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        unordered_map<char, int> cnt_suits;
        for (char ch: suits) {
            cnt_suits[ch] += 1;
            if (cnt_suits[ch] == 5) return "Flush";
        }
        unordered_map<int, int> cnt_ranks;
        bool find_pair = false;
        for (int rank: ranks) {
            cnt_ranks[rank] += 1;
            if (cnt_ranks[rank] == 2) find_pair = true;
            else if (cnt_ranks[rank] == 3) return "Three of a Kind";
        }
        if (find_pair) return "Pair";
        else return "High Card";
    }
};
