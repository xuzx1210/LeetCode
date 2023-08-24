class Solution
{
public:
    vector<string> fullJustify(vector<string> &words, int maxWidth)
    {
        vector<string> result{};
        const int size = words.size();
        int beginIndex = 0, length = 0;
        for (int index = 0; index < size; ++index)
        {
            if (length + words[index].length() + index - beginIndex <= maxWidth)
            {
                length += words[index].length();
                continue;
            }
            string line{};
            int backIndex = index - 1;
            if (beginIndex != backIndex)
            {
                div_t d = div(maxWidth - length, backIndex - beginIndex);
                for (int i = beginIndex; i < backIndex; ++i)
                {
                    line.append(words[i]);
                    line.insert(line.end(), d.quot, ' ');
                    if (i - beginIndex < d.rem)
                        line.push_back(' ');
                }
            }
            line.append(words[backIndex]);
            line.insert(line.end(), maxWidth - line.length(), ' ');
            result.emplace_back(line);
            beginIndex = index;
            length = words[index].length();
        }
        string lastLine{};
        for (int index = beginIndex; index < size; ++index)
        {
            lastLine.append(words[index]);
            lastLine.push_back(' ');
        }
        lastLine.pop_back();
        lastLine.insert(lastLine.end(), maxWidth - lastLine.length(), ' ');
        result.emplace_back(lastLine);
        return result;
    }
};
