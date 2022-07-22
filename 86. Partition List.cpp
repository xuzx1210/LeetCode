class Solution
{
public:
    ListNode *partition(ListNode *head, int x)
    {
        ListNode *leftHead = nullptr, *leftTail = nullptr, *rightHead = nullptr, *rightTail = nullptr;
        for (ListNode *cur = head; cur; cur = cur->next)
            if (cur->val < x)
            {
                if (leftHead)
                    leftTail->next = cur;
                else
                    leftHead = cur;
                leftTail = cur;
            }
            else
            {
                if (rightHead)
                    rightTail->next = cur;
                else
                    rightHead = cur;
                rightTail = cur;
            }
        if (leftTail)
            leftTail->next = rightHead;
        if (rightTail)
            rightTail->next = nullptr;
        return leftHead ? leftHead : (rightHead ? rightHead : nullptr);
    }
};
