class Solution
{
public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> result(n);
        for (size_t i = 0; i < n; ++i)
        {
            size_t cur = i + 1;
            bool mod3 = !(cur % 3), mod5 = !(cur % 5);
            if (mod3)
                result[i] = mod5 ? "FizzBuzz" : "Fizz";
            else
                result[i] = mod5 ? "Buzz" : to_string(cur);
        }
        return result;
    }
};
