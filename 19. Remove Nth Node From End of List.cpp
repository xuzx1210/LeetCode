class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        vector<int> nums;
        nums.clear();
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
            nums.push_back(cur->val);
        if (nums.size() < 2)
            return nullptr;
        nums.erase(nums.end() - n);
        ListNode *result = new ListNode(nums[0]);
        ListNode *cur = result;
        for (int i = 1; i < nums.size(); ++i)
        {
            ListNode *tmp = new ListNode(nums[i]);
            cur->next = tmp;
            cur = tmp;
        }
        return result;
    }
};
