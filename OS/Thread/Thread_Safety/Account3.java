package Thread.Thread_Safety;
/**
 * @ param     :    显式定义同步锁对象来实现同步
 * @ return    :
 * @ Description:   在实现线程安全的控制中，常用的是ReentrantLock（可重入锁），使用该对象可以显式地
 *              加锁、释放锁。使用ReentrantLock对象来进行同步，加锁和释放锁出现在不同的作用范围内时，
 *              通常建议使用finally块来确保在必要时释放锁。
 * @ Date       :2020/9/29 15:23
 * @ author     :32353
*/

public class Account3 {
    //定义锁对象
    private final java.util.concurrent.locks.ReentrantLock lock = new java.util.concurrent.locks.ReentrantLock();

    //账户编号、账户余额
    private String accountNo;
    private double balance;
    public Account3(String accountNo, double balance)
    {
        this.accountNo = accountNo;
        this.balance = balance;
    }
    public String getAccountNo()
    {
        return accountNo;
    }
    public void setAccountNo(String accountNo)
    {
        this.accountNo = accountNo;
    }
    public double getBalance() {
        return balance;
    }
    public void setBalance(double balance) {
        this.balance = balance;
    }

    //与原类的区别
    //使用lock提供一个线程安全的draw()方法来完成取钱操作
    public void draw(double drawAmount)
    {
        //加锁
        lock.lock();
        try
        {
            //账户余额大于取钱数目
            if (balance >= drawAmount)
            {
                //吐出钞票
                System.out.println(Thread.currentThread().getName() + "取钱成功！吐出钞票：" + drawAmount);
//            try
//            {
//                Thread.sleep(1);
//            }
//            catch (InterruptedException ex)
//            {
//                ex.printStackTrace();
//            }
                //修改余额
                balance -=  drawAmount;
                System.out.println("\t余额为：" + balance);
            }
            else
            {
                System.out.println(Thread.currentThread().getName() + "取钱失败！余额不足！");
            }
        }
        finally
        {
            //修改完成，释放锁
            lock.unlock();
        }
    }

    //下面两个方法根据accountNo来重写hashCode()和equals()方法
    public int hashCode()
    {
        return accountNo.hashCode();
    }
    public boolean equals(Object obj)
    {
        if (this == obj)
            return true;
        if (obj != null && obj.getClass() == Account.class)
        {
            var target = (Account) obj;
            return target.getAccountNo().equals(accountNo);
        }
        return false;
    }
}
