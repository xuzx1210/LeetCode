class Solution
{
private:
    TreeNode *makeTree(const vector<int>::const_iterator begin, const vector<int>::const_iterator end)
    {
        if (begin == end)
            return nullptr;
        const vector<int>::const_iterator middle = begin + ((end - begin) >> 1);
        return new TreeNode(*middle, makeTree(begin, middle), makeTree(middle + 1, end));
    }

public:
    TreeNode *sortedListToBST(ListNode *head)
    {
        vector<int> vals{};
        for (ListNode *cur = head; cur; cur = cur->next)
            vals.emplace_back(cur->val);
        return makeTree(vals.begin(), vals.end());
    }
};
