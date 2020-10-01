package Thread;

/**
 * 实现Runnable接口创建线程类
 * @date:2020.09.28
 * @创建方法：
 *      1.定义Runnable接口的实现类，并重写该接口的run()方法
 *      2.创建Runnable实现类的实例，并以此实例作为Thread的Target来创建Thread对象
 * */

public class SecondThread implements Runnable{
    private int i;
    public void run()
    {
        for ( ; i < 100; i++)
        {
            //当线程类实现Runnable接口时
            //如果想获取当前线程，只能用Thread.currentThread()方法
            System.out.println(Thread.currentThread().getName() + " " + i);
        }
    }

    public static void main(String[] args)
    {
        for (var i = 0; i < 100; i++)
        {
            System.out.println(Thread.currentThread().getName() + " " + i);
            if (i == 20)
            {
                var st = new SecondThread();
                new Thread(st, "newThread1").start();
                new Thread(st, "newThread2").start();
            }
        }
    }
}
