可以把此算法理解为模仿打结的绳，从桌面提起。对每个结，计算机必须知道1.有**几段**绳连着。2.每段**多长**。还必须保存一个表dist，存放起点到每个节点估计距离。距离dist[v]：从起点到v，只经过_垂悬_结的最短连线长度。

```
所有结都在等待，所有d[v] = ∞，只有d[起点] = 0
while 有等待的结 do
	v := 最小dist[v]的等待结
	把v提起
	for 从v到u长度为l的所有的绳 do
		if dist[v] + l < dist[u], then dist[u] := dist[v] + l
			// 找到v到u的较短路径 
```

```cpp
// 类比bfs queue->priority_queue
// 若不使用pq:增加vis[V]标记,在未标记顶点中循环找最最近顶点
#include <bits/stdc++.h>
using namespace std;
#define MAX_V 50
#define INF 100000
int V;  //顶点数
//         权值 顶点号  (也可用struct)
vector<pair<int,int> > adj[MAX_V];  
vector<int> dist;    //记录min距离
vector<int> parent;    //记录从哪来
void dij(int src)
{
	dist = vector<int>(V,INF);
    dist[src] = 0;
    parent[src] = src;
    priority_queue<pair<int,int> > pq;    //按first(权值)由大到小排序 so 取相反数入队
    pq.push(make_pair(0,src));

    while(!pq.empty())
    {
        int cost = -pq.top().first;
        int here = pq.top().second;
        pq.pop();

        if(dist[here] < cost)  //忽略，已有更新过的更短的路径
            continue;

        for(int i=0; i<adj[here].size(); i++)
        {
            int there = adj[here][i].second;
            int next_dist = cost - adj[here][i].first;
            if(next_dist < dist[there])
            {
                dist[there] = next_dist;
                parent[there] = here;
                pq.push(make_pair(-next_dist,there));
            }
        }
    }
}
void print_path(int v)  // v --> src
{
    vector<int> path(1,v);
    while(parent[v] != v)
    {
        v = parent[v];
        path.push_back(v);
    }
    for(int v:path)
        cout<<v<<" ";
    cout<<endl;
}
int main()
{
    V = 4;
    parent = vector<int>(V, -1);
    adj[0].push_back(make_pair(-2,1));
    adj[0].push_back(make_pair(-12,3));
    adj[1].push_back(make_pair(-2,0));
    adj[1].push_back(make_pair(-4,2));
    adj[2].push_back(make_pair(-4,1));
    adj[2].push_back(make_pair(-3,3));
    adj[3].push_back(make_pair(-12,0));
    adj[3].push_back(make_pair(-3,2));
    dij(0);
    for(int d:dist)
        cout<<d<<" ";
    cout<<endl;
    print_path(3);
    return 0;
}
```
