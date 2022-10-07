class MyCalendarThree
{
private:
    map<int, int> calender;

public:
    MyCalendarThree()
    {
        calender.clear();
    }
    int book(int start, int end)
    {
        ++calender[start];
        --calender[end];
        int result = 0, integral = 0;
        for (const auto &[key, value] : calender)
        {
            integral += value;
            result = max(result, integral);
        }
        return result;
    }
};
