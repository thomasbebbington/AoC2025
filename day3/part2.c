#include<stdio.h>
#include<stdlib.h>

#define N 100
#define L 12

int getlargest(char* x, int from, int to, int* indx){
	int l = 0;
	char c[2];

	for(int i = from; i < to; ++i){
		c[0] = x[i];
		c[1] = '\0';
		int current = atoi(c);
		if(current > l){
			l = current;
			if(indx != NULL) *indx = i;
			if(l == 9) break;
		}
	}

	return l;
}

long long dorow(char* x){
	printf("%s\n", x);
	int indx = -1;
	char ret[L+1] = {0};
	ret[L] = '\0';

	for(int i = 0; i < L-1; ++i){
		int largest = getlargest(x, indx + 1, N - 11 + i, &indx);
		printf("%d\n", largest);
		sprintf(&ret[i], "%d", largest);	
	}

	int largest = getlargest(x, indx + 1, N, NULL);
	printf("%d\n", largest);
	sprintf(&ret[11], "%d", largest);
	printf("%s\n", ret);
	return strtol(ret, NULL, 10);
}

int main(){
	FILE* f = fopen("input.txt", "r");
	char x[N + 1] = {0};
	x[N] = '\0';
	long long total = 0;
	int count = 0;
	
	do{
		fread(x, sizeof(char), N, f);
		total = total + dorow(x);
		fseek(f, sizeof(char), SEEK_CUR);
		count++;
	} while(count < 200);

	printf("Total: %lld\n", total);
	fclose(f);
	return 0;
}
