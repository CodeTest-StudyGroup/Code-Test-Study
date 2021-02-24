#include<bits/stdc++.h>

using namespace std;

struct Data{
	int idx;
	int color;
	int size;
	
	Data(int i, int c , int s)
	{
		idx=i;
		color=c;
		size=s;
	}
	
	bool operator<(const Data& b)const{
		if(size != b.size)
			return size<b.size;
		else
			return color<b.color;
	}
};
int main()
{
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	int N;
	
    cin>>N;
    
   	vector<Data> data;
   	vector<int> color_set[N];
   	
   	for(int i=0 ; i<N ; i++)
   	{
		int color,size;
		
		cin>>color>>size;
		
		data.push_back(Data(i,color,size));   
	
		color_set[color-1].push_back(size);
	
	}
	
	sort(data.begin(),data.end());
	
	int color_sum[N];
	
	color_sum[0]=data[0].size;
	
	for(int i=1 ; i<data.size() ; i++)
		color_sum[i] = color_sum[i-1]+data[i].size;
	
	for(int i=0 ; i<N ; i++)
	{
		sort(color_set[i].begin(),color_set[i].end());
		
		for(int j=1 ; j<color_set[i].size() ; j++)
		{
			color_set[i][j] = color_set[i][j-1]+color_set[i][j];
		}
	}
	
	int idx_arr[N];
	int res[N];
	int size_check[2001];
	
	fill(idx_arr,idx_arr+N,0);
	fill(res,res+N,0);
	
	for(int i=0 ; i<N ; i++)
	{
		int idx = idx_arr[data[i].color-1]++;
		
		res[data[i].idx] = color_sum[i] - color_set[data[i].color-1][idx];
		
		int temp_i=i;
		while(temp_i>0 && data[i].size == data[temp_i-1].size)
		{
			temp_i--;
			if(data[i].color!=data[temp_i].color)
				res[data[i].idx]-=data[temp_i].size;
		}
	}	
	
	for(int i=0 ; i<N ; i++)
		cout<<res[i]<<"\n";
	
	
    
    
}



