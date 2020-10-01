package Thread;
/**
 * @ param     :    线程睡眠：Sleep
 * @ return    :
 * @ Description:   在当前进程调用sleep()方法进入阻塞状态后，在其睡眠时间段内，该线程不会获得执行的机会
 *              即使该系统中没有其他可执行的线程。因此sleep()方法常用来暂停程序的执行。
 *                  下面的程序中调用sleep()来暂停主线程的执行，因为该程序只有一个主线程，当主线程进入睡眠
 *              之后，系统就没有其他可执行的线程，所以程序在sleep()方法处暂停。
 *                  Thread类还提供一个与sleep()方法有些类似的yield()静态方法，它也可以让当前正在执行的线程
 *              暂停，但它不会阻塞该线程，它只是将该进程转入就绪状态，yield()只是让当前进程暂停一下，让系统
 *              的线程调度器重新调整一次。完全可能的结果是：当某个线程调用了yield()方法暂停后，线程调度器又
 *              将其调度出来重新执行。
 * @ Date       :2020/9/29 10:03
 * @ author     :32353
*/

public class SleepTest {
    public static void main(String[] args) throws Exception
    {
        for (var i = 0; i < 10; i++)
        {
            System.out.println("当前时间： " + new java.util.Date());
            //调用sleep()方法让当前线程暂停1s
            Thread.sleep(1000);
        }
    }
}
