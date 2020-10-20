 #include<cstdio> 
#include<cstring>
using namespace std;
const int MAX_LEN = 1e6;
int tree1[MAX_LEN];
int tree2[MAX_LEN];
void build_tree(int arr[], int tree[], int node, int start, int end)
{
	if(start == end)
	{
		tree[node] = arr[start];
	}
	else
	{
		int mid = (start + end) / 2;
		int left_node  = 2 * node + 1;
		int right_node = 2 * node + 2;
		build_tree(arr, tree, left_node, start, mid);
		build_tree(arr, tree, right_node, mid + 1, end);
		tree[node] = tree[left_node] + tree[right_node]; 
	}
}

//void update_tree(int arr[], int tree[], int node, int start, int end, int idx, int val)
//{
//	if(start == end)
//	{
//		arr[idx] = val;
//		tree[node] = val;
//	}
//	else
//	{
//		int mid = (start + end) / 2;
//		int left_node  = 2 * node + 1;
//		int right_node = 2 * node + 2;
//		if(idx >= start && idx <= mid)
//		{
//			update_tree(arr, tree, left_node, start, mid, idx, val);
//		}
//		else
//		{
//			update_tree(arr, tree, right_node, mid + 1, end, idx, val);
//		}
//		tree[node] = tree[left_node] + tree[right_node]; 		
//	}
//}
void update_tree(int tree[], int node, int start, int end, int idx)
{
	if(start == end)
	{
		tree[node]++;
	}
	else
	{
		int mid = (start + end) / 2;
		int left_node  = 2 * node + 1;
		int right_node = 2 * node + 2;
		if(idx >= start && idx <= mid)
		{
			update_tree(tree, left_node, start, mid, idx);
		}
		else
		{
			update_tree(tree, right_node, mid + 1, end, idx);
		}
		tree[node] = tree[left_node] + tree[right_node]; 		
	}
}
int query(int tree[], int node, int start, int end, int L, int R)
{
	if(R < start || L > end) 
	{
		return 0;
	} 
	else if(start == end || start >= L && end <= R)
	{
		return tree[node];
	}
	else
	{
		int mid = (start + end) / 2;
		int left_node  = 2 * node + 1;
		int right_node = 2 * node + 2;
		int sum_left = query(tree, left_node, start, mid, L, R);
		int sum_right = query(tree, right_node, mid + 1, end, L, R);
		return sum_left + sum_right;
	}
	
}

int main()
{
	int n, q;
	while(~scanf("%d%d", &n, &q))
	{
		memset(tree1, 0, sizeof(tree1));
		memset(tree2, 0, sizeof(tree2));
		int cnt = 0;
		while(q--)  
		{
			int op, L, R;
		
			scanf("%d%d%d", &op, &L, &R);
			if(op == 1) 
			{
				cnt++;
				update_tree(tree1, 0, 0, n - 1, L - 1);
				update_tree(tree2, 0, 0, n - 1, R - 1);
			}
			else
			{
				int num1 = query(tree1, 0, 0, n - 1, L, n - 1);
				int num2 = query(tree2, 0, 0, n - 1, 0, R - 1 - 1);
				printf("%d\n", cnt - num1 - num2);
			}
		}
	}
	return 0;
}
