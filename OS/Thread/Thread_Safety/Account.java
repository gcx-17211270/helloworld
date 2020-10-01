package Thread.Thread_Safety;
/**
 * @ param     :    账户类
 * @ return    :
 * @ Description:   封装了账户编号和余额两个实例变量
 * @ Date       :2020/9/29 11:11
 * @ author     :32353
 */

public class Account {
    //账户编号、账户余额
    private String accountNo;
    private double balance;
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
