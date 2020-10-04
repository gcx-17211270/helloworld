class Solution
{
public:
    int visiblePoints(vector<vector<int>>& ps, int angle,vector<int>& s)
    {
        int ans = 0; 
        double pi = acos(-1.0);
        int x = s[0], y = s[1];
        vector<double> v;
        for (auto &p : ps)
        {
            if (x == p[0] && y == p[1])
            {
                ++ans;
                continue;
            }
            v.push_back(atan2(p[1] - y, p[0] - x));
        }
        sort(v.begin(), v.end());
        int n = v.size();
        for (int i = 0; i < n; ++i)
            v.push_back(v[i]);
        int j = 0;
        double g = 1.0 * angle * pi / 180;
        int tmp = 0;
        for (int i = 0; i < n; ++i)
        {
            while (j < i + n && (v[j] >= v[i] ?
                v[j] - v[i]:v[j] + 2 * pi - v[i]) <= g)
                ++j;
                tmp = max(tmp, j - i);
        }
        return ans + tmp;
    }
};

