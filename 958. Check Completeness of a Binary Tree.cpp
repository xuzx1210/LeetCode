class Solution
{
public:
    bool isCompleteTree(TreeNode *root)
    {
        queue<TreeNode *> bfs({root});
        while (!bfs.empty())
        {
            TreeNode *cur = bfs.front();
            bfs.pop();
            if (!cur)
                break;
            bfs.emplace(cur->left);
            bfs.emplace(cur->right);
        }
        while (!bfs.empty())
        {
            if (bfs.front())
                return false;
            bfs.pop();
        }
        return true;
    }
};
