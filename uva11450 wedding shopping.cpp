#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int cas, m, c, price[25][25];
	int dp[205][25]; //價格 商品種類數 
	
	scanf("%d", &cas);
	while(cas--)
	{	
		memset(dp, 0, sizeof(dp));
		scanf("%d%d", &m, &c);
		
		for(int i = 0; i < c; i++){
			scanf("%d", &price[i][0]); //商品型別數 
			
			for(int j = 1; j <= price[i][0]; j++){
				scanf("%d", &price[i][j]); //不同型別價錢 
			}
		}
		
		for(int i = 1; i <= price[0][0]; i++){
			dp[m-price[0][i]][0] = true;
		}
		
		for(int i = 1; i < c; i++){
			for(int j = 0; j < m; j++){
				
				if(dp[j][i-1]){
					for(int k = 1; k <= price[i][0]; k++){
						if(j - price[i][k] >= 0){
							dp[j - price[i][k]][i] = true;
						}

					}
				}
			}
		}
		int cost = -1;
		for(int i = 0; i < m; i++){
			if(dp[i][c-1]){
				cost = m - i;
				break;
			}
		}
		
		if(cost < 0) printf("no solution\n");
		else printf("%d\n", cost); 
	}
} 
