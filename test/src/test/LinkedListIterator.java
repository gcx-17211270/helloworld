package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月7日 下午5:17:11
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
			throw new OutOfBoundaryException("错误，已没有元素。");
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
			throw new OutOfBoundaryException("错误：已经没有元素。");
			return current.getData();
		// TODO Auto-generated method stub
	}

}
