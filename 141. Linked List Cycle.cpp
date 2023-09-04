class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head)
            return false;
        for (ListNode *slow = head, *fast = head->next; fast && fast->next; slow = slow->next, fast = fast->next->next)
            if (slow == fast)
                return true;
        return false;
    }
};
