#include <bits/stdc++.h>
#define MAX_VAL 1000000

using namespace std;

int N;
//long long segment_tree[MAX_VAL*4];

void update(int node, int start, int end, int index, long long diff, vector<long long> &segment_tree)
{
	//범위에 포함되지 않으면 주겨버려 
	if(!(start <= index && index <= end))
		return;
	
	segment_tree[node] += diff;
	
	if(start != end)
	{
		int mid=(start+end)/2;
		//왼쪽자식 들어가보리기 
		update(node*2, start, mid, index, diff, segment_tree);
		//오른쪽자식 들어가보리기 
		update(node*2+1, mid+1, end, index, diff, segment_tree);
	}
}

int query(int node, int start, int end, int value, vector<long long> &segment_tree)
{
	if(start == end)
	{
		cout<<start<<"\n";
		return start;
	}
	
	int mid = (start+end)/2;
	
	//왼쪽에 두두둥장 
	if(segment_tree[node*2] >= value)
		return query(node*2, start, mid, value, segment_tree);
	else
		return query(node*2+1, mid+1, end, value-segment_tree[node*2], segment_tree);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); 
	
	int A,B;
	long long C;
	vector<long long> segment_tree(MAX_VAL*4,0);
	
	cin>>N;
	
	for(int i=0 ; i<N ; i++)
	{
		cin>>A>>B;
		
		if(A==1)
		{
			int idx = query(1, 1, MAX_VAL, B, segment_tree);
			update(1, 1, MAX_VAL, idx, -1, segment_tree);	
		}
		else if(A==2)
		{
			cin>>C;
			
			update(1, 1, MAX_VAL, B, C, segment_tree);
		}
	}

}
