package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月7日 下午2:08:16
*/

public class ListSLinked implements List {
	private Strategy strategy;	//数据元素比较策略
	private SLNode head;		//单链表首节点引用
	private int size;			//线性表中数据元素的个数
	public ListSLinked()
	{
		//this(new defaultStrategy());
		//显示没有DefaultStrategy()
	}
	public ListSLinked(Strategy strategy)
	{
		this.strategy = strategy;
		head = new SLNode();
		size = 0;
	}
	//辅助方法：获取数据元素e所在结点的前驱节点
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
	//辅助方法：获取序号为0<=i<size的元素所在节点的前驱结点
	private SLNode getPreNode(int i)
	{
		SLNode p = head;
		for(; i > 0; i--)p=p.getNext();
		return p;
	}
	//获得序号为0<=i<size的元素所在结点
	private SLNode getNode(int i)
	{
		SLNode p = head.getNext();
		for (; i > 0; i--) p = p.getNext();
		return p;
	}
	//返回线性表的大小，即数据元素的个数
	public int getSize()
	{
		return size;
	}
	//如果线性表为空返回true，否则返回false
	public boolean isEmpty()
	{
		return size == 0;
	}
	//判断线性表是否包含数据元素e
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
			throw new OutOfBoundaryException("错误，指定的输入越界");
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
			throw new OutOfBoundaryException("错误，指定的删除序号越界");
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
			throw new OutOfBoundaryException("错误，指定的序号越界");
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
