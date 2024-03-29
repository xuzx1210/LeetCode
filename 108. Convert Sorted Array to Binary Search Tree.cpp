class Solution
{
public:
    TreeNode *makeTree(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nullptr;
        int mid = (left + right) >> 1;
        return new TreeNode(nums[mid], makeTree(nums, left, mid), makeTree(nums, mid + 1, right));
    }
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        return makeTree(nums, 0, nums.size());
    }
};
