class Solution
{
public:
    vector<ListNode *> splitListToParts(ListNode *head, int k)
    {
        int size = 0;
        for (ListNode *curr = head; curr; curr = curr->next)
            ++size;
        const div_t d = div(size, k);
        vector<ListNode *> result(k);
        ListNode redundant;
        ListNode *curr = head, *prev = &redundant;
        for (int i = 0; i < k; ++i)
        {
            prev->next = nullptr;
            result[i] = curr;
            for (int j = d.quot + (i < d.rem); j; --j)
            {
                prev = curr;
                curr = curr->next;
            }
        }
        return result;
    }
};
