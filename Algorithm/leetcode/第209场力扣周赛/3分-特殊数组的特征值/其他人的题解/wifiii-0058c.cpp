class Solution
{
    public:
        int specialArray(vector<int>& a)
        {
            int n = a.size();
            for (int x = 0; x <= n; ++x)
            {
                int cnt = 0;
                for (int i: a)
                    if (i >= x)
                        ++cnt;
                if (cnt == x) return x;
            }
            return -1;
        }
}