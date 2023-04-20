class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> bfs({{root, 0}});
        int result = -1;
        while (!bfs.empty())
        {
            int minimum = INT_MAX, maximum = 0;
            for (int size = bfs.size(); size; --size)
            {
                auto [cur, index] = bfs.front();
                bfs.pop();
                if (!cur)
                    continue;
                minimum = min(minimum, index);
                maximum = index;
                const int doubleIndex = (index - minimum) << 1;
                bfs.emplace(cur->left, doubleIndex);
                bfs.emplace(cur->right, doubleIndex + 1);
            }
            result = max(result, maximum - minimum);
        }
        return result + 1;
    }
};
