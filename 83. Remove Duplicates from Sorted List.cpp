class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    { // return list without duplicates
        if (!head)
            return nullptr;
        head->next = deleteDuplicates(head->next);
        return head->next && head->val == head->next->val ? head->next : head;
    }
};
