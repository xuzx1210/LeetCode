class Solution
{
public:
    bool dfs(TreeNode *p, TreeNode *q)
    {
        if (p->val != q->val)
            return false;
        if (p->left)
            if (q->left)
            {
                if (!dfs(p->left, q->left))
                    return false;
            }
            else
                return false;
        else if (q->left)
            return false;
        if (p->right)
            if (q->right)
            {
                if (!dfs(p->right, q->right))
                    return false;
            }
            else
                return false;
        else if (q->right)
            return false;
        return true;
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p)
            if (q)
                return dfs(p, q);
            else
                return false;
        else
        {
            if (q)
                return false;
            else
                return true;
        }
    }
};
