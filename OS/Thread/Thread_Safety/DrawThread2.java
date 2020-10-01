package Thread.Thread_Safety;
/**
 * @ param     :    配合Account2的DrawThread2
 *                  也可以通过修改，配合Account3类使用
 * @ return    :
 * @ Description:   因为在Account2里已经写了线程安全的draw方法，因而本线程类的run()方法只要调用Account对象的
 *              draw()方法即可执行取钱操作。
 *                  在Account里定义draw()方法，而不是在run()方法中实现取钱逻辑，这样做法更符合面向对象规则。
 *              在面向对象中有一种流行的涉及方式:Domain Driven Design（领域驱动设计），这种方式认为每个类都
 *              应该是完备的领域对象。
 * @ Date       :2020/9/29 14:53
 * @ author     :32353
*/

public class DrawThread2 extends Thread{
    //模拟用户账户
    private Account3 account;
    //当前取钱线程所希望取到的钱数
    private double drawAmount;
    public DrawThread2(String name, Account3 account, double drawAmount)
    {
        super(name);
        this.account = account;
        this.drawAmount = drawAmount;
    }
    public void run()
    {
        account.draw(drawAmount);
    }
}
