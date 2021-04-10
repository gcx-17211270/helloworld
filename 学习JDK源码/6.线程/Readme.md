<!--
 * @Descripttion: 
 * @version: 
 * @Author: 32353
 * @Date: 2021-04-09 12:37:05
 * @LastEditors: 32353
 * @LastEditTime: 2021-04-09 13:41:44
-->

# 线程相关

## 1.Java线程创建

### 1.1 不使用线程池

1. 直接继承Thread类，重写run方法
2. 通过java.lang.Runnable接口重写run方法，作为Thread类的一个参数创建新线程
3. 通过 Callable 和 Future 创建线程

前两种比较常见也是存在比较早的方法，Callable是在1.5版本后加入的方法，它的实现步骤有以下所示：

1. 创建 Callable 接口的实现类，并实现 call() 方法，该 call() 方法将作为线程执行体，并且有返回值。
2. 创建 Callable 实现类的实例，使用 FutureTask 类来包装 Callable 对象，该 FutureTask 对象封装了该 Callable 对象的 call() 方法的返回值。
3. 使用 FutureTask 对象作为 Thread 对象的 target 创建并启动新线程。
4. 调用 FutureTask 对象的 get() 方法来获得子线程执行结束后的返回值。

举个例子：

```Java
public class CallableThreadTest implements Callable<Integer> {
    public static void main(String[] args)  
    {  
        CallableThreadTest ctt = new CallableThreadTest();  
        FutureTask<Integer> ft = new FutureTask<>(ctt);  
        for(int i = 0;i < 100;i++)  
        {  
            System.out.println(Thread.currentThread().getName()+" 的循环变量i的值"+i);  
            if(i==20)  
            {  
                new Thread(ft,"有返回值的线程").start();  
            }  
        }  
        try  
        {  
            System.out.println("子线程的返回值："+ft.get());  
        } catch (InterruptedException e)  
        {  
            e.printStackTrace();  
        } catch (ExecutionException e)  
        {  
            e.printStackTrace();  
        }  
  
    }
    @Override  
    public Integer call() throws Exception  
    {  
        int i = 0;  
        for(;i<100;i++)  
        {  
            System.out.println(Thread.currentThread().getName()+" "+i);  
        }  
        return i;  
    }  
}
```

### 1.2 Java线程池

池化技术的思想主要是为了减少每次获取资源的消耗，提高对资源的利用率。

线程池提供了一种限制、管理资源的策略。 每个线程池还维护一些基本统计信息，例如已完成任务的数量。

使用线程池的好处：

1. 降低资源消耗：通过重复利用已创建的线程降低线程创建和销毁造成的消耗。
2. 提高响应速度：当任务到达时，可以不需要等待线程创建就能立即执行。
3. 提高线程的可管理性：线程是稀缺资源，如果无限制的创建，不仅会消耗系统资源，还会降低系统的稳定性，使用线程池可以进行统一的分配，监控和调优。

具体到Java代码中，在java.util.concurrent包中，提供了一系列对于程序并行的类。

1. Executor是一个顶层接口，声明了一个方法void execute(Runnable)，用来执行给定的任务
2. ExecutorService接口继承了Executor接口，并声明了一些二方法：submit、invokeAll、invokeAny以及shutDown等
3. 抽象类AbstractExecutorService实现了ExecutorService接口，基本实现了其中的所有方法。可以通过重写newTaskFor方法来更改任务
4. ThreadPoolExecutor继承了类AbstractExecutorService，它是线程池中最核心的一个类，通过对于BlockingQueue的不同实现，决定了对线程任务的调度方法。
5. Executors类，通过使用ThreadPoolExecutor的一个实现，可以创建四种线程池（但不推荐使用这种方法）。四种线程池分别为：newCachedThreadPool、newFixedThreadPool、newScheduledTreadPool、newSingleThreadExecutor。不推荐的原因是他们设置的允许创建线程数或请求队列长度上限为Integer.MAX_VALUE，容易导致内存溢出OOM

## 2.线程中的重要概念

### 2.1 线程同步

### 2.2 线程间通信

### 2.3 死锁

### 2.4 进程控制：挂起、恢复和停止
