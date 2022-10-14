class Solution
{
public:
    ListNode *deleteMiddle(ListNode *head)
    {
        ListNode *prev = nullptr;
        for (ListNode *slow = head, *fast = head; fast && fast->next; slow = slow->next, fast = fast->next->next)
            prev = slow;
        if (!prev)
            return prev;
        prev->next = prev->next->next;
        return head;
    }
};
