package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月9日 上午1:33:38
*/

public interface Queue {
	public int getSize();
	public boolean isEmpty();
	public void enqueue(Object e);
	public Object dequeue() throws QueueEmptyException;
	public Object peek() throws QueueEmptyException;
}
