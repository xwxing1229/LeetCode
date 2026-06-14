// https://leetcode.cn/problems/maximum-twin-sum-of-a-linked-list/

#include <vector>

using namespace std;

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> values;
        while (head != nullptr) {
            values.push_back(head->val);
            head = head->next;
        }
        int res = values[0] + values.back();
        int n = values.size();
        for (int i = 0; i < n/2; ++i) {
            res = max(res, values[i] + values[n-1-i]);
        }
        return res;
    }
};