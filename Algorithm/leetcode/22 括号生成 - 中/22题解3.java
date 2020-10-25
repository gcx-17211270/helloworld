//三种方法，超详细注释，思路清晰，绝对看得懂
class Solution{
    //深度优先搜索
    public IList<string> GenerateParenthesis666(int n){//IList写错了？ string大小写？
        //n为0、1的时候特殊
        if (n == 0) return new List<string>(){""};
        else if (n == 1) return new List<string>(){"()"};

        IList<string> result = new List<string>();
        Helper(n, n, "", result);
        return result;
    }

    public void Helper(int left, int right, string cur, IList<string> result)
    {
        //参数里的left、right表示剩余可用的括号数
        //如果left>right,则说明之前使用过左括号个数比右括号少，例如（）），这样是无效的，直接返回
        if (left > right) return;
        ////此时恰好使用完所有括号，加入结果集
        if (left == 0 && right == 0)
        {
            result.Add(cur);
            return;
        }

        //还剩余左右括号没使用，继续递归
        if (left > 0)
            Helper(left - 1, right, cur + "(", result);
        if (right > 0)
            Helper(left, right - 1, cur + ")", result);
    }

    //动态规划
    public IList<string> GenerateParenthesis888(int n)
    {
        if (n == 0) return new List<string>(){""};
        else if (n == 1) return new List<string>(){"()"};

        List<List<string>> dp = new List<List<string>>();
        dp.Add(new List<string>(){""});
        for (int i = 1; i <= n; i++)
        {
            List<string> cur = new List<string>();
            for (int j = 0; j < i; j ++)
            {
                int cnt1 = dp[j].Count;
                int cnt2 = dp[i - 1 - j].Count;
                for (int m = 0; m < cnt1; m++)
                    for (int k = 0; k < cnt2; k++)
                        cur.Add($"({dp[j][m]}){dp[i - 1 - j][k]}");
            }
            dp.Add(cur);
        }
        return dp[n];
    }

    //模拟，找出所有可能插入的位置，然后去重
    public IList<string> GenerateParenthesis(int n)
    {
        List<string> result = new List<string>(){"()"};
        if (n == 1)
            return result;
        for (int i = 2; i <= n; i++)
        {
            List<string> temp = new List<string>();
            for (int j = 0; j < result.Count; j++)
            {
                string s = result[j];
                for (int k = 0; k <= s.length; k++)
                    temp.Add(s.Insert(k, "()"));
            }
            result = temp.Distinct().ToList();
        }
        return result;
    }
}