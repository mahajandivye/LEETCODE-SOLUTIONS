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
    TreeNode* getFloor(TreeNode* root , int val)
    {
        TreeNode* ans = nullptr;
        while(root)
        {
            if(root->val > val) root = root->left;
            else if(root->val < val)
            {
                ans = root;
                root = root->right;
            } 
            else if(root->val == val) return root;
        }
        return ans;
    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* newNode = new TreeNode(val);
        if(!root)return newNode;
        TreeNode* floor = getFloor(root , val);
        if(floor)
        {
        TreeNode* tempRight = floor->right;
        
        floor->right = newNode;
        newNode->right = tempRight;
        newNode->left = nullptr;
        }
        else if(!floor)
        {
            TreeNode* temp = root;
            while(temp->left)
            {
                temp = temp->left;
            }
            temp->left = newNode;
        }
        return root;
    }
};