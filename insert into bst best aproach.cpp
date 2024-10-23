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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* x = root;
        TreeNode* y = nullptr;
        while(x)
        {
            y = x;
            if(y->val > val) x = x->left;
            else if(y->val < val) x= x->right;
        }
        TreeNode* newNode = new TreeNode(val);
        if(y == nullptr) return newNode;
        else if(y->val > val) y->left = newNode;
        else y->right = newNode;
        return root;
    }
};