class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        ListNode dummy;
        dummy.next = head;
        ListNode *sentinel, *tail = &dummy;
        for (int i = 0; i < left; ++i)
        {
            sentinel = tail;
            tail = tail->next;
        }
        for (int i = left; i < right; ++i)
        {
            ListNode *previous = tail->next;
            tail->next = previous->next;
            previous->next = sentinel->next;
            sentinel->next = previous;
        }
        return dummy.next;
    }
};
