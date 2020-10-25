package tree;
/**
*@author ���� �߳���
*@Version ����ʱ��:2020��4��22�� ����11:54:57
*/

public class HuffmanTreeNode extends BinTreeNode {

	private int weight;					//Ȩֵ
	private String coding = "";			//����
	//public HuffmanTreeNode() {
		// TODO Auto-generated constructor stub
	//}
	public HuffmanTreeNode(int weight)
	{
		this(weight, null);
	}
	public HuffmanTreeNode(int weight, Object e)
	{
		super(e);
		this.weight = weight;
	}

	public HuffmanTreeNode(Object e) {
		super(e);
		// TODO Auto-generated constructor stub
	}

	public HuffmanTreeNode getParent()
	{
		return (HuffmanTreeNode)super.getParent();
	}
	public HuffmanTreeNode getLChild()
	{
		return (HuffmanTreeNode)super.getLChild();
	}
	public HuffmanTreeNode getRChild()
	{
		return (HuffmanTreeNode)super.getRChild();
	}
	public int getWeight()
	{
		return weight;
	}
	public String getCoding()
	{
		return coding;
	}
	public void setCoding(String coding)
	{
		this.coding = coding;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		HuffmanTreeNode[] nodes = new HuffmanTreeNode[10];
		buildHuffmanTree(nodes);
	}
	public static HuffmanTreeNode buildHuffmanTree(HuffmanTreeNode[] nodes)
	{
		int n = nodes.length;
		if (n < 2) return nodes[0];
		List l = new ListArray();		//��������Ա���weight�Ӵ�С����
		for (int i = 0; i < n; i++)		//�������һ�������Ա�
		{
			insertToList(l, nodes[i]);
		}
		for (int i = 1; i < n; i++)		//ѡ��weight��С���������ϲ���ѭ��n-1��
		{
			HuffmanTreeNode min1 = (HuffmanTreeNode)l.remove(l.getSize() - 1);
			HuffmanTreeNode min2 = (HuffmanTreeNode)l.remove(l.getSize() - 1);
			HuffmanTreeNode newRoot = new HuffmanTreeNode(min1.getWeight() + min2.getWeight());
			newRoot.setLChild(min1);		
			newRoot.setRChild(min2);			//�ϲ�
			insertToList(l, newRoot);			//�������������Ա�
		}
		return (HuffmanTreeNode)l.get(0);		//����Huffman���ĸ�
	}
	
	//����㰴��weight�Ӵ�С��˳��������Ա�
	private static void insertToList(List l, HuffmanTreeNode node) {
		for (int j = 0; j < l.getSize(); j++)
			if (node.getWeight() > ((HuffmanTreeNode)l.get(j)).getWeight()) {
				l.insert(j, node);
				return;
			}
	}
	
	//����Huffman�����Եݹ����Huffman����
	public static void generateHuffmanCode(HuffmanTreeNode root){
		if (root == null) return;
		if (root.hasParent()) {
			if (root.isLChild())
				root.setCoding(root.getParent().getCoding() + "0");	//����Ϊ0
			else
				root.setCoding(root.getParent().getCoding() + "1");
		}
		generateHuffmanCode(root.getLChild());
		generateHuffmanCode(root.getRChild());
	}
}
