class MedianFinder
{
private:
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;

public:
    MedianFinder()
    {
        left = {};
        left.emplace(INT_MIN);
        right = {};
        right.emplace(INT_MAX);
    }
    void addNum(int num)
    {
        if (num < left.top())
            left.emplace(num);
        else
            right.emplace(num);
        if (left.size() > right.size())
        {
            right.emplace(left.top());
            left.pop();
        }
        if (left.size() < right.size())
        {
            left.emplace(right.top());
            right.pop();
        }
    }
    double findMedian()
    {
        if (left.size() > right.size())
            return left.top();
        if (left.size() < right.size())
            return right.top();
        return (left.top() + right.top()) / 2.0;
    }
};
