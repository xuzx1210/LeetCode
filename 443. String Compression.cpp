class Solution
{
private:
    void addChar(string &compressed, char &last, int &counter)
    {
        compressed.push_back(last);
        if (counter > 1)
            compressed += to_string(counter);
    }

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
                addChar(compressed, last, counter);
                last = c;
                counter = 1;
            }
        addChar(compressed, last, counter);
        chars = vector<char>(compressed.begin() + 1, compressed.end());
        return chars.size();
    }
};
