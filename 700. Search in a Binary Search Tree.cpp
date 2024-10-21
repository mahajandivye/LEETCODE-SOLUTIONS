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
    void search(TreeNode* root , int val , TreeNode* &ans)
    {
        if(root == nullptr)return;
        if(root->val > val) search(root->left , val , ans);
        else if(root->val < val) search(root->right , val , ans);
        else
        {
            ans = root;
            return;
        }
    }
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = nullptr;
        search(root , val , ans);
        return ans;
    }
};