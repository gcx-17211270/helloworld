package Thread.Thread_Safety;
/**
 * @ param     :    使用同步方法修饰的Account类
 * @ return    :
 * @ Description:   同步方法就是使用synchronized关键字修饰某个方法，则该方法称为同步方法。对于
 *              synchronize修饰的实例方法而言，无需显式指定同步监视器，同步方法的同步监视器是
 *              this，也就是调用该方法的对象。
 * @ Date       :2020/9/29 14:48
 * @ author     :32353
*/

public class Account2 {
    //账户编号、账户余额
    private String accountNo;
    private double balance;
    public Account2(String accountNo, double balance)
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
    //使用synchronized提供一个线程安全的draw()方法来完成取钱操作
    public synchronized void draw(double drawAmount)
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
