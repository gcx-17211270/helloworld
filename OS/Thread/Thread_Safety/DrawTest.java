package Thread.Thread_Safety;
/**
 * @ param     :    取钱的行为类
 * @ return    :
 * @ Description:   创建一个账户、启动两个线程从该账户里取钱
 * @ Date       :2020/9/29 13:34
 * @ author     :32353
*/

public class DrawTest {
    public static void main(String[] args)
    {
        //创建一个账户
        var acct = new Account3("1234567", 1000);
        //模拟两个线程对同一个账户取钱
        new DrawThread2("甲", acct,800).start();
        new DrawThread2("乙", acct, 800).start();
        System.out.println("finished!");
    }
}
