class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    { // roots[index]: all tree roots with index nodes
        vector<vector<TreeNode *>> roots(n + 1, vector<TreeNode *>{});
        roots[1].emplace_back(new TreeNode());
        for (int i = 2; i <= n; ++i)
            for (int left = 1, right = i - left - 1; right >= 1; ++left, --right)
                for (TreeNode *leftTree : roots[left])
                    for (TreeNode *rightTree : roots[right])
                        roots[i].emplace_back(new TreeNode(0, leftTree, rightTree));
        return roots.back();
    }
};
