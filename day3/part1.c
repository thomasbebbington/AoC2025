#include<stdio.h>
#include<stdlib.h>

#define N 100

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

int dorow(char* x){
	int indx = 0;

	int largest = getlargest(x, 0, N - 1, &indx);
	int largest2 = getlargest(x, indx + 1, N, NULL);
	return (largest) * 10 + largest2;
}

int main(){
	FILE* f = fopen("input.txt", "r");
	char x[N + 1] = {0};
	x[N] = '\0';
	int total = 0;
	int count = 0;
	
	do{
		fread(x, sizeof(char), N, f);
		total = total + dorow(x);
		fseek(f, sizeof(char), SEEK_CUR);
		count++;
	} while(count < 200);

	printf("Total: %d\n", total);
	fclose(f);
	return 0;
}
