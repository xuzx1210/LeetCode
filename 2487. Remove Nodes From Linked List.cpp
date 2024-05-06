class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *next = removeNodes(head->next);
        if (next && head->val < next->val)
            return next;
        head->next = next;
        return head;
    }
};
