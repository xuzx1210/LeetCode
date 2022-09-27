class Solution
{
private:
    void write(string &result, int start, int end, char c)
    {
        int length = end - start;
        result.replace(start, length, length, c);
    }

public:
    string pushDominoes(string dominoes)
    {
        size_t length = dominoes.length();
        vector<pair<char, int>> force;
        for (int i = 0; i < length; ++i)
            if (dominoes[i] != '.')
                force.push_back({dominoes[i], i});
        size_t size = force.size();
        string result(dominoes);
        if (force.empty())
            return result;
        if (force.front().first == 'L')
            write(result, 0, force.front().second, 'L');
        if (force.back().first == 'R')
            write(result, force.back().second + 1, length, 'R');
        if (size == 1)
            return result;
        for (int i = 0; i < size - 1; ++i)
            if (force[i].first == 'L' && force[i + 1].first == 'L')
                write(result, force[i].second + 1, force[i + 1].second, 'L');
            else if (force[i].first == 'R' && force[i + 1].first == 'R')
                write(result, force[i].second + 1, force[i + 1].second, 'R');
            else if (force[i].first == 'R' && force[i + 1].first == 'L')
            {
                int half = (force[i + 1].second - force[i].second + 1) >> 1;
                write(result, force[i].second + 1, force[i].second + half, 'R');
                write(result, force[i + 1].second - half + 1, force[i + 1].second, 'L');
            }
        return result;
    }
};
