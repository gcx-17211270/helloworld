package Thread;
/**
 * @ param     :    线程组
 * @ return    :
 * @ Description:   下面程序创建了几个线程，他们分别属于不同的线程组，程序还将一个线程组设置为后台线程组
 * @ Date       :2020/9/30 13:23
 * @ author     :32353
*/
class MyThread extends Thread
{
    //提供指定线程名的构造器
    public MyThread (String name)
    {
        super(name);
    }
    //提供指定线程名、线程组的构造器
    public Mythread (ThreadGroup group, String name)
    {
        super(group, name);
    }
    public void run()
    {
        for (var i = 0; i < 100; i++)
        {
            System.out.println(getName() + " 线程的i变量：" + i);
        }
    }
}

public class ThreadGroup {
    public static void main(String[] args)
    {
        //获取主线程所在的线程组
        ThreadGroup mainGroup = Thread.currentThread().getThreadGroup();
        System.out.println("主线程组的名字：" + mainGroup.getName());
        System.out.println("主线程组是否为后台进程：" + mainGroup.isDaemon());

        new MyThread("主线程组的线程").start();

        var tg = new ThreadGroup("新线程组");
        tg.setDaemon(true);
        System.out.println("tg线程组是否是后台线程组：" + tg.isDaemon());

        var tt = new MyThread(tg, "tg组的线程甲");
        tt.start();
        new MyThread(tg, "tg组的线程乙").start();
    }

}
