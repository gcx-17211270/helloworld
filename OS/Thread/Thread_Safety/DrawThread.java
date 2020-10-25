package Thread.Thread_Safety;
/**
 * @ param     :    取钱的线程类
 * @ return    :
 * @ Description:   该线程类根据执行账户、取钱数量进行取钱操作。取钱的逻辑是当余额不足时无法提供现金，
 *              当余额足够时系统吐出钞票，余额减少。
 *                  多线程编程因为线程调度的不确定性，容易出现编程错误。如果取消代码中try-catch的语句，
 *              由于sleep()引起的强制线程调度切换，总是会出现错误。
 *                  解决的方法是使用同步监视器，使用同步监视器的通用方法就是同步代码块，同步代码块的
 *              语法格式如下：
 *                  synchronized (obj)
 *                  {
 *                      ...         //此处的代码就是同步代码块
 *                  }
 *                  上面语法格式中synchronized后括号的obj就是同步监视器，上面代码的含义是：线程开始执行
 *               同步代码块之前，必须先获得对同步监视器的锁定。
 * @ Date       :2020/9/29 13:25
 * @ author     :32353
*/

public class DrawThread extends Thread{
    //模拟用户账户
    private Account account;
    //当前取钱线程所希望取到的钱数
    private double drawAmount;
    public DrawThread(String name, Account account, double drawAmount)
    {
        super(name);
        this.account = account;
        this.drawAmount = drawAmount;
    }
    //当多个线程同时修改一个共享数据时，涉及数据安全问题
    //解决方法是使用账户(account)作为同步监视器，任何线程进入下面代码块之前
    //必须获得对account账户的锁定——其他线程无法获得锁，也就无法修改它
    //这种做法符合：“加锁->修改->释放锁”的逻辑
    public void run()
    {
        synchronized(account)
        {
            //账户余额大于取钱数目
            if (account.getBalance() >= drawAmount)
            {
                //吐出钞票
                System.out.println(getName() + "取钱成功！吐出钞票：" + drawAmount);
//            try
//            {
//                Thread.sleep(1);
//            }
//            catch (InterruptedException ex)
//            {
//                ex.printStackTrace();
//            }
                //修改余额
                account.setBalance(account.getBalance() - drawAmount);
                System.out.println("\t余额为：" + account.getBalance());
            }
            else
            {
                System.out.println(getName() + "取钱失败！余额不足！");
            }
        }
    }
}
