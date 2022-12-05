class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        for (ListNode *fast = head; fast; fast = fast->next->next)
            if (fast->next)
                slow = slow->next;
            else
                break;
        return slow;
    }
};
