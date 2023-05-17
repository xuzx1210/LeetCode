class Solution
{
public:
    int pairSum(ListNode *head)
    {
        ListNode *prev = nullptr, *slow = head, *fast = head;
        while (fast)
        { // find middle and reverse left side of list
            fast = fast->next->next;
            ListNode *next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }
        ListNode *left = prev, *right = slow;
        int result = 0;
        while (left && right)
        { // find max pair
            result = max(result, left->val + right->val);
            left = left->next;
            right = right->next;
        }
        return result;
    }
};
