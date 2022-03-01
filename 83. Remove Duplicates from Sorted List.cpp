class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        vector<ListNode *> list({});
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
            list.push_back(cur);
        if (list.size() < 2)
            return head;
        int left = 0, right = 1;
        for (; right < list.size(); ++right)
        {
            if (list[right]->val == list[left]->val)
                continue;
            list[left]->next = list[right];
            left = right;
        }
        list[left]->next = nullptr;
        return head;
    }
};
