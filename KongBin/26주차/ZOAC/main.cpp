#include <bits/stdc++.h>

using namespace std;

int N;

int visited[105];
string copy_str="";

void print_str()
{
	for(int i=0 ; i<copy_str.size() ; i++)
	{
		if(visited[i]==1)
			cout<<copy_str[i];
	}
	cout<<"\n";
}

void DFS(string &str, int start_idx)
{
	int min_idx = min_element(str.begin()+start_idx, str.end())-str.begin();
	
	if(str[min_idx]=='a')
		return;
	else
	{
		visited[min_idx]=1;
		str[min_idx]='a';
		
		print_str();
		
		DFS(str,min_idx);
		DFS(str,start_idx);
	}
}


int main(void) {
	ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	string str;

	cin>>str;
	
	for(int i=0 ; i<str.size() ; i++)
		copy_str+=str[i];
	
	DFS(str,0);
	return 0;
}

