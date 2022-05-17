class Solution
{
private:
    vector<bool> path;
    bool dfs(TreeNode *node, TreeNode *target)
    {
        if (node == target)
            return true;
        if (!node)
            return false;
        path.push_back(false);
        if (dfs(node->left, target))
            return true;
        path.back() = true;
        if (dfs(node->right, target))
            return true;
        path.pop_back();
        return false;
    }

public:
    TreeNode *getTargetCopy(TreeNode *original, TreeNode *cloned, TreeNode *target)
    {
        path.clear();
        dfs(original, target);
        TreeNode *result = cloned;
        for (bool direction : path)
            result = direction ? result->right : result->left;
        return result;
    }
};
