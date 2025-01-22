// https://leetcode.cn/problems/reward-top-k-students/

class Solution {
public:
    vector<int> topStudents(vector<string>& positive_feedback, vector<string>& negative_feedback, vector<string>& report, vector<int>& student_id, int k) {
        unordered_set<string> posset(positive_feedback.begin(), positive_feedback.end());
        unordered_set<string> negset(negative_feedback.begin(), negative_feedback.end());
        int n = student_id.size();
        vector<pair<int,int>> scores(n);
        for (int i = 0; i < n; ++i) {
            int score = 0;
            string rep = report[i];
            int j = 0, k = 0, l = rep.size();
            while (k < l) {
                while (k < l-1 && rep[k+1] != ' ') {
                    k += 1;
                }
                string feedback = rep.substr(j, k-j+1);
                if (posset.find(feedback) != posset.end()) score += 3;
                else if (negset.find(feedback) != negset.end()) score -= 1;
                k += 2;
                j = k;
            }
            scores[i] = make_pair(student_id[i], score);
        }
        sort(scores.begin(), scores.end(), [](const pair<int,int> p1, const pair<int,int> p2) {
            return p1.second > p2.second || (p1.second == p2.second && p1.first < p2.first);
        });
        vector<int> res(k);
        for (int i = 0; i < k; ++i) {
            res[i] = scores[i].first;
        }
        return res;
    }
};
