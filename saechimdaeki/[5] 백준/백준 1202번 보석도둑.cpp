#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
int n,k;
vector<pair<int, int> > v;
multiset<int> s;
long long answer;
bool cmp(pair<int, int> p1, pair<int, int > p2)
{
	return p1.second>p2.second;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>k;
	v.resize(n);
	//first:=무게 second:=가격  
	for(int i=0; i<n; i++)
	cin>>v[i].first>>v[i].second;
	sort(v.begin(),v.end(),cmp);
	for(int i=0; i<k; i++)
	{
		int a;
		cin>>a;
		s.insert(a);
	}
	for(int i=0; i<n; i++)
	{
		auto iterator=s.lower_bound(v[i].first);
		if(iterator!=s.end())
		{
			answer+=v[i].second;
			s.erase(iterator);
		}
	}
	cout<<answer;
}
