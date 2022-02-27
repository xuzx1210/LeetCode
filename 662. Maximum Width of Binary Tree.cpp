class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<pair<TreeNode *, unsigned long long int>> bfs;
        while (!bfs.empty())
            bfs.pop();
        bfs.push({root, 0});
        int result = 0;
        while (!bfs.empty())
        {
            int start = bfs.front().second, end = bfs.back().second;
            result = max(result, end - start + 0);
            int size = bfs.size();
            for (int i = 0; i < size; ++i)
            {
                TreeNode *cur = bfs.front().first;
                int index = bfs.front().second - start;
                bfs.pop();
                if (cur->left)
                    bfs.push({cur->left, (index << 1) + 1});
                if (cur->right)
                    bfs.push({cur->right, (index << 1) + 2});
            }
        }
        return result + 1;
    }
};
