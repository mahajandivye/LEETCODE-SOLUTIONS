
void solve(Node* root , int input , int &ans)
{
    if(root == nullptr)return;
    if(root->data > input)
    {
        ans = root->data;
        solve(root->left , input , ans);
    }
    else if(root->data < input) solve(root->right , input , ans);
    else if(root->data == input)
    {
        ans = input;
        return;
    }
}

int findCeil(Node* root, int input) {
    if (root == NULL) return -1;
    int ans = -1;
    // Your code heres
    solve(root , input , ans);
    return ans;
    
}