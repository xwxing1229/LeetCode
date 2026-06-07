// https://leetcode.cn/problems/create-binary-tree-from-descriptions/

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

#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        for (const auto &d: descriptions) {
            int parent = d[0], child = d[1], isleft = d[2];
            if (!nodes.count(parent)) nodes[parent] = new TreeNode(parent);
            if (!nodes.count(child)) nodes[child] = new TreeNode(child);
            
            if (isleft) nodes[parent]->left = nodes[child];
            else nodes[parent]->right = nodes[child];
            
            children.insert(child);
        }
        for (const auto &[val, node]: nodes) {
            if (!children.count(val)) return node;
        }
        return new TreeNode(-1);
    }
};