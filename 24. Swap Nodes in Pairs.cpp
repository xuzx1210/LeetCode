class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        ListNode sentinel(0, head);
        for (ListNode *prev = &sentinel, *curr = head; curr;)
        {
            // check next
            ListNode *next = curr->next;
            if (!next)
                break;
            // assign link
            curr->next = next->next;
            next->next = curr;
            prev->next = next;
            // move pointer
            prev = curr;
            curr = curr->next;
        }
        return sentinel.next;
    }
};
