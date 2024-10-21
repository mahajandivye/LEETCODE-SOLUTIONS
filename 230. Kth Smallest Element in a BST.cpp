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
    void insert(TreeNode* root , int k , priority_queue<int , vector<int> , greater<int>> &pq)
    {
        if(root == nullptr)return;
        pq.push(root->val);
        insert(root->left , k , pq);
        insert(root->right , k , pq);
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int , vector<int> , greater<int>> pq;
        insert(root , k , pq);
        int cnt = 0;
        while(!pq.empty())
        {
            cnt++;
            if(cnt == k)return pq.top();
            pq.pop();
        }
        return -1;
    }
};