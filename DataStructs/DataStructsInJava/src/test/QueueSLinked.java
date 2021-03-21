package test;
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��9�� ����2:00:09
*/

public class QueueSLinked implements Queue {
	private SLNode front;
	private SLNode rear;
	private int size;
	public QueueSLinked() {
		// TODO Auto-generated constructor stub
		front = new SLNode();
		rear = front;
		size = 0;
	}

	@Override
	public int getSize() {
		// TODO Auto-generated method stub
		return size;
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return size == 0;
	}

	@Override
	public void enqueue(Object e) {
		// TODO Auto-generated method stub
		SLNode p = new SLNode(e,null);
		rear.setNext(p);
		rear = p;
		size++;
	}

	@Override
	public Object dequeue() throws QueueEmptyException {
		// TODO Auto-generated method stub
		if (size < 1)
			throw new QueueEmptyException("���󣬶���Ϊ��");
		SLNode p = front.getNext();
		front.setNext(p.getNext());
		return p.getData();
	}

	@Override
	public Object peek() throws QueueEmptyException {
		// TODO Auto-generated method stub
		if (size < 1)
			throw new QueueEmptyException("���󣬶���Ϊ��");
		return front.getNext().getData();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
