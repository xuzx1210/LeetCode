class Solution {
public:
    ListNode *swapNodes(ListNode *head, int k)
    {
        vector<ListNode *> list;
        for (auto cur = head; cur; cur = cur->next)
            list.push_back(cur);
        swap(list[k - 1]->val, list[list.size() - k]->val);
        return head;
    }
};
