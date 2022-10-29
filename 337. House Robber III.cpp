class Solution
{
private:
    int dfs(TreeNode *node, int &l, int &r)
    {
        if (!node)
            return 0;
        int ll = 0, lr = 0, rl = 0, rr = 0;
        l = dfs(node->left, ll, lr);
        r = dfs(node->right, rl, rr);
        return max(node->val + ll + lr + rl + rr, l + r);
    }

public:
    int rob(TreeNode *root)
    {
        int l, r;
        return dfs(root, l, r);
    }
};
