package Thread;
/**
 * @ param     :    后台进程(Daemon Thread)
 * @ return    :
 * @ Description:   又称为“守护线程”、“精灵线程”，JVM的垃圾回收线程就是典型的后台线程
 *              后台进程的特征：如果所有前台线程都死亡，后台线程会自动死亡。
 *                  调用Thread对象的setDaemon(true)方法可将指定线程设置为后台线程。下面的
 *              程序将执行线程设为后台线程，可以看到当所有的前台线程死亡时，后台线程随之死亡。
 *              当整个虚拟机中只剩下后台线程，程序就没有继续运行的必要，所以虚拟机也就退出了。
 *                  Thread类还提供一个isDaemon()方法，用来判断指定线程是否为后台进程。前台
 *              进程创建的子进程默认是前台进程，后台进程创建的进程默认是后台进程。
 * @ Date       :2020/9/29 9:36
 * @ author     :32353
*/

public class DaemonThread extends Thread{
    //定义后台线程的线程执行体和普通线程没有任何区别
    public void run()
    {
        for (var i = 0; i < 100; i++)
        {
            System.out.println(getName() + " " + i);
        }
    }
    public static void main(String[] args)
    {
        var t = new DaemonThread();
        //将此线程设置为后台线程
        t.setDaemon(true);
        //启动后台线程
        t.start();
        for (var i = 0; i < 50; i++)
        {
            System.out.println(Thread.currentThread().getName() + " " + i);
        }
        //程序执行到此处，前台线程(main线程)执行结束
        //后台线程也应随之结束
    }
}
