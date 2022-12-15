class Solution
{
private:
    vector<int> makeNumber(ListNode *head)
    {
        vector<int> result{};
        for (ListNode *cur = head; cur; cur = cur->next)
            result.emplace_back(cur->val);
        reverse(result.begin(), result.end());
        return result;
    }
    void fullAdder(int input, int &carry, vector<int> &sum)
    { // input: digit1 + digit2
        int tmp = input + carry;
        carry = tmp >= 10;
        sum.emplace_back(carry ? tmp - 10 : tmp);
    }

public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        vector<int> number1(makeNumber(l1)), number2(makeNumber(l2)), sum{}; // reversed numbers
        const size_t size1 = number1.size(), size2 = number2.size();
        const size_t minSize = min(size1, size2), maxSize = max(size1, size2);
        int carry = 0;
        for (size_t i = 0; i < minSize; ++i)
            fullAdder(number1[i] + number2[i], carry, sum);
        for (size_t i = minSize; i < maxSize; ++i)
            fullAdder((size1 > size2 ? number1 : number2)[i], carry, sum);
        if (carry)
            sum.emplace_back(1);
        ListNode *result = nullptr;
        for (int &digit : sum) // create linked list from back
            result = new ListNode(digit, result);
        return result;
    }
};
