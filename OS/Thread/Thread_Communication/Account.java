package Thread.Thread_Communication;
/**
 * @ param     :    传统的线程通信
 * @ return    :
 * @ Description:   Object类提供了wait()、notify()、notifyAll()三个方法，这三个方法
 *              必须由同步监视器对象来调用，关于这三个方法的解释如下：
 *                  wait()：导致当前线程等待，直到其他线程调用该同步监视器的notify()方法
 *              或notifyAll()方法来唤醒该线程
 *                  notify()：唤醒在此同步监视器上等待的单个线程，如果所有线程都在此同步
 *              监视器上等待，则会选择唤醒其中一个。
 *                  notifyAll()：唤醒在此同步监视器上等待的所有线程。
 * @ Date       :2020/9/29 16:29
 * @ author     :32353
 */
public class Account {
    //账户编号、账户余额
    private String accountNo;
    private double balance;
    //标识账户中是否由存款的旗标
    public boolean flag = false;
    public Account(String accountNo, double balance)
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

    protected synchronized void draw(double drawAmount)
    {
        try
        {
            //如果flag为假，表明账户中还没有人存钱进去，取钱方法阻塞
            if (!flag)
            {
                wait();
            }
            else
            {
                //执行取钱操作
                System.out.println(Thread.currentThread().getName() + " 取钱：" + drawAmount);
                balance -= drawAmount;
                System.out.println("账户余额为：" + balance);
                //将标识账户是否已有存款的旗标设为false
                flag = false;
                //唤醒其他线程
                notifyAll();
            }
        }
        catch (InterruptedException ex)
        {
            ex.printStackTrace();
        }
    }

    protected synchronized void deposit(double depositAmount)
    {
        try
        {
            //如果flag为真，表明账户已经有人存钱进去，存钱方法阻塞
            if (flag)
            {
                wait();
            }
            else
            {
                //执行存款行为
                System.out.println(Thread.currentThread().getName() + " 存钱：" + depositAmount);
                balance += depositAmount;
                System.out.println("账户余额为：" + depositAmount);
                //将表示账户是否已经有存款的旗标设置为true
                flag = true;
                //唤醒其他线程
                notifyAll();
            }
        }
        catch (InterruptedException ex)
        {
            ex.printStackTrace();
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
