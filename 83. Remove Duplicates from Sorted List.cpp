class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    { // return list without duplicates
        if (!head || !head->next)
            return head;
        head->next = deleteDuplicates(head->next);
        return head->val == head->next->val ? head->next : head;
    }
};
