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
        int scope = 1, result = head->val;
        for (ListNode *cur = head; cur; cur = cur->next)
            if (!(rand() % scope++))
                result = cur->val;
        return result;
    }
};
