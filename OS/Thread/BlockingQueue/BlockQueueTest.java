package Thread.BlockingQueue;
/**
 * @ param     :    使用阻塞队列控制线程通信
 * @ return    :    Java5提供了一个BlockingQueue作为Queue的子接口，但它的主要作用不是作为容器，
 *              而是作为线程同步的工具。BlockingQueue有一个特征：当生产者线程试图向BlockingQueue
 *              中放入元素时，如果该队列已满，则该线程被阻塞；当消费者线程试图向BlockingQueue中
 *              取出元素时，如果队列为空，则该线程被阻塞。
 *                  BlockinQueue通过交替向BlockingQueue中放入、取出元素，即可很好地控制线程的通信。
 * @ Description:
 * @ Date       :2020/9/30 11:13
 * @ author     :32353
*/

public class BlockQueueTest {
    public static void main(String[] args) throws Exception
    {
        //定义一个长度为2的阻塞队列
        java.util.concurrent.BlockingQueue<String> bq = new java.util.concurrent.ArrayBlockingQueue<>(2);
        bq.put("java");
        bq.put("java");
        bq.put("Java");
    }
}
