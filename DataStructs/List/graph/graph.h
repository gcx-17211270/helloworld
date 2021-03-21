/*****************************************************************//**
 * \file   graph.h
 * \brief  ͼ��ͷ�ļ�
 *			����ĺ��������
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

	//����ͼ�Ľṹ�����ڽӱ�ṹ
	typedef struct _Graph Graph;
	//���嶥��
	typedef struct _Vertex Vertex;
	//�����
	typedef struct _Edge Edge;
	
	typedef struct _DijkstraPath DijkstraPath;
	typedef struct _MinSpanningTree MinSpanningTree;

	//����߽���ֵ
	typedef void* EdgeValue;
	//���嶥����ֵ
	typedef void* VertexValue;

	typedef void (*tranverse_callback)(Vertex* v, int subGraphNo);
	struct _Edge {
		//�����ӵĶ���
		Vertex* vertices[2];
		EdgeValue value;
		//Ȩ��
		float weight;
	};

	//��������ṹ
	typedef struct _ListEntry ListEntry;
	//������Ľڵ�ṹ
	typedef void* ListValue;
	struct _SListEntry
	{
		ListValue data;
		ListEntry* next;
	};

	struct _Vertex {
		//�ڵ����
		int id;
		//�����붥����ͬ�������ı����ָ��
		ListEntry* edge;
		//�ڵ�����
		VertexValue value;
	};

	struct _DijkstraPath {
		float* pathCosts;
		int* vertexIds;
	};

	//ͼ����С������
	struct _MinSpanningTree {
		//��С�������Ĵ���
		float spanningTreeVost;
		ListEntry* edges;
	};
	//ͼ�Ľṹ
	struct _Graph {
		//ͼ�����ͣ�0����ͼ��1����ͼ
		GraphType graphType;
		//����ͱߵ�����
		unsigned int vertexNum;
		unsigned int edgeNum;
		//�����б�
		ListEntry* vertices;
		ListEntry* edges;
	};

	Graph* graph_new(GraphType type);
	//��ʼ��һ��ͼ
	void graph_initial(Graph* g);

	//����һ���µĽڵ�
	Vertex* (*add_new_vertex)(Graph* g, VertexValue value);

	//����һ���±�
	Edge* (*add_new_edge)(Graph* g, Vertex* sourceVertex, Vertex* targetVertex, EdgeValue value);

	//�����������
	void (*tranverse_bfs)(Graph* g, Vertex* firstVertex, tranverse_callback callBack);

	//�����������
	void (*tranverse_dfs)(Graph* g, Vertex* firstVertex, tranverse_callback callBack);

	//Prim�㷨
	MinSpanningTree* (*prim_spanning_tree)(Graph* g);

	//Kruskal�㷨
	MinSpanningTree* (*kruskal_spanning_tree)(Graph* g);

	//Dijkstra�㷨
	void (*dijkstra)(Graph* g, Vertex* start, DijkstraPath* path);

	//Floyd�㷨
	float** (*floyd)(Graph* g);

	//����һ��ͼ
	void (*graph_free)(Graph* g);

	//�ؼ�·���㷨
	int critical_path_method(Graph* g, Vertex* start, float* earlyTime, float* lateTime);
#ifdef __cpluscplus
}
#endif

#endif
