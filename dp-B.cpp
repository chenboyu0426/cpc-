#include <iostream>
#include <algorithm>
#include <cstring>
#define maxn 0x3f3f3f3f3f3f3f3f

using namespace std;

long long dp[4005][4005];
int path[4005][4005];
int ans[4005];

struct Item{
	int id;
	int num;
	bool operator< (const Item &tmp)const{
		return tmp.num > num;
	}
}team[4005], shet[4005];

int main(){
	int n, m;
	
	while(scanf("%d", &n) != EOF){
		for(int i = 1; i <= n; i++){
			scanf("%d", &team[i].num);
			team[i].id = i;
		}
		sort(team+1, team+n+1);
		
		scanf("%d", &m);
		for(int i = 1; i <= m; i++){
			scanf("%d", &shet[i].num);
			shet[i].id = i;
		}
		sort(shet+1, shet+m+1);
		//i=Áa¶b¬° shet , j=¾î¶b¬° team 
		memset(dp, 0, sizeof(dp));
		memset(path, 0, sizeof(path));
		for(int j = 1; j <= n; j++){
			dp[0][j] = maxn; 
		}
		
		for(int i = 1; i <= m; i++){
			dp[i][i-1] = maxn;
			
			for(int j = i; j <= n; j++){
				if(dp[i][j-1] < dp[i-1][j-1]){
					dp[i][j] = dp[i][j-1] + abs(team[j].num - shet[i].num);
					path[i][j] = 0;
				}
				else{
					dp[i][j] = dp[i-1][j-1] + abs(team[j].num - shet[i].num);
					path[i][j] = 1;
				}
			}
		}
		printf("%lld\n", dp[m][n]);
		
		int back_track = m;
		for(int i = n; i > 0; i--){
			ans[team[i].id] = shet[back_track].id;
			back_track -= path[back_track][i];
		}
		
		printf("%d", ans[1]);
		for(int i = 2; i <= n; i++){
			printf(" %d", ans[i]);
		}
		printf("\n");
		
	}
}
