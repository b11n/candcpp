#include<iostream>
#include<set>
#include<map>
#include<string>
#include<stdio.h>
#include<sstream>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string.h>
using namespace std ;
#define INF (int)1e9
#define MAXN 700
int N ;
double matrix[MAXN][MAXN] ;

string normalize(string s)
{
 int mp[26],c = 0 ;
 memset(mp,255,sizeof mp) ;
 for(int i = 0;i < s.size();i++)
  if(mp[s[i] - 'a'] == -1)
   mp[s[i] - 'a'] = c++ ;
 string ret ;
 for(int i = 0;i < s.size();i++)
  ret.push_back(mp[s[i] - 'a'] + 'a') ;
 return ret ;
}

int ct = 0 ;
map<string,int> id ;
int getId(string s)
{
 if(id.count(s)) return id[s] ;
 return id[s] = ct++ ;
}

int tot = 0 ;
map<string,double> memo ;
double solve(string s)
{
 s = normalize(s) ;
 if(memo.count(s)) return memo[s] ;

 ct = 0 ;
 id.clear() ;

 int n = s.size() ;
 int swaps = n * (n - 1) / 2 ;
 
 N = 0 ;
 string t = s ;
 sort(t.begin(),t.end()) ;
 do { getId(normalize(t)) ; }
 while(next_permutation(t.begin(),t.end())) ;
 N = id.size() ;

 for(int i = 0;i <= N;i++)
  for(int j = 0;j <= N;j++)
   matrix[i][j] = 0 ;

 t = s ;
 sort(t.begin(),t.end()) ;
 do
 {
  string x = normalize(t) ;
  int id1 = getId(x) ;
  matrix[id1][id1]++ ;
    
  string tt = x ;
  reverse(tt.begin(),tt.end()) ;
  if(x == tt) continue ;  
  for(int i = 0;i < n;i++)
   for(int j = i + 1;j < n;j++)
   {
    swap(x[i],x[j]) ;
    int id2 = getId(normalize(x)) ;
    matrix[id1][id2] += -1. / swaps ;
    swap(x[i],x[j]) ;
   }
  matrix[id1][N]++ ;
 }
 while(next_permutation(t.begin(),t.end())) ;
 
 for(int i = 0;i < N;i++)
 {
  for(int j = N;j >= i;j--) matrix[i][j] /= matrix[i][i] ;
   for(int k = 0;k < N;k++) if(i != k)
    for(int j = N;j >= i;j--)
     matrix[k][j] -= matrix[k][i] * matrix[i][j] ;
 }

 sort(t.begin(),t.end()) ;
 do
 {
  string tt = normalize(t) ;
  memo[tt] = matrix[getId(tt)][N] ;
 }
 while(next_permutation(t.begin(),t.end())) ;
 
 return memo[s] ;
}

int main()
{
 int runs ;
 cin >> runs ; 
 while(runs--)
 {
  string s ;
  cin >> s ;
  double ret = solve(s) ;
  printf("%.4lf\n",ret) ;
 }
 return 0 ;
}
