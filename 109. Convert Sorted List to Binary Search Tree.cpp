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
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> nums({});
        for (ListNode *cur = head; cur; cur = cur->next)
            nums.push_back(cur->val);
        return makeTree(nums, 0, nums.size());
    }
};
