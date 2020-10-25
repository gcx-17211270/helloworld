package test;

/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月7日 上午3:27:22
*/

public class ListArray implements List{
	private final int LEN = 8;
	private Strategy strategy;
	private int size;
	private Object[] elements;
	public ListArray()
	{
		//this(new DefaultStrategy());
	}
	public ListArray(Strategy strategy)
	{
		this.strategy = strategy;
		size = 0;
		elements = new Object[LEN];
	}
	public int getSize()
	{
		return size;
	}
	public boolean contains(Object e)
	{
		for (int i = 0; i < size; i++)
			if (strategy.equal(e, elements[i])) return true;
		return false;
	}
	public int indexOf(Object e)
	{
		for (int i = 0; i < size; i++)
			if (strategy.equal(e, elements[i])) return i;
		return -1;
	}
	public void insert(int i, Object e)throws OutOfBoundaryException
	{
		if (i < 0 || i > size)
			throw new OutOfBoundaryException("错误，指定的插入序号越界");
		if (size >= elements.length)
			expandSpace();
		for (int j = size; j > i; j--)
			elements[j] = elements[j-1];
		elements[i] = e;
		size++;
		return;
	}
	private void expandSpace()
	{
		Object[] a = new Object[elements.length*2];
		for (int i = 0; i < elements.length; i++)
			a[i] = elements[i];
		elements = a;
	}
	public boolean insertBefore(Object obj, Object e)
	{
		int i = indexOf(obj);
		if (i < 0) return false;
		try {
			insert(i, e);
		} catch (OutOfBoundaryException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		return true;
	}
	public boolean insertAfter(Object obj, Object e)
	{
		int i = indexOf(obj);
		if (i < 0) return false;
		try {
			insert(i+1, e);
		} catch (OutOfBoundaryException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		return true;
	}
	public Object remove(int i) throws OutOfBoundaryException
	{
		if (i < 0 || i >= size)
			throw new OutOfBoundaryException("错误，指定的删除序号越界");
		Object obj = elements[i];
		for (int j = i; j < size - 1; j++)
			elements[j] = elements[j + 1];
		elements[--size] = null;
		return obj;
	}
	public boolean remove(Object e)
	{
		int i = indexOf(e);
		if (i < 0) return false;
		try {
			remove(i);
		} catch (OutOfBoundaryException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		return true;
	}
	public Object replace(int i, Object e)throws OutOfBoundaryException
	{
		if (i < 0 || i >= size)
			throw new OutOfBoundaryException("错误，指定的序号越界");
		Object obj = elements[i];
		elements[i] = e;
		return obj;
	}
	public Object Get(int i) throws OutOfBoundaryException
	{
		if (i < 0 || i >= size)
			throw new OutOfBoundaryException("错误，指定的序号越界");
		return elements[i];
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ListArray la = new ListArray();
		System.out.println(args);
		System.out.println(la.size);
		System.out.println(la.contains(args));
		/*
		Object a = new Object();
		a = 2;
		try {
			la.insert(0, a);
		} catch (OutOfBoundaryException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
		for(Object e : la.elements)
			System.out.println(e);
		*/
	}
	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return false;
	}
	@Override
	public Object get(int i) throws OutOfBoundaryException {
		// TODO Auto-generated method stub
		return null;
	}

}
