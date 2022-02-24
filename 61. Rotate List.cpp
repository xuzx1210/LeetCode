class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        vector<ListNode *> list({});
        for (ListNode *cur = head; cur != nullptr; cur = cur->next)
            list.push_back(cur);
        int n = list.size();
        if (n < 2)
            return head;
        k %= n;
        if (!k)
            return head;
        list.back()->next = head;
        list[n - k - 1]->next = nullptr;
        return list[n - k];
    }
};
