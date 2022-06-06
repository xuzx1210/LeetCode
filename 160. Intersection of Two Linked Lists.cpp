class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        vector<ListNode *> a = {}, b = {};
        for (ListNode *cur = headA; cur; cur = cur->next)
            a.push_back(cur);
        reverse(a.begin(), a.end());
        for (ListNode *cur = headB; cur; cur = cur->next)
            b.push_back(cur);
        reverse(b.begin(), b.end());
        size_t minSize = min(a.size(), b.size()), index = 0;
        for (index = 0; index < minSize; ++index)
            if (a[index] != b[index])
                break;
        return index ? a[index - 1] : nullptr;
    }
};
