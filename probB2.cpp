#include<stdio.h>
int main(){
	int day=0, milk=0, biscuit=0;
	scanf("%d %d %d", &day, &milk, &biscuit);
	int need[day]={'0'};
	int drinked[day]={'0'};
	for(int i=0;i<day;i++){
		scanf("%d", &need[i]);
	}
	int survived=0,counter=0,count=0;
	while(counter<day){
		int chance=milk-need[counter];
		if(chance>=0){
			milk-=need[counter];
			drinked[count]=need[counter];
			count++;
			counter++;
			survived++;
			continue;
		}
		else{
			if(biscuit>0){
				if(count<=0){
					biscuit--;
					survived++;
					counter++;
					continue;
				}
				int max=0;
				int index=0;
				for(int i=0;i<count;i++){
					if(max<drinked[i]){
						max=drinked[i];
						index=i;
					}
				}
				if(need[counter]<max){
					milk+=max;
					drinked[index]=0;
					biscuit--;
					continue;
				}
					biscuit--;
					survived++;
					counter++;
			}
			else{
				break;
			}
		}
	}
	printf("%d\n",survived);
return 0;
}

