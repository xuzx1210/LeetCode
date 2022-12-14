class Solution
{
public:
    int compress(vector<char> &chars)
    {
        string compressed{};
        char last = ' ';
        int counter = 1;
        for (char c : chars)
            if (c == last)
                ++counter;
            else
            {
                compressed.push_back(last);
                last = c;
                if (counter > 1)
                    compressed += to_string(counter);
                counter = 1;
            }
        compressed.push_back(last);
        if (counter > 1)
            compressed += to_string(counter);
        chars = vector<char>(compressed.begin() + 1, compressed.end());
        return chars.size();
    }
};
