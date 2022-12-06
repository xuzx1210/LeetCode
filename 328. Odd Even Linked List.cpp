class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head)
            return head;
        if (!head->next)
            return head;
        ListNode *oddHead = head, *evenHead = head->next, *oddTail = head, *evenTail = head->next;
        while (oddTail->next && evenTail->next)
        {
            oddTail->next = oddTail->next->next;
            oddTail = oddTail->next;
            evenTail->next = evenTail->next->next;
            evenTail = evenTail->next;
        }
        oddTail->next = evenHead;
        return oddHead;
    }
};
