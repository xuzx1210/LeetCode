class Solution {
public:
    ListNode *swapPairs(ListNode *head)
    {
        vector<int> num;
        num.clear();
        ListNode *cur = head;
        for (; cur != nullptr; cur = cur->next)
            num.push_back(cur->val);
        int swapTime = (num.size() >> 1);
        for (int i = 0; i < swapTime; ++i)
            swap(num[i << 1], num[(i << 1) + 1]);
        cur = head;
        for (int i = 0; i < num.size(); ++i)
        {
            cur->val = num[i];
            cur = cur->next;
        }
        return head;
    }
};
