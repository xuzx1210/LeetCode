class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode left, right, *leftTail = &left, *rightTail = &right;
        for (ListNode *node = head; node; node = node->next)
            if (node->val < x)
                leftTail = leftTail->next = node;
            else
                rightTail = rightTail->next = node;
        if (&left == leftTail)
            return right.next;
        if (&right == rightTail)
            return left.next;
        leftTail->next = right.next;
        rightTail->next = nullptr;
        return left.next;
    }
};
