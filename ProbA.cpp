#include<stdio.h>
#include<string.h>

int main(){
	int peserta=0, top=0, golden=0;
	scanf("%d", &peserta);getchar();
	scanf("%d", &top);getchar();
	scanf("%d", &golden);getchar();
	char team[peserta][255]={'0'};
	char institute[peserta][255]={'0'};
	for(int i=0;i<peserta;i++){
		scanf("%s %s", team[i], institute[i]); getchar();
//		cin >> team[i] >> institute[i];
	}
	char goldenteam[peserta][255]={'0'};
	char goldenuni[peserta][255]={'0'};
	int counter=0;
	for(int i=top;i<peserta;i++){
		if(counter>=golden){
			break;
		}
		int marker=0;
		for(int j=0;j<top;j++){
			if(strcmp(institute[i],institute[j])==0){
				marker=1;
				break;
			}
		}
		if(i==top && marker==0){
			strcpy(goldenuni[counter],institute[i]);
			strcpy(goldenteam[counter],team[i]);
			counter++;
		}
		else if(i!=top && marker==0){
			for(int j=0;j<counter;j++){
				if(strcmp(institute[i],goldenuni[j])==0){
					marker=1;
					break;
				}
			}
			if(marker==0){
				strcpy(goldenuni[counter],institute[i]);
				strcpy(goldenteam[counter],team[i]);
				counter++;	
			}
		}
	}
if(counter==0){
	printf("0\n");
//	cout << "0\n";
}
else{
	printf("%d\n", counter);
//	cout << counter << endl;
	for(int i=0;i<counter;i++){
//		cout << goldenteam[i] << endl;
	printf("%s\n", goldenteam[i]);
	}
}
	
return 0;
}

