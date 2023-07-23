class Solution
{
public:
    vector<TreeNode *> allPossibleFBT(int n)
    { // roots[index]: all tree roots with index+1 nodes
        vector<vector<TreeNode *>> roots(n, vector<TreeNode *>{});
        roots[0].emplace_back(new TreeNode());
        for (int i = 1; i < n; ++i)
            for (int left = 1, right = i - left; right >= 1; ++left, --right)
                for (TreeNode *leftTree : roots[left - 1])
                    for (TreeNode *rightTree : roots[right - 1])
                        roots[i].emplace_back(new TreeNode(0, leftTree, rightTree));
        return roots.back();
    }
};
