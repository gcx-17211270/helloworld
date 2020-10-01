package Thread.Thread_Communication;

public class DepositThread extends Thread{
    //模拟用户账户
    private Account2 account;
    //当前存款线程所希望存的钱数
    private double depositAmount;
    public DepositThread(String name, Account2 account, double depositAmount)
    {
        super(name);
        this.account = account;
        this.depositAmount = depositAmount;
    }
    //重复100次存操作
    public void run()
    {
        for (var i = 0; i < 100; i++)
        {
            account.deposit(depositAmount);
        }
    }
}
