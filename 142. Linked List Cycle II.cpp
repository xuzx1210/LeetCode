class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head, *fast = head, *result = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                while (slow != result)
                {
                    slow = slow->next;
                    result = result->next;
                }
                return result;
            }
        }
        return nullptr;
    }
};
