package Thread;

import java.util.concurrent.Callable;
import java.util.concurrent.FutureTask;

/**
 * 创建并启动有返回值的线程
 * @data:2020.09.28
 * @author 32353
 * @方法：
 *          1.创建Callable接口的实现类，并实现call()方法，该call()方法作为线程执行体，
 *      该call()方法有返回值，在创建Callable实现类的实例。从Java8开始，可以直接使用
 *      Lambda表达式创建Callable对象。
 *          2.使用FutureTask类来包装Callable对象，该FutureTask对象封装了该Callable对象
 *      的call()方法的返回值
 *          3.使用FutureTask对象作为Thread对象的target创建并启动新线程
 *          4.调用FutureTask对象的get()方法来获得子线程执行结束后的返回值
 * */

public class ThirdThread {
    public static void main(String[] args)
    {
        var rt = new ThirdThread();
        FutureTask<Integer> task = new FutureTask<>((Callable<Integer>)()->{
            var i = 0;
            for ( ; i < 100; i++)
            {
                System.out.println(Thread.currentThread().getName() + " " + i);
            }
            return i;
        });

        for (var i = 0; i < 100; i++)
        {
            System.out.println(Thread.currentThread().getName() + " " + i);
            if (i == 20){
                new Thread(task, "有返回值的线程").start();
            }
        }

        try
        {
            System.out.println("子线程的返回值：" + task.get());
        }
        catch (Exception ex)
        {
            ex.printStackTrace();
        }
    }
}
