package Thread;
/**
 * @ param:    join()方法。当在某个程序执行流中调用其他线程的join()方法时，调用线程将被阻塞，直到
 *          被join()方法加入的join线程执行完为止。
 *
 * @ return:
 * @ Description:
 * @ Date       :2020/9/29 0:11
 * @ author     :32353
*/


public class JoinThread extends Thread{
    //提供一个有参数的构造器，用于设置该线程的名字
    public JoinThread(String name)
    {
        super(name);
    }
    //重写run()方法，定义线程执行体
    public void run()
    {
        for (var i = 0; i < 100; i++)
            System.out.println(getName() + " " + i);
    }

    public static void main(String[] args)
    {
        //启动子线程
        new JoinThread("新线程").start();
        for (var i = 0; i < 100; i++)
        {
            if (i == 20)
            {
                var jt = new JoinThread("被Join的线程");
                jt.start();
                //main线程调用了jt线程的join()方法，main线程必须等jt执行结束才会向下执行
                try {
                    jt.join();
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
            System.out.println(Thread.currentThread().getName() + " " +  i);
        }
    }
}
