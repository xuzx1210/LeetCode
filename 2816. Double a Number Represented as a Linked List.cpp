class Solution
{
private:
    int doubleAndCarry(ListNode *node)
    {
        if (!node)
            return 0;
        const int tmp = (node->val << 1) + doubleAndCarry(node->next);
        node->val = tmp % 10;
        return 9 < tmp;
    }

public:
    ListNode *doubleIt(ListNode *head)
    {
        if (doubleAndCarry(head))
            head = new ListNode(1, head);
        return head;
    }
};
