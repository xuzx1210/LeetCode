class Solution
{
public:
    int findDepth(TreeNode *node)
    {
        return node ? max(findDepth(node->left), findDepth(node->right)) + 1 : 0;
    }
    vector<int> rightSideView(TreeNode *root)
    {
        queue<pair<TreeNode *, int>> bfs({{root, 0}});
        vector<int> result(findDepth(root));
        while (!bfs.empty())
        {
            TreeNode *cur = bfs.front().first;
            int depth = bfs.front().second;
            bfs.pop();
            if (!cur)
                continue;
            result[depth] = cur->val;
            bfs.push({cur->left, depth + 1});
            bfs.push({cur->right, depth + 1});
        }
        return result;
    }
};
