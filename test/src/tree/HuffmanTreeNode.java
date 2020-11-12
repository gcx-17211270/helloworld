package tree;
/**
*@author 作者 高成鑫
*@Version 创建时间:2020年4月22日 上午11:54:57
*/

public class HuffmanTreeNode extends BinTreeNode {

	private int weight;					//权值
	private String coding = "";			//编码
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
		List l = new ListArray();		//根结点线性表，按weight从大到小排序
		for (int i = 0; i < n; i++)		//讲结点逐一插入线性表
		{
			insertToList(l, nodes[i]);
		}
		for (int i = 1; i < n; i++)		//选择weight最小的两棵树合并，循环n-1次
		{
			HuffmanTreeNode min1 = (HuffmanTreeNode)l.remove(l.getSize() - 1);
			HuffmanTreeNode min2 = (HuffmanTreeNode)l.remove(l.getSize() - 1);
			HuffmanTreeNode newRoot = new HuffmanTreeNode(min1.getWeight() + min2.getWeight());
			newRoot.setLChild(min1);		
			newRoot.setRChild(min2);			//合并
			insertToList(l, newRoot);			//将新树插入线性表
		}
		return (HuffmanTreeNode)l.get(0);		//返回Huffman树的根
	}
	
	//将结点按照weight从大到小的顺序插入线性表
	private static void insertToList(List l, HuffmanTreeNode node) {
		for (int j = 0; j < l.getSize(); j++)
			if (node.getWeight() > ((HuffmanTreeNode)l.get(j)).getWeight()) {
				l.insert(j, node);
				return;
			}
	}
	
	//利用Huffman树可以递归产生Huffman编码
	public static void generateHuffmanCode(HuffmanTreeNode root){
		if (root == null) return;
		if (root.hasParent()) {
			if (root.isLChild())
				root.setCoding(root.getParent().getCoding() + "0");	//向左为0
			else
				root.setCoding(root.getParent().getCoding() + "1");
		}
		generateHuffmanCode(root.getLChild());
		generateHuffmanCode(root.getRChild());
	}
}
