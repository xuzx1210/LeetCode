class Solution
{
private:
    bool check(vector<int> &data, int index, int times)
    {
        if (index + times > data.size())
            return false;
        for (int i = 0; i < times; ++i)
            if ((data[index + i] & 192) != 128)
                return false;
        return true;
    }

public:
    bool validUtf8(vector<int> &data)
    {
        int size = data.size();
        for (int i = 0; i < size; ++i)
            if (!(data[i] & 128))
                continue;
            else if ((data[i] & 224) == 192)
                if (check(data, i + 1, 1))
                    ++i;
                else
                    return false;
            else if ((data[i] & 240) == 224)
                if (check(data, i + 1, 2))
                    i += 2;
                else
                    return false;
            else if ((data[i] & 248) == 240)
                if (check(data, i + 1, 3))
                    i += 3;
                else
                    return false;
            else
                return false;
        return true;
    }
};
