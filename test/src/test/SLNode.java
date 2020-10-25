package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月7日 上午11:49:09
*/

public class SLNode {
	private Object element;
	private SLNode next;
	
	public SLNode()
	{
		this(null, null);
	}
	public SLNode(Object ele, SLNode next)
	{
		this.element = ele;
		this.next = next;
	}
	public SLNode getNext()
	{
		return next;
	}
	public void setNext(SLNode next)
	{
		this.next = next;
	}
	
	/****************Methods of Node Interface******************/
	public Object getData()
	{
		return element;
	}
	public void setData(Object obj)
	{
		element = obj;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		SLNode sln1 = new SLNode(1,null);
		sln1.setData("Hello world!");
		//Object a = new Object();
		SLNode sln = new SLNode(2,sln1);
		System.out.println(sln.next.element);
	}

}
