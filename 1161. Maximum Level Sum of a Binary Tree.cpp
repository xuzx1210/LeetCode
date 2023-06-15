class Solution
{
public:
    int maxLevelSum(TreeNode *root)
    {
        int maximum = INT_MIN, result = 1;
        queue<TreeNode *> bfs({root});
        for (int level = 1; !bfs.empty(); ++level)
        {
            bool hasNode = false;
            int sum = 0;
            for (int size = bfs.size(); size; --size)
            {
                TreeNode *cur = bfs.front();
                bfs.pop();
                if (!cur)
                    continue;
                hasNode = true;
                sum += cur->val;
                bfs.emplace(cur->left);
                bfs.emplace(cur->right);
            }
            if (hasNode && maximum < sum)
            {
                maximum = sum;
                result = level;
            }
        }
        return result;
    }
};
