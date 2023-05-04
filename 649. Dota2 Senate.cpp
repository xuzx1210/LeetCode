class Solution
{
public:
    string predictPartyVictory(string senate)
    {
        int senators = senate.length(), remain = 0, radiant = 0, dire = 0;
        while (true)
        {
            for (int i = 0; i < senators; ++i)
                if (senate[i] == 'R')
                {
                    ++radiant;
                    if (radiant > dire)
                        senate[remain++] = 'R';
                }
                else
                {
                    ++dire;
                    if (dire > radiant)
                        senate[remain++] = 'D';
                }
            if (remain == senators)
                break;
            senators = remain;
            remain = 0;
        }
        return senate[0] == 'R' ? "Radiant" : "Dire";
    }
};
