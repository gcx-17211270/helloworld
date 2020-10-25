package Thread.Thread_Communication;

public class DrawThread extends Thread {
    //模拟用户账户
    private Account2 account;
    //当前希望取钱的钱数
    private double drawAmount;
    public DrawThread(String name, Account2 account, double drawAmount)
    {
        super(name);
        this.account = account;
        this.drawAmount = drawAmount;
    }
    //重复100次取钱操作
    public void run()
    {
        for (var i = 0; i < 100; i++)
        {
            account.draw(drawAmount);
        }
    }
}
