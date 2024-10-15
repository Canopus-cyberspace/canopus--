// 修改
   # include <stdio.h>
  # include <stdbool.h>
int main() {
    int code;
    while(true){
		printf("Show me your code,please.");
        scanf("%d",code);
        if(code >= 100000 || code <= 999999){printf("I am super hacker!");
        return code;
		}else printf("Fake code!");
    }
    return 0;
}

// helloc.c
  # include <stdio.h>

int main() {
    printf("Hello, glimmer!");
    return 0;
}

// 最大公约数
  # include <stdio.h>

int main(){
	int m,n,c;
	scanf("%d%d",&m,&n);
	do{
		if(m<n){
		c=m;
		m=n;
		n=c;//让最大的始终为m
		}
		c=m%n;
		m=n;
		n=c;
	}while(c!=0);
	printf("%d",m);
	return 0;
}