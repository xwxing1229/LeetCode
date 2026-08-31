// https://leetcode.cn/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> extreme;
        int val_prev = head->val;
        ListNode *curr = head->next;
        int idx = 1;
        while (curr->next != nullptr) {
            int val_curr = curr->val;
            int val_next = curr->next->val;
            if (
                (val_curr < val_prev && val_curr < val_next)
                || (val_curr > val_prev && val_curr > val_next)
            ) {
                extreme.push_back(idx);
            }
            val_prev = val_curr;
            curr = curr->next;
            idx += 1;
        }
        if (extreme.size() < 2) return {-1, -1};
        vector<int> res = {
            extreme[1] - extreme[0],
            extreme.back() - extreme[0]
        };
        for (int i = 1; i < extreme.size(); ++i) {
            res[0] = min(res[0], extreme[i] - extreme[i-1]);
        }
        return res;
    }
};