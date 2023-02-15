class Solution
{
private:
    int fullAdder(int digit0, int digit1, int &carry)
    {
        int sum = digit0 + digit1 + carry;
        carry = 0;
        if (sum > 9)
        {
            sum -= 10;
            carry = 1;
        }
        return sum;
    }

public:
    vector<int> addToArrayForm(vector<int> &num, int k)
    {
        vector<int> &num0 = num;
        reverse(num0.begin(), num0.end());
        vector<int> num1{};
        while (k)
        {
            const div_t d = div(k, 10);
            num1.emplace_back(d.rem);
            k = d.quot;
        }
        const int size0 = num0.size(), size1 = num1.size();
        const int minSize = min(size0, size1);
        int carry = 0;
        vector<int> result{};
        for (int i = 0; i < minSize; ++i)
            result.emplace_back(fullAdder(num0[i], num1[i], carry));
        if (size0 < size1)
            for (int i = size0; i < size1; ++i)
                result.emplace_back(fullAdder(0, num1[i], carry));
        else
            for (int i = size1; i < size0; ++i)
                result.emplace_back(fullAdder(num0[i], 0, carry));
        if (carry == 1)
            result.emplace_back(1);
        reverse(result.begin(), result.end());
        return result;
    }
};
