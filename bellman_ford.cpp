#include<iostream>
#include<algorithm>
#include<math.h>
#include<cstring>
#include<iomanip>
#include<stdio.h>
#include<limits>
#include<map>
#include<set>
#include<list>
#include<vector>
#include <ctime>
#include<stack>
#define gcd __gcd
#define pb(x) push_back(x)
#define ll long long
#define in(x) scanf("%d",&x)
#define mod 1000000007LL
#define sz(x) x.size()
#define mst(x,a) memset(x,a,sizeof(x))
#define pii pair<ll,ll>
#define F first
#define S second
#define m_p make_pair
#define all(v) (v.begin(),v.end())
#define inf 1000000000
using namespace std;
vector<pii> gr;
map<pii,int>wt;
//void bellman_ford(int s,int x)
void bellman_ford(int s,int n)
{
	int d[n];
	for(int i=0;i<n;i++)
		d[i]=inf;
		d[s-1]=0;
		int e=sz(gr);
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<e;j++)
		{
			int u=gr[j].first;
			int v=gr[j].second;
			if(d[u]+wt[m_p(u,v)]<d[v]&&d[u]!=inf)
				d[v]=d[u]+wt[m_p(u,v)];
		}

	}
	for(int i=0;i<e;i++)
	{
		int u=gr[i].first;
		int v=gr[i].second;
		if(d[u]+wt[m_p(u,v)]<d[v]&&d[u]!=inf)
		{
			cout<<"negative cycle found in case of "<<s<<endl;
			break;
		}
	}
	cout<<"shortest distances from "<<s<<" are ";
	for(int i=0;i<n;i++)
	{
			cout<<d[i]<<" ";
	}
	cout<<endl;
	return;
}
int main()
{
    ios::sync_with_stdio(0);
    int start_s=clock();
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cout<<"enter the number of vertices"<<endl;
  	int v;
  	cin>>v;
  	cout<<"enter the adjacency matrix"<<endl;
  	int x;
  	for(int i=0;i<v;i++)
  		for(int j=0;j<v;j++)
  		{
  			cin>>x;
  			if(x!=0)
  			{
  				gr.pb(m_p(i,j));
  				wt[m_p(i,j)]=x;
  			}
  		}
  	//cout<<"by bellman-ford algorithm\n";
  	for(int i=1;i<=v;i++)
  		bellman_ford(i,v);
  	int stop_s=clock();
	cout << "time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC)*1000 << endl;

    return 0;
}
