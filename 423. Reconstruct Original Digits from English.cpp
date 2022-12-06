class Solution
{
public:
    string originalDigits(string s)
    {
        const vector<string> digits{"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
        const vector<char> distinct{'z', 'o', 'w', 't', 'u', 'f', 'x', 's', 'g', 'i'};
        const vector<int> order{0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
        vector<int> counter(26, 0), resultCounter(10, 0);
        for (char c : s)
            ++counter[c - 'a'];
        for (int cur : order)
        {
            resultCounter[cur] = counter[distinct[cur] - 'a'];
            for (char c : digits[cur])
                counter[c - 'a'] -= resultCounter[cur];
        }
        string result{};
        for (int i = 0; i < 10; ++i)
            result.insert(result.end(), resultCounter[i], i + '0');
        return result;
    }
};
