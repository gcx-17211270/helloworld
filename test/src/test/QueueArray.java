package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月9日 上午1:36:23
*/

public class QueueArray implements Queue {
	public static final int CAP = 7;
	private Object[] elements;
	private int capacity;
	private int front;
	private int rear;
	public QueueArray() {
		// TODO Auto-generated constructor stub
		this(CAP);
	}
	public QueueArray(int cap)
	{
		capacity = cap + 1;
		elements = new Object[capacity];
		front = rear = 0;
	}

	@Override
	public int getSize() {
		// TODO Auto-generated method stub
		return (rear - front + capacity) % capacity;
	}
	public void enqueue(Object e)
	{
		if (getSize() == capacity - 1) expandSpace();
		elements[rear] = e;
		rear = (rear + 1) % capacity;
	}
	private void expandSpace()
	{
		Object[] a = new Object[elements.length * 2];
		int i = front;
		int j = 0;
		while (i != rear)
		{
			a[j++] = elements[i];
			i = (i + 1) % capacity;
		}
		elements = a;
		capacity = elements.length;
		front = 0;
		rear = j;
	}
	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return front == rear;
	}

	@Override
	public Object dequeue() throws QueueEmptyException {
		// TODO Auto-generated method stub
		if (isEmpty())
			throw new QueueEmptyException("错误，队列为空");
		Object obj = elements[front];
		elements[front] = null;
		front = (front + 1) % capacity;
		return obj;
	}

	@Override
	public Object peek() throws QueueEmptyException {
		// TODO Auto-generated method stub
		if (isEmpty())
			throw new QueueEmptyException("错误，队列为空");
		return elements[front];
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Queue q = new QueueArray();
		//System.out.println(q.dequeue());
	}
}
