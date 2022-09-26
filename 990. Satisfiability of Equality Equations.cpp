class Solution
{
public:
    bool equationsPossible(vector<string> &equations)
    {
        vector<int> cluster(26);
        for (int i = 0; i < 26; ++i)
            cluster[i] = i;
        for (string &equation : equations)
        {
            if (equation[1] == '!')
                continue;
            int left = equation[0] - 'a', right = equation[3] - 'a';
            if (cluster[left] == cluster[right])
                continue;
            int tmp = cluster[right];
            for (int i = 0; i < 26; ++i)
                if (cluster[i] == tmp)
                    cluster[i] = cluster[left];
        }
        for (string &equation : equations)
            if (equation[1] == '!' && cluster[equation[0] - 'a'] == cluster[equation[3] - 'a'])
                return false;
        return true;
    }
};
