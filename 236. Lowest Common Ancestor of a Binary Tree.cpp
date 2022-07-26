class Solution
{
private:
    bool findNode(TreeNode *cur, TreeNode *target, vector<TreeNode *> &path)
    {
        if (!cur)
            return false;
        path.push_back(cur);
        if (cur == target)
            return true;
        if (findNode(cur->left, target, path))
            return true;
        if (findNode(cur->right, target, path))
            return true;
        path.pop_back();
        return false;
    }

public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> pPath = {}, qPath = {};
        bool ok = false;
        findNode(root, p, pPath);
        findNode(root, q, qPath);
        int minSize = min(pPath.size(), qPath.size());
        for (int i = 0; i < minSize; ++i)
            if (pPath[i] != qPath[i])
                return pPath[i - 1];
        return pPath[minSize - 1];
    }
};
