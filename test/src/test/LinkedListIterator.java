package test;
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��7�� ����5:17:11
*/

public class LinkedListIterator implements Iterator {
	private LinkedList list;
	private Node current;
	public LinkedListIterator(LinkedList list)
	{
		this.list = list;
		if (list.isEmpty())
			current = null;
		else current = list.first();
	}
	@Override
	public void first() {
		// TODO Auto-generated method stub
		if (list.isEmpty())
			current = null;
		else current = list.first();
	}

	@Override
	public void next() throws OutOfBoundaryException{
		// TODO Auto-generated method stub
		if(isDone())
			throw new OutOfBoundaryException("������û��Ԫ�ء�");
		if (current == list.last()) current = null;
		else current = list.getNext(current);
	}

	@Override
	public boolean isDone() {
		// TODO Auto-generated method stub
		return current == null;
	}

	@Override
	public Object currentItem() throws OutOfBoundaryException{
		if (isDone())
			throw new OutOfBoundaryException("�����Ѿ�û��Ԫ�ء�");
			return current.getData();
		// TODO Auto-generated method stub
	}

}
