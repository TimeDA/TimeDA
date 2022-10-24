#include<stdio.h>
 char ooxx[101][101];
 int main(){
 	int i,j,k;
 	int T,TN,f,p;
 	scanf("%d",&TN);
 	for(T=1;T<=TN;T++){
 		p=0;
 		for(i=0;i<4;i++){
 			scanf("%s",ooxx[i]);
 			for(j=0;j<4;j++){
 				if(ooxx[i][j]=='.')p++;
 			}
 		}
 		for(i=0;i<4;i++){
 			f=0;
 			for(j=0;j<4;j++){
 				if(ooxx[i][j]=='O');
 				else if(ooxx[i][j]=='T'&&!f)f=1;
 				else break;
 			}
 			if(j>=4)break;
 		}
 		if(i<4){
 			printf("Case #%d: O won\n",T);
 			continue;
 		}
 		for(i=0;i<4;i++){
 			f=0;
 			for(j=0;j<4;j++){
 				if(ooxx[j][i]=='O');
 				else if(ooxx[j][i]=='T'&&!f)f=1;
 				else break;
 			}
 			if(j>=4)break;
 		}
 		if(i<4){
 			printf("Case #%d: O won\n",T);
 			continue;
 		}
 		f=0;
 		for(j=0;j<4;j++){
 			if(ooxx[j][j]=='O');
 			else if(ooxx[j][j]=='T'&&!f)f=1;
 			else break;
 		}
 		if(j>=4){
 			printf("Case #%d: O won\n",T);
 			continue;
 		}
 		f=0;
 		for(j=0;j<4;j++){
 			if(ooxx[j][3-j]=='O');
 			else if(ooxx[j][3-j]=='T'&&!f)f=1;
 			else break;
 		}
 		if(j>=4){
 			printf("Case #%d: O won\n",T);
 			continue;
 		}
 		for(i=0;i<4;i++){
 			f=0;
 			for(j=0;j<4;j++){
 				if(ooxx[i][j]=='X');
 				else if(ooxx[i][j]=='T'&&!f)f=1;
 				else break;
 			}
 			if(j>=4)break;
 		}
 		if(i<4){
 			printf("Case #%d: X won\n",T);
 			continue;
 		}
 		for(i=0;i<4;i++){
 			f=0;
 			for(j=0;j<4;j++){
 				if(ooxx[j][i]=='X');
 				else if(ooxx[j][i]=='T'&&!f)f=1;
 				else break;
 			}
 			if(j>=4)break;
 		}
 		if(i<4){
 			printf("Case #%d: X won\n",T);
 			continue;
 		}
 		f=0;
 		for(j=0;j<4;j++){
 			if(ooxx[j][j]=='X');
 			else if(ooxx[j][j]=='T'&&!f)f=1;
 			else break;
 		}
 		if(j>=4){
 			printf("Case #%d: X won\n",T);
 			continue;
 		}
 		f=0;
 		for(j=0;j<4;j++){
 			if(ooxx[j][3-j]=='X');
 			else if(ooxx[j][3-j]=='T'&&!f)f=1;
 			else break;
 		}
 		if(j>=4){
 			printf("Case #%d: X won\n",T);
 			continue;
 		}
 		if(p){
 			printf("Case #%d: Game has not completed\n",T);
 		} else {
 			printf("Case #%d: Draw\n",T);
 		}
 	}
 }
