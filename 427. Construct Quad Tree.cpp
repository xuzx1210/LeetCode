class Solution
{
private:
    Node *dfs(const vector<vector<int>> &grid, const int x, const int y, const int n)
    {
        if (n == 1)
            return new Node(grid[x][y], true);
        const int half = n >> 1;
        Node *topLeft = dfs(grid, x, y, half), *topRight = dfs(grid, x, y + half, half), *bottomLeft = dfs(grid, x + half, y, half), *bottomRight = dfs(grid, x + half, y + half, half);
        if (topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val && topRight->val == bottomLeft->val && bottomLeft->val == bottomRight->val)
        {
            Node *result = new Node(topLeft->val, true);
            delete topLeft;
            delete topRight;
            delete bottomLeft;
            delete bottomRight;
            return result;
        }
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }

public:
    Node *construct(vector<vector<int>> &grid)
    {
        return dfs(grid, 0, 0, grid.size());
    }
};
