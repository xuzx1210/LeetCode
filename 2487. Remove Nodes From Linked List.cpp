class Solution
{
public:
    ListNode *removeNodes(ListNode *head)
    {
        if (!head)
            return nullptr;
        head->next = removeNodes(head->next);
        if (!head->next)
            return head;
        if (head->val < head->next->val)
            return head->next;
        return head;
    }
};
