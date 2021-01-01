/*****************************************************************//**
 * \file   graph.h
 * \brief  图的头文件
 *			具体的函数待完成
 * 
 * \author 32353
 * \date   December 2020-12-16 19:33 
 *********************************************************************/
#pragma once
#ifndef __GRAPH_H_HELLO_QIU__
#define __GRAPH_H_HELLO_QIU__

#ifdef __cpluscplus
extern "C"
{
#endif
	typedef enum 
	{
		GRAPH_UNDIRECTED = 0,
		GRAPH_DIRECTED = 1
	}GraphType;

	//定义图的结构，用邻接表结构
	typedef struct _Graph Graph;
	//定义顶点
	typedef struct _Vertex Vertex;
	//定义边
	typedef struct _Edge Edge;
	
	typedef struct _DijkstraPath DijkstraPath;
	typedef struct _MinSpanningTree MinSpanningTree;

	//定义边界数值
	typedef void* EdgeValue;
	//定义顶点数值
	typedef void* VertexValue;

	typedef void (*tranverse_callback)(Vertex* v, int subGraphNo);
	struct _Edge {
		//边连接的顶点
		Vertex* vertices[2];
		EdgeValue value;
		//权重
		float weight;
	};

	//单向链表结构
	typedef struct _ListEntry ListEntry;
	//单链表的节点结构
	typedef void* ListValue;
	struct _SListEntry
	{
		ListValue data;
		ListEntry* next;
	};

	struct _Vertex {
		//节点序号
		int id;
		//访问与顶点相同的相连的边入口指针
		ListEntry* edge;
		//节点数据
		VertexValue value;
	};

	struct _DijkstraPath {
		float* pathCosts;
		int* vertexIds;
	};

	//图的最小生成树
	struct _MinSpanningTree {
		//最小生成树的代价
		float spanningTreeVost;
		ListEntry* edges;
	};
	//图的结构
	struct _Graph {
		//图的类型，0无向图，1有向图
		GraphType graphType;
		//顶点和边的数量
		unsigned int vertexNum;
		unsigned int edgeNum;
		//顶点列表
		ListEntry* vertices;
		ListEntry* edges;
	};

	Graph* graph_new(GraphType type);
	//初始化一个图
	void graph_initial(Graph* g);

	//加入一个新的节点
	Vertex* (*add_new_vertex)(Graph* g, VertexValue value);

	//加入一条新边
	Edge* (*add_new_edge)(Graph* g, Vertex* sourceVertex, Vertex* targetVertex, EdgeValue value);

	//广度优先搜索
	void (*tranverse_bfs)(Graph* g, Vertex* firstVertex, tranverse_callback callBack);

	//深度优先搜索
	void (*tranverse_dfs)(Graph* g, Vertex* firstVertex, tranverse_callback callBack);

	//Prim算法
	MinSpanningTree* (*prim_spanning_tree)(Graph* g);

	//Kruskal算法
	MinSpanningTree* (*kruskal_spanning_tree)(Graph* g);

	//Dijkstra算法
	void (*dijkstra)(Graph* g, Vertex* start, DijkstraPath* path);

	//Floyd算法
	float** (*floyd)(Graph* g);

	//销毁一个图
	void (*graph_free)(Graph* g);

	//关键路径算法
	int critical_path_method(Graph* g, Vertex* start, float* earlyTime, float* lateTime);
#ifdef __cpluscplus
}
#endif

#endif
