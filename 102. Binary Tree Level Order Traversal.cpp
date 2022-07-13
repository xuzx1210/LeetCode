class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> bfs({root});
        vector<vector<int>> result = {};
        while (!bfs.empty())
        {
            int size = bfs.size();
            vector<int> level = {};
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = bfs.front();
                bfs.pop();
                if (!cur)
                    continue;
                level.push_back(cur->val);
                bfs.push(cur->left);
                bfs.push(cur->right);
            }
            if (!level.empty())
                result.push_back(level);
        }
        return result;
    }
};
