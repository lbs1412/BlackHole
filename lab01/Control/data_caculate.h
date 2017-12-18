#pragma once
#include "../stdafx.h"
typedef struct _result
{
	int num_of_blackhole;
	int num_of_diffarea_blackhole;
	int num_of_diffshap_blackhole;
	_result(){}
	_result(int a,int b,int c):num_of_blackhole(a),num_of_diffarea_blackhole(b),num_of_diffshap_blackhole(c){}
}result;

typedef struct _node
{
	int x, y;
	_node(int a, int b) :x(a), y(b) {}
	bool friend operator<(_node a, _node b)
	{
		if (a.x < b.x)return true;
		else if (a.x == b.x&&a.y < b.y)return true;
		return false;
	}
}node;

typedef struct _shape
{
	std::vector<node>Node;
	int number;
	bool friend operator==(_shape a, _shape b)
	{
		if (a.number != b.number)return false;
		for (int i = 0; i < a.number; i++)
		{
			if (a.Node[i].x != b.Node[i].x || a.Node[i].y != b.Node[i].y)return false;
		}
		return true;
	}
}Shape;



bool cmp(node a, node b);
void Dfs(node x,std::vector<std::vector<bool>>G, int a, int&l, int&t,int N,int M);
bool isOK(int x, int y, int N, int M);
result get_data(std::vector<std::vector<bool>>);



