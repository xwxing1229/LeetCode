// https://leetcode.cn/problems/delete-nodes-and-return-forest/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        s_.insert(to_delete.begin(), to_delete.end());
        check(root, true);
        return res_;
    }

    TreeNode* check(TreeNode *node, bool is_root) {
        if (node == nullptr) {
            return nullptr;
        }
        bool del = false;
        if (s_.find(node->val) != s_.end()) {
            del = true;
        }
        node->left = check(node->left, del);
        node->right = check(node->right, del);

        if (del) {
            return nullptr;
        }
        else {
            if (is_root) {
                res_.push_back(node);
            }
            return node;
        }
    }

    unordered_set<int> s_;
    vector<TreeNode*> res_;
};
