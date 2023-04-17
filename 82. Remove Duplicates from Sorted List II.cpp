class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        vector<int> counter(201, 0);
        for (ListNode *node = head; node; node = node->next)
            ++counter[node->val + 100];
        ListNode sentinel(-101, head);
        ListNode *last = &sentinel;
        for (ListNode *node = head; node; node = node->next)
            if (counter[node->val + 100] < 2)
            {
                last = last->next;
                last->val = node->val;
            }
        last->next = nullptr;
        return sentinel.next;
    }
};
