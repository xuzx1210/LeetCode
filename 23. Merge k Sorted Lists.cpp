class Solution
{
private:
    void link(ListNode *&tail, ListNode *&target)
    {
        tail->next = target;
        tail = target;
        target = target->next;
    }
    ListNode *merge2Lists(const vector<ListNode *>::const_iterator begin, const vector<ListNode *>::const_iterator end)
    {
        if (begin == end)
            return nullptr;
        const int diff = end - begin;
        if (diff == 1)
            return *begin;
        const vector<ListNode *>::const_iterator middle = begin + (diff >> 1);
        ListNode sentinel;
        ListNode *tail = &sentinel, *left = merge2Lists(begin, middle), *right = merge2Lists(middle, end);
        while (true)
            if (left && right)
                link(tail, left->val < right->val ? left : right);
            else if (left)
                link(tail, left);
            else if (right)
                link(tail, right);
            else
                break;
        return sentinel.next;
    }

public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        return merge2Lists(lists.begin(), lists.end());
    }
};
