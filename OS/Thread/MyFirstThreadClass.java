package Thread;

/**
 * 线程的创建和启动
 * 使用继承Thread类创建线程类
 * 使用继承Thread类的方法来创建线程类时，多个线程之间无法共享线程类的实例变量
 * @data:2020.09.28
 * @方法：
 *      1.定义Thread类的子类，并重写该类的run()方法
 *      2.创建Thread类的实例，即创建线程对象
 *      3.调用线程对象的start()方法来启动该线程
 * */

public class MyFirstThreadClass extends Thread{
    private int i;
    public void run()
    {
        for (  ; i < 100; i++)
            System.out.println(getName() + " " + i);
    }
    public static void main(String[] args)
    {
       for(var i =0; i < 100; i++)
       {
           System.out.println(Thread.currentThread().getName() + " " + i);          //Thread类的静态方法，返回正在执行的线程对象
           if (i == 20)
           {
               new MyFirstThreadClass().start();
               new MyFirstThreadClass().start();
           }
       }
    }
}