class Solution
{
public:
    bool winnerOfGame(string colors)
    {
        int counter[2] = {0};
        for (int i = colors.length() - 2; i > 0; --i)
            if (colors[i + 1] == colors[i] && colors[i] == colors[i - 1])
                ++counter[colors[i] - 'A'];
        return counter[0] > counter[1];
    }
};
