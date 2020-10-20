//��������
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct qnode
{
	int c;
	qnode(int _c = 0) : c(_c){};
	bool operator<(const qnode &r) const
	{
		return c > r.c;
	}
};
int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF)
	{
		int p1, p2;
		//�洢����ͼ
		vector<vector<int>> edges;
		//�洢ÿ���ڵ����
		vector<int> indegrees;
		//�洢��
		vector<int> result;
		edges.resize(n + 1);
		indegrees.resize(n + 1);
		for (int i = 0; i < m; i++)
		{
			scanf("%d%d", &p1, &p2);
			edges[p1].push_back(p2);
			indegrees[p2]++;
		}
		//���ȶ��д洢���Ϊ��ĵ�
		priority_queue<qnode> q;
		for(int i = 1; i < indegrees.size(); i++)
		{
			if(indegrees[i] == 0)
				q.push(i);
		}
		while(!q.empty())
		{
			int u = q.top().c;
			q.pop();
			result.push_back(u);
			for(int i = 0; i < edges[u].size(); i++)
			{
				indegrees[edges[u][i]]--;
				if(indegrees[edges[u][i]] == 0)
					q.push(edges[u][i]);
			}
		}
		printf("%d",result[0]);
		for(int i = 1; i < result.size(); i++)
			printf(" %d",result[i]);
		printf("\n");
	}
	return 0;
}
