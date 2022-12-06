class Solution
{
private:
    class Table
    {
    private:
        vector<int> counter;
        char feature;

    public:
        Table(string num, char feature)
        {
            this->feature = feature;
            counter.resize(26, 0);
            for (char c : num)
                ++counter[c - 'a'];
        }
        int operator-=(Table &right)
        {
            int times = counter[right.feature - 'a'];
            for (int i = 0; i < 26; ++i)
                counter[i] -= times * right.counter[i];
            return times;
        }
    };

public:
    string originalDigits(string s)
    {
        Table input(s, 'a');
        vector<Table> table{};
        table.emplace_back("zero", 'z');
        table.emplace_back("one", 'o');
        table.emplace_back("two", 'w');
        table.emplace_back("three", 't');
        table.emplace_back("four", 'u');
        table.emplace_back("five", 'f');
        table.emplace_back("six", 'x');
        table.emplace_back("seven", 's');
        table.emplace_back("eight", 'g');
        table.emplace_back("nine", 'i');
        vector<int> resultCounter(10, 0);
        for (int i = 0; i < 10; i += 2)
            resultCounter[i] = input -= table[i];
        for (int i = 1; i < 10; i += 2)
            resultCounter[i] = input -= table[i];
        string result{};
        for (int i = 0; i < 10; ++i)
            result.insert(result.end(), resultCounter[i], i + '0');
        return result;
    }
};
