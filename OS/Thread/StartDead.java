package Thread;

/**
 * 下面程序将尝试对处于死亡状态的线程再次调用start()方法
 * @date:2020.09.28 23:54
 * @author 32353
 * */
public class StartDead extends Thread{
    private int i;
    public void run()
    {
        for ( ; i < 100; i++)
        {
            System.out.println("Hello " + getName() + " " + i);
        }
    }

    public static void main(String[] args)
    {
        var sd = new StartDead();
        for (var i = 0; i < 300; i++)
        {
            System.out.println(Thread.currentThread().getName() + " " + i);
            if (i == 20)
            {
                sd.start();
                //判断线程启动后的isAlive值
                System.out.println(sd.isAlive());
            }
            //当线程处于饿新建、死亡两种状态时，isAlive()方法返回false
            //当i > 20时，该线程肯定已经启动过了，如果st.isAlive()为false
            //则肯定是死亡状态了
            if (i > 20 && !sd.isAlive())
            {
                //试图再次启动该线程
                //如果子进程在主进程结束前执行完，就将引发IllegalThreadStateException异常
                sd.start();
            }
        }
    }
}
