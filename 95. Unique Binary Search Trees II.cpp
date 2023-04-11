class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    { // use 0-indexed
        vector<vector<vector<TreeNode *>>> dp(n + 1, vector<vector<TreeNode *>>(n + 1, vector<TreeNode *>{}));
        // dp[begin][end]: vector<TreeNode *> contains all root of possible subtree for [begin, end)
        for (int i = 0; i <= n; ++i) // for length=0
            dp[i][i].emplace_back(nullptr);
        for (int length = 1; length <= n; ++length)                                           // length of range
            for (int begin = 0, end = length; end <= n; ++begin, ++end)                       // begin and end of the range
                for (int root = begin; root < end; ++root)                                    // root could be any index
                    for (TreeNode *left : dp[begin][root])                                    // all subtree for [begin, root)
                        for (TreeNode *right : dp[root + 1][end])                             // all subtree for [root+1, end)
                            dp[begin][end].emplace_back(new TreeNode(root + 1, left, right)); // +1 for 1-indexed
        return dp[0][n];
    }
};
