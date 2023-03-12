class Solution
{
public:
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<pair<int, ListNode *>>> pq{}; // sort by val
        for (ListNode *listHead : lists)
            if (listHead) // skip empty list
                pq.emplace(listHead->val, listHead);
        ListNode *result = new ListNode(); // sentinel
        ListNode *tail = result;           // tail of result list
        while (!pq.empty())
        {
            ListNode *cur = pq.top().second;
            pq.pop();
            tail->next = cur; // push cur to the end of result list
            tail = cur;
            cur = cur->next;
            if (cur)
                pq.emplace(cur->val, cur);
        }
        tail = result;
        result = result->next;
        delete tail; // release sentinel memory
        return result;
    }
};
