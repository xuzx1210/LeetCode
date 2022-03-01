class Solution
{
public:
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        vector<ListNode *> list({});
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
            list.push_back(cur);
        --left;
        --right;
        for (int i = right; i > left; --i)
            list[i]->next = list[i - 1];
        if (left)
            list[left - 1]->next = list[right];
        else
            head = list[right];
        if (right == list.size() - 1)
            list[left]->next = nullptr;
        else
            list[left]->next = list[right + 1];
        return head;
    }
};
