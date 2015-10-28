/*
 *https://leetcode.com/problems/unique-paths/
*/
#include <iostream>
#include <memory>
#include <vector>
#include <sys/time.h>      

using namespace std;

class Solution {
public:
   unsigned uniquePaths(int m, int n) {
     unsigned path[m][n];
    //memset(path,0,sizeof(path));
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        //cout<<i<<j<<endl;
        if (i == 0 || j == 0) {
          path[i][j] = (unsigned)1;
          continue;
        }
        
        path[i][j] = path[i-1][j] + path[i][j-1];
      }
    }
    return path[m-1][n-1];     
  }
  int uniquePaths2(int m, int n) {
        if (m > n) return uniquePaths(n, m);
        vector<int> cur(m, 1);
        for (int j = 1; j < n; j++)
            for (int i = 1; i < m; i++)
                cur[i] += cur[i - 1]; 
        return cur[m - 1];
    }
};
long getCurrentTime()    
{    
   struct timeval tv;    
   gettimeofday(&tv,NULL);    
   //cout<<tv.tv_sec<<" - "<<tv.tv_usec <<endl;
   return tv.tv_sec * 1000 * 1000 + tv.tv_usec  ;    
};
int main(){
  Solution s;
  cout<<sizeof(1)<<endl;
  cout<<sizeof(long)<<endl;

  //cout<<(2<<31)<<endl;
   long l=((1<<31)-1);
    long ul=1;
     ul=(((ul<<31)-1)*2);

  cout<<l<<" "<<ul<<endl;
  cout<<s.uniquePaths(2,2)<<endl;
  long start=getCurrentTime();
  cout<<s.uniquePaths(100,100)<<endl;
    cout<<s.uniquePaths2(100,100)<<endl;

  cout<<start<<" "<<(getCurrentTime()-start)<<endl;
  //cout<<(1<<30)<<endl;
  return 0;
}