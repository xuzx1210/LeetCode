// store linked list in vector
class Solution
{
private:
    vector<int> vals;
    int size;

public:
    Solution(ListNode *head)
    {
        for (ListNode *cur = head; cur; cur = cur->next)
            vals.emplace_back(cur->val);
        size = vals.size();
    }
    int getRandom()
    {
        return vals[rand() % size];
    }
};

// unknown length
// without extra space
class Solution
{
private:
    ListNode *head;

public:
    Solution(ListNode *head)
    {
        this->head = head;
    }
    int getRandom()
    {
        int scope = 1, result;
        for (ListNode *cur = head; cur; cur = cur->next)
            if (!(rand() % scope++))
                result = cur->val;
        return result;
    }
};
