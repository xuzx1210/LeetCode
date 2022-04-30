class Solution
{
public:
    vector<int> rightSideView(TreeNode *root)
    {
        queue<TreeNode *> bfs({root});
        vector<int> result({});
        if (!root)
            return result;
        while (!bfs.empty())
        {
            int size = bfs.size();
            TreeNode *cur;
            for (int i = 0; i < size; ++i)
            {
                cur = bfs.front();
                bfs.pop();
                if (cur->left)
                    bfs.push(cur->left);
                if (cur->right)
                    bfs.push(cur->right);
            }
            result.push_back(cur->val);
        }
        return result;
    }
};
