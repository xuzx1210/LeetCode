class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> nodes({});
        for (ListNode *cur = headA; cur; cur = cur->next)
            nodes.insert(cur);
        for (ListNode *cur = headB; cur; cur = cur->next)
            if (nodes.find(cur) != nodes.end())
                return cur;
        return nullptr;
    }
};
