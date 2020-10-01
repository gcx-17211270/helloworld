package Thread;
/**
 * @ param     :    改变线程优先级
 * @ return    :
 * @ Description:   每个线程的默认优先级与创建它的父线程的优先级相同。在相同的情况下，main线程具有
 *              普通优先级。Thread类提供setPriority(int newPriority)、getPriority()方法来设置和返回
 *              指定线程的优先级。
*                  setPriority()的参数是一个整数，范围是1-10之间，也可以使用Thread类的如下三个静态常量；
 *                  MAX_PRIORITY    : 其值为10
 *                  MIN_PRIORITY    : 其值为1
 *                  NORM_PRIORITY   : 其值为5
 *                  下面程序使用了setPriorty()方法来改变主进程的优先级，并使用该方法改变了两个线程的
 *              优先级，从而可以看到高优先级的线程将会获得更多的执行机会。
 * @ Date       :2020/9/29 10:15
 * @ author     :32353
*/

public class PriorityTest extends Thread{
    //定义一个有参数的构造器，用来指定name
    public PriorityTest(String name)
    {
        super(name);
    }
    public void run()
    {
        for (var i = 0; i < 50; i++)
        {
            System.out.println(getName() + ",其优先级是：" + getPriority()
                            + ", 循环变量的值为: " + i);
        }
    }
    public static void main(String[] args)
    {
        //改变主进程的优先级
        Thread.currentThread().setPriority(6);
        System.out.println(PriorityTest.class);
        for (var i = 0; i < 30; i++)
        {
            System.out.println(Thread.currentThread().getName() + " " + i);
            if (i == 10)
            {
                var low = new PriorityTest("低级");
                low.start();
                System.out.println("创建之初的优先级：" + low.getPriority());
                //设置该线程为最低优先级
                low.setPriority(Thread.MIN_PRIORITY);
            }
            if (i == 20)
            {
                var high = new PriorityTest("高级");
                high.start();
                System.out.println("创建之初的优先级是：" + high.getPriority());
                //设置该线程为最高优先级
                high.setPriority(Thread.MAX_PRIORITY);
            }
        }
    }
}
