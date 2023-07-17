class Solution
{
private:
    int countSize(ListNode *head)
    {
        int size = 0;
        for (; head; head = head->next)
            ++size;
        return size;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        for (ListNode *curr = head; curr;)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        const int size1 = countSize(l1), size2 = countSize(l2);
        ListNode *back1 = reverse(l1), *back2 = reverse(l2);
        if (size1 < size2)
            swap(back1, back2);
        int carry = 0;
        ListNode *prev = nullptr;
        for (ListNode *curr1 = back1, *curr2 = back2; curr1;)
        {
            int sum = curr1->val + carry;
            if (curr2)
                sum += curr2->val;
            curr1->val = sum % 10;
            carry = sum / 10;
            prev = curr1;
            curr1 = curr1->next;
            if (curr2)
                curr2 = curr2->next;
        }
        if (carry)
            prev->next = new ListNode(1);
        return reverse(back1);
    }
};
