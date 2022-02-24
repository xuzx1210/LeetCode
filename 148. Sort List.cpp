class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        vector<int> nums({});
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
            nums.push_back(cur->val);
        sort(nums.begin(), nums.end());
        ListNode *cur = head;
        for (auto num : nums)
        {
            cur->val = num;
            cur = cur->next;
        }
        return head;
    }
};
