class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& amn)
    {
        int n= amn.size();
        vector<int> ans(n, 0);
        stack<int> stk;
        for(int i=0;i<n;i++)
        {
            while(!stk.empty()&&amn[stk.top()]<amn[i])
            {
                ans[stk.top()] =i-stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};