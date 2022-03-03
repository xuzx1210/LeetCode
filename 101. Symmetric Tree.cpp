class Solution
{
public:
    bool dfs(TreeNode *a, TreeNode *b)
    {
        if (a->val != b->val)
            return false;
        if (a->left)
        {
            if (b->right)
            {
                if (!dfs(a->left, b->right))
                    return false;
            }
            else
                return false;
        }
        else if (b->right)
            return false;
        if (a->right)
        {
            if (b->left)
            {
                if (!dfs(a->right, b->left))
                    return false;
            }
            else
                return false;
        }
        else if (b->left)
            return false;
        return true;
    }
    bool isSymmetric(TreeNode *root)
    {
        if (root == nullptr)
            return true;
        if (root->left)
        {
            if (root->right)
                return dfs(root->left, root->right);
            else
                return false;
        }
        else
        {
            if (root->right)
                return false;
            else
                return true;
        }
    }
};
