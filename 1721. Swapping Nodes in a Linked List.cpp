class Solution
{
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        ListNode *first = head;
        for (int i = 1; i < k; ++i)
            first = first->next;
        ListNode *second = head, *tmp = first;
        while (tmp->next)
        {
            tmp = tmp->next;
            second = second->next;
        }
        swap(first->val, second->val);
        return head;
    }
};
