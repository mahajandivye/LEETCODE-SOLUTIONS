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
    void solve(TreeNode* root , vector<int> &store)
    {
        if(root == nullptr)return;
        solve(root->left , store);
        store.push_back(root->val);
        solve(root->right , store);
        return;
    }
    bool isValidBST(TreeNode* root) {
        vector<int> store;
        solve(root , store);
        int n = store.size();
        for(int i=0;i<n;i++)
        {
            if(i < n-1 && store[i] >= store[i+1])return false;
        }
        return true;
    }
};