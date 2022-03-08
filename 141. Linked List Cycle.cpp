class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        ListNode *slow = head, *fast = head;
        while (slow->next && fast->next)
        {
            if (!fast->next->next)
                break;
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
