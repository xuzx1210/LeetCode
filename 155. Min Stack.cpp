class MinStack
{
private:
    stack<int> nums, mins;

public:
    MinStack()
    {
        nums = {};
        mins = {};
        mins.push(INT_MAX);
    }
    void push(int val)
    {
        nums.push(val);
        int m = mins.top();
        mins.push(m < val ? m : val);
    }
    void pop()
    {
        nums.pop();
        mins.pop();
    }
    int top()
    {
        return nums.top();
    }
    int getMin()
    {
        return mins.top();
    }
};
