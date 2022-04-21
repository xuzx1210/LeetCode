class Solution
{
public:
    void reorderList(ListNode *head)
    {
        vector<ListNode *> nodes({});
        for (ListNode *cur = head; cur; cur = cur->next)
            nodes.push_back(cur);
        int size = nodes.size();
        int half = size >> 1;
        vector<ListNode *> result({});
        for (int i = 0; i < half; ++i)
        {
            result.push_back(nodes[i]);
            result.push_back(nodes[size - i - 1]);
        }
        if (size & 1)
            result.push_back(nodes[half]);
        for (int i = 0; i < size - 1; ++i)
            result[i]->next = result[i + 1];
        result.back()->next = nullptr;
    }
};
