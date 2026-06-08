#include<stdio.h>
#include<string.h>

int gdb(int a,int b)
{
	while(b!=0){
		int temp=a%b;
		a=b;
		b=temp;
	}
	return a;
}

int main()
{
    int n,m,lie=0,line=0,mark;
	scanf("%d %d",&n,&m);
	getchar();
	char a[n][m+1];
	for(int i=0;i<n;i++){
		scanf("%s",a[i]);
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(a[i][j]=='x'){
				line++;
				mark=i;
				break;
			}
		}
	}
	for(int j=0;j<m;j++){
		if(a[mark][j]=='x'){
			lie++;
		}
	}
	for(int i=0;i<line/gdb(line,lie);i++){
		for(int j=0;j<lie/gdb(line,lie);j++){
			printf("x");
		}
		printf("\n");
	}
    return 0;
}