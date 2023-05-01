class Solution
{
public:
    double average(vector<int> &salary)
    {
        const int size = salary.size();
        int minimum = 1000000, maximum = 1000;
        double sum = 0.0;
        for (int i = 0; i < size; ++i)
        {
            minimum = min(minimum, salary[i]);
            maximum = max(maximum, salary[i]);
            sum += salary[i];
        }
        sum = sum - minimum - maximum;
        return sum / (size - 2);
    }
};
