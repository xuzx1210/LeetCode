class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        vector<int> nodes = {};
        for (ListNode *cur = head; cur; cur = cur->next)
            nodes.push_back(cur->val);
        return equal(nodes.begin(), nodes.begin() + (nodes.size() >> 1), nodes.rbegin());
    }
};
