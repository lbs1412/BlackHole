#include"data_caculate.h"

//----------------------------------------------
int movex[4] = { 1,0,-1,0 };
int movey[4] = { 0,-1,0,1 };


std::set<node>visit_set;
std::vector<Shape>shape_vector;
//----------------------------------------------
bool cmp(node a, node b)
{
	if (a.x < b.x)return true;
	else if (a.x == b.x&&a.y < b.y)return true;
	return false;
}

bool isOK(int x, int y,int N,int M)
{
	if (x >= N || x < 0 || y >= M || y < 0)return false;
	return true;
}
//-----------------------------------------------
void Dfs(node x,std::vector<std::vector<bool>>G, int a, int&l, int&t,int N,int M)
{
	visit_set.insert(x);
	for (int i = 0; i < 4; i++)
	{
		node temp(x.x + movex[i], x.y + movey[i]);
		if (isOK(temp.x, temp.y,N,M) && G[temp.x][temp.y] && !visit_set.count(temp))
		{
			if (temp.x < l)
			{
				l = temp.x;
			}
			if (temp.y < t)
			{
				t = temp.y;
			}
			shape_vector[a].Node.push_back(temp);
			shape_vector[a].number++;
			Dfs(temp,G, a, l, t,N,M);
		}
	}
}

//-----------------------------------------------
result get_data(std::vector<std::vector<bool>>G)
{
	visit_set.clear();
	shape_vector.clear();

	int N = G.size();
	int M = G[0].size();
	

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			node temp(i, j);
			if (!visit_set.count(temp) && G[i][j])
			{
				int L = i;
				int T = j;
				Shape Temp;
				shape_vector.push_back(Temp);
				int Num = shape_vector.size() - 1;
				shape_vector[Num].Node.push_back(temp);
				shape_vector[Num].number = 1;
				Dfs(temp, G, Num, L, T, N, M);
				for (int q = 0; q < shape_vector[Num].Node.size(); q++)
				{
					shape_vector[Num].Node[q].x = shape_vector[Num].Node[q].x - L;
					shape_vector[Num].Node[q].y = shape_vector[Num].Node[q].y - T;
				}
				sort(shape_vector[Num].Node.begin(), shape_vector[Num].Node.end(), cmp);
			}
		}
	}

	result R(shape_vector.size(), 0, 0);

	std::vector<bool>diff_area;
	std::vector<bool>diff_shape;
	
	diff_area.resize(N + 20);
	diff_shape.resize(N + 20);

	for (int i = 0; i < N*M+20; i++)
	{
		diff_area.push_back(false);
		diff_shape.push_back(false);
	}

	for (int i = 0; i < shape_vector.size(); i++)
	{
		if (!diff_area[shape_vector[i].number])
		{
			R.num_of_diffarea_blackhole++;
			diff_area[shape_vector[i].number] = true;
		}
	}
	for (int i = 0; i < shape_vector.size(); i++)
	{
		if (!diff_shape[i])
		{
			diff_shape[i] = true;
			R.num_of_diffshap_blackhole++;
			for (int j = i + 1; j < shape_vector.size(); j++)
			{
				if (shape_vector[i] == shape_vector[j])
				{
					diff_shape[j] = true;
				}
			}
		}
	}

	return R;

}


