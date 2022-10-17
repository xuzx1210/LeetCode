class Solution
{
public:
    bool checkIfPangram(string sentence)
    {
        int exist = 0;
        for (char &c : sentence)
            exist |= (1 << (c - 'a'));
        return exist == (1 << 26) - 1;
    }
};
