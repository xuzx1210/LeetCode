class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int counter = 0;
        for (int &code : data)
            if (!counter)
                if ((code & 0b10000000) == 0b00000000)
                    continue;
                else if ((code & 0b11100000) == 0b11000000)
                    counter = 1;
                else if ((code & 0b11110000) == 0b11100000)
                    counter = 2;
                else if ((code & 0b11111000) == 0b11110000)
                    counter = 3;
                else
                    return false;
            else if ((code & 0b11000000) != 0b10000000)
                return false;
            else
                --counter;
        return !counter;
    }
};
