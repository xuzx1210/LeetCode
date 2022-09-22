class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        vector<ListNode *> nodes{};
        for (ListNode *cur = head; cur; cur = cur->next)
            nodes.emplace_back(cur);
        size_t size = nodes.size();
        for (size_t i = 0; i + 2 < size; i += 2)
            nodes[i]->next = nodes[i + 2];
        for (size_t i = 1; i + 2 < size; i += 2)
            nodes[i]->next = nodes[i + 2];
        if (size > 1)
        {
            ((size & 1) ? nodes[size - 1] : nodes[size - 2])->next = nodes[1];
            ((size & 1) ? nodes[size - 2] : nodes[size - 1])->next = nullptr;
        }
        return head;
    }
};
