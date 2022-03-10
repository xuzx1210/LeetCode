class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> num1, num2;
        num1.clear(), num2.clear();
        for (ListNode *tmp = l1; tmp != nullptr; tmp = tmp->next)
            num1.push_back(tmp->val);
        for (ListNode *tmp = l2; tmp != nullptr; tmp = tmp->next)
            num2.push_back(tmp->val);
        vector<int> sum;
        sum.clear();
        int carry = 0;
        int length = min(num1.size(), num2.size());
        for (int i = 0; i < length; ++i)
        {
            int tmp = num1[i] + num2[i] + carry;
            sum.push_back(tmp % 10);
            carry = tmp / 10;
        }
        if (num1.size() < num2.size())
        {
            for (int i = num1.size(); i < num2.size(); ++i)
            {
                int tmp = num2[i] + carry;
                sum.push_back(tmp % 10);
                carry = tmp / 10;
            }
        }
        else if (num2.size() < num1.size())
        {
            for (int i = num2.size(); i < num1.size(); ++i)
            {
                int tmp = num1[i] + carry;
                sum.push_back(tmp % 10);
                carry = tmp / 10;
            }
        }
        if (carry)
            sum.push_back(carry);
        ListNode *result = new ListNode(sum[0]);
        ListNode *cur = result;
        for (int i = 1; i < sum.size(); ++i)
        {
            ListNode *tmp = new ListNode(sum[i]);
            cur->next = tmp;
            cur = tmp;
        }
        return result;
    }
};
