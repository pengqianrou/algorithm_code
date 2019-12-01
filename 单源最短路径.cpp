#include <stdio.h> 
#include <iostream> 
#include <cstdio> 
#include <cstdlib> 
using namespace std; 
const int maxnum=100; 
const int maxint=999999; 
int dist[maxnum]; 
int prev[maxnum]; 
int c[maxnum][maxnum];
int n,line;
 void Dijkstra(int n, int v, int *dist, int *prev, int c[maxnum][maxnum]) { 
 bool s[maxnum]; 
 for(int i=1; i<=n; ++i) { 
 dist[i] = c[v][i]; 
 s[i] = 0;
 if(dist[i] == maxint) 
 prev[i] = 0; 
 else 
 prev[i] = v; 
 } 
 dist[v] = 0; 
 s[v] = 1;  
 for(int i=2; i<=n; ++i) { 
 int tmp = maxint; int u = v; 
 for(int j=1; j<=n; ++j) 
 if((!s[j]) && dist[j]<tmp) { 
 u = j; 
 tmp = dist[j]; 
 } 
 s[u] = 1; 
 for(int j=1; j<=n; ++j) 
 if((!s[j]) && c[u][j]<maxint) 
 { 
   int newdist = dist[u] + c[u][j]; 
   if(newdist < dist[j]) 
   { 
     dist[j] = newdist; 
	 prev[j] = u; 
	 } 
	 } 
	 } 
	 } 
	 void searchPath(int *prev,int v, int u) 
	 {
	  int que[maxnum]; 
	  int tot = 1; 
	  que[tot] = u; 
	  tot++; 
	  int tmp = prev[u]; 
	  while(tmp != v) 
	  {
	   que[tot] = tmp; 
	   tot++; 
	   tmp = prev[tmp]; 
	   } 
	   que[tot] = v; 
	   for(int i=tot; i>=1; --i) 
	   { 
	     if(i != 1) 
		   cout << que[i] << " -> "; 
	     else 
		   cout << que[i] << endl; 
		   } 
		   } 
	int main() 
	{ 
	cin >> n; 
	cin >> line; 
	int p, q, len; 
	for(int i=1; i<=n; ++i) 
	for(int j=1; j<=n; ++j) 
	c[i][j] = maxint; 
	for(int i=1; i<=line; ++i) 
	{ 
	  cin >> p >> q >> len; 
	  if(len < c[p][q]) 
	  { 
	  c[p][q] = len; 
	  c[q][p] = len;  
	  } 
	  } 
	  for(int i=1; i<=n; ++i) 
	  dist[i] = maxint; 
	  for(int i=1; i<=n; ++i) 
	  { 
	  for(int j=1; j<=n; ++j) 
	  printf("%8d", c[i][j]); 
	  printf("\n"); 
	  } 
	  Dijkstra(n, 1, dist, prev, c);  
	  cout << dist[n] << endl;  
	  searchPath(prev, 1, n);
	  while(1){
	  } 
	  }
