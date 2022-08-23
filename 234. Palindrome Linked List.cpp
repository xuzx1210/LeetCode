class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head, *slow = head, *prev, *temp;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        prev = slow;
        slow = slow->next;
        prev->next = nullptr;
        while (slow)
        {
            temp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = temp;
        }
        fast = head;
        slow = prev;
        for (; slow; slow = slow->next, fast = fast->next)
            if (fast->val != slow->val)
                return false;
        return true;
    }
};
