class Solution
{
public:
    vector<double> averageOfLevels(TreeNode *root)
    {
        if (!root)
            return {};
        vector<double> result = {};
        queue<TreeNode *> bfs({root});
        while (!bfs.empty())
        {
            const int size = bfs.size();
            double sum = 0.0;
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = bfs.front();
                bfs.pop();
                sum += cur->val;
                if (cur->left)
                    bfs.push(cur->left);
                if (cur->right)
                    bfs.push(cur->right);
            }
            result.emplace_back(sum / size);
        }
        return result;
    }
};
