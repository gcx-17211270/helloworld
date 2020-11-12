package test;
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��7�� ����2:08:16
*/

public class ListSLinked implements List {
	private Strategy strategy;	//����Ԫ�رȽϲ���
	private SLNode head;		//�������׽ڵ�����
	private int size;			//���Ա�������Ԫ�صĸ���
	public ListSLinked()
	{
		//this(new defaultStrategy());
		//��ʾû��DefaultStrategy()
	}
	public ListSLinked(Strategy strategy)
	{
		this.strategy = strategy;
		head = new SLNode();
		size = 0;
	}
	//������������ȡ����Ԫ��e���ڽ���ǰ���ڵ�
	private SLNode getPreNode(Object e)
	{
		SLNode p = head;
		while(p.getNext() != null)
		{
			if (strategy.equal(p.getNext().getData(), e))
				return p;
			else p = p.getNext();
		}
		return null;
	}
	//������������ȡ���Ϊ0<=i<size��Ԫ�����ڽڵ��ǰ�����
	private SLNode getPreNode(int i)
	{
		SLNode p = head;
		for(; i > 0; i--)p=p.getNext();
		return p;
	}
	//������Ϊ0<=i<size��Ԫ�����ڽ��
	private SLNode getNode(int i)
	{
		SLNode p = head.getNext();
		for (; i > 0; i--) p = p.getNext();
		return p;
	}
	//�������Ա�Ĵ�С��������Ԫ�صĸ���
	public int getSize()
	{
		return size;
	}
	//������Ա�Ϊ�շ���true�����򷵻�false
	public boolean isEmpty()
	{
		return size == 0;
	}
	//�ж����Ա��Ƿ��������Ԫ��e
	public boolean contains(Object e)
	{
		SLNode p = head.getNext();
		while (p != null)
			if (strategy.equal(p.getData(), e)) return true;
			else p = p.getNext();
		return false;
	}
	/************************************/
	

	@Override
	public int indexOf(Object e) {
		// TODO Auto-generated method stub
		SLNode p = head.getNext();
		int index = 0;
		while (p != null)
			if (strategy.equal(p.getData(), e)) return index;
			else {
				index++;
				p = p.getNext();
			}
		return -1;
	}

	@Override
	public void insert(int i, Object e) throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		if (i < 0 || i > size)
			throw new OutOfBoundaryException("����ָ��������Խ��");
		SLNode p = getPreNode(i);
		SLNode q = new SLNode(e, p.getNext());
		p.setNext(q);
		size++;
		return;
	}

	@Override
	public boolean insertBefore(Object obj, Object e) {
		// TODO Auto-generated method stub
		SLNode p = getPreNode(obj);
		if (p != null) {
			SLNode q = new SLNode(e,p.getNext());
			p.setNext(q);
			size++;
			return true;
		}
		return false;
	}

	@Override
	public boolean insertAfter(Object obj, Object e) {
		// TODO Auto-generated method stub
		SLNode p = head.getNext();
		while (p != null)
			if (strategy.equal(p.getData(), obj))
			{
				SLNode q = new SLNode(e, p.getNext());
				p.setNext(q);
				size++;
				return true;
			}
			else p = p.getNext();
		return false;
	}

	@Override
	public Object remove(int i) throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		if (i < 0 || i > size)
			throw new OutOfBoundaryException("����ָ����ɾ�����Խ��");
		SLNode p = getPreNode(i);
		Object obj = p.getNext().getData();
		p.setNext(p.getNext().getNext());
		size--;
		return obj;
	}

	@Override
	public boolean remove(Object e) {
		// TODO Auto-generated method stub
		SLNode p = getPreNode(e);
		if (p != null) {
			p.setNext(p.getNext().getNext());
			size--;
			return true;
		}
		return false;
	}

	@Override
	public Object replace(int i, Object e) throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		if (i < 0 || i > size)
			throw new OutOfBoundaryException("����ָ�������Խ��");
		SLNode p = getNode(i);
		Object obj = p.getData();
		p.setData(e);
		return obj;
	}

	@Override
	public Object get(int i) throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		if (i < 0 || i > size)
			throw new OutOfBoundaryException("Error");
		SLNode p = getNode(i);
		return p.getData();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
