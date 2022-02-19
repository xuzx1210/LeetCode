class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *result = new ListNode;
        ListNode *cur = result;
        while (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                cur->next = list1;
                cur = list1;
                list1 = list1->next;
            }
            else
            {
                cur->next = list2;
                cur = list2;
                list2 = list2->next;
            }
        }
        cur->next = (list1 == nullptr) ? list2 : list1;
        return result->next;
    }
};
