#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int lis[2005];
int lds[2005];
int arr[2005];

int main(){
	int cas, n;
	
	scanf("%d", &cas);
	for(int i = 0; i < cas; i++){
		
		memset(lis, 0, sizeof(lis));
		memset(lds, 0, sizeof(lds));
		
		scanf("%d", &n);
		for(int j = 0; j < n; j++){
			scanf("%d", &arr[j]);
		}
		
		//ºâ³Ìªø»¼¼W§Ç¦C
		int maxn = 0;
		for(int r1 = n-1; r1 >= 0; r1--){
			lis[r1] = 1, lds[r1] = 1;
			
			for(int r2 = n-1; r2 > r1; r2--){
				if(arr[r1] > arr[r2]){
					lis[r1] = max(lis[r2]+1, lis[r1]);
				}
				else if(arr[r1] < arr[r2]){
					lds[r1] = max(lds[r2]+1, lds[r1]);
				}
			}
			maxn = max(lis[r1]+lds[r1]-1, maxn);
		}		
		
		printf("%d\n", maxn);
		
	} 
	
} 

