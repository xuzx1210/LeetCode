class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        set<ListNode *> list({});
        for (ListNode *cur = head; cur; cur = cur->next)
        {
            if (list.find(cur) == list.end())
                list.insert(cur);
            else
                return true;
        }
        return false;
    }
};
