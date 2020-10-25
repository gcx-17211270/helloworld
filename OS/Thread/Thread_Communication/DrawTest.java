package Thread.Thread_Communication;

public class DrawTest {
    public static void main(String[] args)
    {
        //创建一个用户
        var acct = new Account2("2345",0);
        new DrawThread("取钱者",acct,800).start();
        new DepositThread("存钱者甲", acct, 800).start();
        new DepositThread("存钱者乙", acct, 800).start();
        new DepositThread("存钱者丙", acct, 800).start();
    }
}
