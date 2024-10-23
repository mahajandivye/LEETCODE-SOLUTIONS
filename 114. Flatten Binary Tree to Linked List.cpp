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
    void solve(TreeNode* root , vector<int>& store)
    {
        if(root == nullptr)return;
        store.push_back(root->val);
        solve(root->left , store);
        solve(root->right , store);
        return;
    }
    void flatten(TreeNode* root) {
        vector<int> store;
        solve(root , store);
        int n = store.size();
        if(root){
        TreeNode* newRoot = root;
        root->left = nullptr;
        root->right = nullptr;
        TreeNode* mover = newRoot;
        for(int i=1;i<n;i++)
        {
            TreeNode* newNode = new TreeNode(store[i]);
            mover->right = newNode;
            mover = newNode;
        }
        }
        return;
    }
};