#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    vector<vector<int>> map(m+1,vector<int>(n+1,0));
    for(int i=0;i<puddles.size();i++){
        map[puddles[i][0]][puddles[i][1]]=-1;
    }
    map[1][1]=1;
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==-1)continue;
            if(map[i-1][j]!=-1){
                map[i][j]+=map[i-1][j];
                map[i][j]%=1000000007;
            }
            if(map[i][j-1]!=-1){
                map[i][j]+=map[i][j-1];
                map[i][j]%=1000000007;
            }
        }
    }
    int answer = map[m][n];
    return answer;
}