package Thread;
/**
 * @ param     :    死锁
 * @ return    :
 * @ Description:   当两个线程互相等待对方释放同步监视器时就会发生死锁，Java虚拟机没有监测，
 *              也没有采取措施来处理死锁情况，所以在多线程编程的时候应该采取措施避免死锁出现。
 * @ Date       :2020/9/29 15:48
 * @ author     :32353
*/

public class DeadLock implements Runnable{
    A a = new A();
    B b = new B();
    public void init()
    {
        Thread.currentThread().setName("主线程");
        //调用a对象的foo()方法
        a.foo(b);
        System.out.println("进入主线程之后");
    }
    public void run()
    {
        Thread.currentThread().setName("副线程");
        b.bar(a);
        System.out.println("进入副线程之后");
    }
    public static void main(String[] args)
    {
        var dl = new DeadLock();
        //以dl为target启动新线程
        new Thread(dl).start();
        //调用init()方法
        dl.init();
    }
}
class A
{
    public synchronized void foo(B b)
    {
        System.out.println("当前线程名：" + Thread.currentThread().getName()
                        + " 进入了A实例的foo()方法");
        try
        {
            Thread.sleep(200);
        }
        catch (InterruptedException ex)
        {
            ex.printStackTrace();
        }
        System.out.println("当前线程名：" + Thread.currentThread().getName()
                        + " 企图调用B实例的last方法");
        b.last();
    }
    public synchronized void last()
    {
        System.out.println("进入了A类的last()方法内部");
    }
}
class B
{
    public synchronized void bar(A a)
    {
        System.out.println("当前线程名：" + Thread.currentThread().getName()
                + " 进入了B实例的bar()方法");
        try
        {
            Thread.sleep(200);
        }
        catch (InterruptedException ex)
        {
            ex.printStackTrace();
        }
        System.out.println("当前线程名：" + Thread.currentThread().getName()
                + " 企图调用A实例的last方法");
        a.last();
    }
    public synchronized void last()
    {
        System.out.println("进入了B类的last()方法内部");
    }
}