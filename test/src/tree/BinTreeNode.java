package tree;
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��15�� ����9:36:35
*/

public class BinTreeNode implements Node {

	private Object data;	//������
	private BinTreeNode parent;	//�����
	private BinTreeNode lChild;	//����
	private BinTreeNode rChild;	//�Һ���
	private int height;		//�Ըý��Ϊ���������ĸ߶�
	private int size;		//�Ըý��������(������㱾��)
	public BinTreeNode() {
		// TODO Auto-generated constructor stub
		this(null);
	}
	public BinTreeNode(Object e) {
		data = e;
		height = 0;
		size = 1;
		parent = lChild = rChild = null;
	}

	@Override
	public Object getData() {
		// TODO Auto-generated method stub
		return data;
	}

	@Override
	public void setData(Object a) {
		// TODO Auto-generated method stub
		data = a;
	}
	
	/******��������,�жϵ�ǰ���λ�����******/
	//�ж��Ƿ��и���
	public boolean hasParent()
	{
		return parent != null;
	}
	//�ж��Ƿ�������
	public boolean hasLChild()
	{
		return lChild != null;
	}
	//�ж��Ƿ����Һ���
	public boolean hasRChild()
	{
		return rChild != null;
	}
	//�ж��Ƿ�ΪҶ�ӽڵ�
	public boolean isLeaf()
	{
		return !hasLChild() && !hasRChild();
	}
	//�ж��Ƿ�Ϊĳ��������
	public boolean isLChild()
	{
		return (hasParent() && this == parent.lChild);
	}
	//�ж��Ƿ�Ϊĳ�����Һ���
	public boolean isRChild()
	{
		return hasParent() && this == parent.rChild;
	}

	/******��parent ��صķ���******/
	//ȡ�����
	public BinTreeNode getParent() { return parent; }
	//�Ͽ��븸�׵Ĺ�ϵ
	public void sever(){
	if (!hasParent()) return;
	if (isLChild()) parent.lChild = null;
	else parent.rChild = null;
	parent.updateHeight(); //���¸���㼰�����ȸ߶�
	parent.updateSize(); //���¸���㼰�����ȹ�ģ
	parent = null;
	}
	
	/******��lChild ��صķ���******/
	//ȡ����
	public BinTreeNode getLChild() { return lChild; }
	//���õ�ǰ��������,����ԭ����
	public BinTreeNode setLChild(BinTreeNode lc){
	BinTreeNode oldLC = this.lChild;
	if (hasLChild()) { lChild.sever();} //�Ͽ���ǰ��������Ĺ�ϵ
	if (lc!=null){
		lc.sever(); //�Ͽ�lc ���丸���Ĺ�ϵ
		this.lChild = lc; //ȷ�����ӹ�ϵ
		lc.parent = this;
		this.updateHeight(); //���µ�ǰ��㼰�����ȸ߶�
		this.updateSize(); //���µ�ǰ��㼰�����ȹ�ģ
	}
	return oldLC; //����ԭ����
	}
	
	/******��rChild ��صķ���******/
	//ȡ�Һ���
	public BinTreeNode getRChild() { return rChild; }
	//���õ�ǰ�����Һ���,����ԭ�Һ���
	public BinTreeNode setRChild(BinTreeNode rc){
	BinTreeNode oldRC = this.rChild;
	if (hasRChild()) { rChild.sever();} //�Ͽ���ǰ�Һ�������Ĺ�ϵ
	if (rc!=null){
		rc.sever(); //�Ͽ�lc ���丸���Ĺ�ϵ
		this.rChild = rc; //ȷ�����ӹ�ϵ
		rc.parent = this;
		this.updateHeight(); //���µ�ǰ��㼰�����ȸ߶�
		this.updateSize(); //���µ�ǰ��㼰�����ȹ�ģ
	}
	return oldRC; //����ԭ�Һ���
	}
	
	/******��height ��صķ���******/
	//ȡ���ĸ߶�,���Ըý��Ϊ�������ĸ߶�
	public int getHeight() {
		return height;
	}
	//���µ�ǰ��㼰�����ȵĸ߶�
	public void updateHeight()
	{
		int newH = 0;	//�¸߶ȳ�ʼ��Ϊ0,�߶ȵ������������߶ȼ�1 �еĴ���
		if (hasLChild()) newH = Math.max(newH, 1 + getLChild().getHeight());
		if (hasRChild()) newH = Math.max(new H, 1 + getRChild().getHeight());
		if (newH == height) return;
		height = newH;	
		if (hasParent()) getParent().updateHeight();
	}
	
	/******��size ��صķ���******/
	//ȡ�Ըý��Ϊ�������Ľ����
	public int getSize() { return size; }
	//���µ�ǰ��㼰�����ȵ�������
	public void updateSize()
	{
		size = 1;		//��ʼ��Ϊ1����㱾��
		if (hasLChild()) size += getLChild().getSize();
		if (hasRChild()) size += getRChild().getSize();
		if (hasParent()) getParent().updateSize();
	}
}
