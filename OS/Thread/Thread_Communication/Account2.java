package Thread.Thread_Communication;
/**
 * @ param     :    使用Condition控制线程通信
 * @ return    :
 * @ Description:   如果程序直接使用Lock对象来保证同步，系统中也就不存在隐式的同步监视器，
 *              也就不能用wait()、notify()、notifyAll()方法来进行线程通信，Java提供了一个
 *              Condition类来让已经得到Lock对象却无法继续执行的线程释放Lock对象，Condition
 *              对象也可以唤醒其他处于等待的线程。
 *                  Condition实例被绑定在一个Lock对象上。要获得特定Lock实例的Condition实例，
 *              调用Lock对象的newCondition()方法即可。Condition类提供了下面三个方法。
 *                  await()
 *                  signal()
 *                  signalAll()
 * @ Date       :2020/9/30 10:38
 * @ author     :32353
*/

//有个问题，Account类这么多，很多都只是局部修改实现其他功能，我为什么不用继承，然后重写父类中某些特定方法

public class Account2 extends Account{
    //显式定义Lock对象
    private final java.util.concurrent.locks.ReentrantLock lock = new java.util.concurrent.locks.ReentrantLock();
    //获得指定Lock对象的Condition
    private final java.util.concurrent.locks.Condition cond = lock.newCondition();
    public Account2(String accountNo, double balance)
    {
        super(accountNo,balance);
    }

    public void draw(double drawAmount)
    {
        //加锁
        lock.lock();
        try
        {
            //如果flag为假，表明账户中还没有人存钱进去，取钱方法阻塞
            if (!flag)
            {
                cond.await();
            }
            else
            {
                //执行取钱操作
                System.out.println(Thread.currentThread().getName() + " 取钱：" + drawAmount);
                setBalance(getBalance() - drawAmount);
                System.out.println("账户余额为：" + getBalance());
                //将标识账户是否已有存款的旗标设为false
                flag = false;
                //唤醒其他线程
                cond.signalAll();
            }
        }
        catch (InterruptedException ex)
        {
            ex.printStackTrace();
        }
        finally
        {
            lock.unlock();
        }
    }

    public void deposit(double depositAmount)
    {
        lock.lock();
        try
        {
            //如果flag为真，表明账户已经有人存钱进去，存钱方法阻塞
            if (flag)
            {
                cond.await();
            }
            else
            {
                //执行存款行为
                System.out.println(Thread.currentThread().getName() + " 存钱：" + depositAmount);
                setBalance(getBalance() + depositAmount);
                System.out.println("账户余额为：" + getBalance());
                //将表示账户是否已经有存款的旗标设置为true
                flag = true;
                //唤醒其他线程
                cond.signal();
            }
        }
        catch (InterruptedException ex)
        {
            ex.printStackTrace();
        }
        finally
        {
            lock.unlock();
        }
    }
}
