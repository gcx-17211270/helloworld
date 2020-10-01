package Thread;
/**
 * 启动线程应该使用start()方法，而不是run()方法，永远不要调用线程对象的run()方法
 * 如果直接使用run()方法，系统会把run()方法当成线程执行体来处理，得到的是整个程序只有一个线程
 * 调用了run()方法后，该线程已经不是新建状态，不能再次调用线程对象的start()方法
 * 否则将引发IllegalThreadStateException异常
 *
 * @date:2020.09.28
 * @author 32353
 * */

public class InvokeRun extends Thread{
    private int i;
    public void run()
    {
        for ( ; i < 100; i++)
        {
            //直接调用run()方法时，Thread的this.getName()返回的是该对象的名字
            //而不是当前线程的名字
            //使用Thread.currentThread().getName()总是获取当前线程的名字
            System.out.println(Thread.currentThread().getName() + " " + i);
        }
    }
    public static void main(String[] args)
    {
        for (var i = 0; i < 100; i++)
        {
            //调用Thread的currentThread()方法获取当前进程
            System.out.println(Thread.currentThread().getName() + " " + i);
            if (i == 20)
            {
                //直接调用线程对象的run()方法
                //系统会把线程对象砍成普通对象，把run()方法看成普通方法
                //所以下面两行代码并不会启动两个线程，而是依次执行两个run()方法
                new InvokeRun().run();
                new InvokeRun().run();
            }
        }
    }
}
