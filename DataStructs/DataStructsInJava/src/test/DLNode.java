package test;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月7日 下午12:32:05
*/

public class DLNode implements Node {
	private Object element;
	private DLNode pre;
	private DLNode next;
	public DLNode()
	{
		this(null, null, null);
	}
	public DLNode(Object ele, DLNode pre, DLNode next)
	{
		this.element = ele;
		this.pre = pre;
		this.next = next;
	}
	public DLNode getNext()
	{
		return next;
	}
	public void setNext(DLNode next)
	{
		this.next = next;
	}
	public DLNode getPre()
	{
		return pre;
	}
	public void setPre(DLNode pre)
	{
		this.pre = pre;
	}
	/**********************Node Interface Method**********************/
	@Override
	public Object getData() {
		// TODO Auto-generated method stub
		return element;
	}
	
	@Override
	public void setData(Object obj) {
		// TODO Auto-generated method stub
		element = obj;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		DLNode dln = new DLNode(2,null,null);
		DLNode dLN = new DLNode(521,dln,null);
		dln.setData(5);
		dLN.setPre(dln);
		System.out.println(dLN.pre.element);
	}

}
