package test;
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��9�� ����1:33:38
*/

public interface Queue {
	public int getSize();
	public boolean isEmpty();
	public void enqueue(Object e);
	public Object dequeue() throws QueueEmptyException;
	public Object peek() throws QueueEmptyException;
}
