class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto head : lists)
            for (ListNode *cur = head; cur != nullptr; cur = cur->next)
                pq.push(cur->val);
        ListNode *result = new ListNode;
        for (ListNode *cur = result; !pq.empty(); pq.pop())
        {
            ListNode *tmp = new ListNode(pq.top());
            cur->next = tmp;
            cur = tmp;
        }
        return result->next;
    }
};
