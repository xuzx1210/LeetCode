class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        for (int i = 0; i < n; ++i)
            fast = fast->next;
        if (!fast)
            return head->next;
        ListNode *slow = head;
        for (; fast->next; fast = fast->next)
            slow = slow->next;
        slow->next = n == 1 ? nullptr : slow->next->next;
        return head;
    }
};
