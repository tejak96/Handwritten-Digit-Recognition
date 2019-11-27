#include "bayes_classifier.h"
#include <time.h>

void storeData(char result, char strArr[32][32], int dataset[10][2][32][32]){
	// Modifies dataset for each provided training model
	int i=0, j=0;
	for (i=0; i<32; i++)
		for(j=0; j<32; j++){
			if (strArr[i][j] == ' ') dataset[result-'0'][0][i][j]++;
			else if (strArr[i][j] == '#') dataset[result-'0'][1][i][j]++;
		}
}

int main(void){
	FILE *fp;
	int dataset[10][2][32][32];
	char c, str[32], charArr[32][32], result;
	int strInd=0, i=0, rowInd=0, count=0;
	int i1, i2, i3, i4;

	clock_t start, end;
	double cpu_time_used;

	printf("\nTraining using optdigits-orig [Training].windep [Supervised]\n");
	start = clock();

	//Initialization
	for (i1=0; i1<10; i1++) for (i2=0; i2<2; i2++) for (i3=0; i3<32; i3++) for (i4=0; i4<32; i4++) dataset[i1][i2][i3][i4]=0;
	
	if( (fp = fopen("../datasets/optdigits-orig [Training].windep", "r")) == NULL){
		printf("Training Sets not found, please check the location\n");
		exit(1);
	}

	// Training
	for (c = getc(fp); c != EOF; c = getc(fp)){
		if (c == '\n') {
			strInd = 0; rowInd++;
		}
		else{
			charArr[rowInd][strInd] = c; strInd++;
		}
		if (rowInd==32){ //Got the whole number set by 31
			c = getc(fp); //Stray space in the result
			result = getc(fp); c = getc(fp); //New line
			storeData(result, charArr, dataset);
			count++; rowInd = 0; strInd = 0;
		}
	}

	// Stores dataset results in a txt file
	storeDataset(10, 2, 32, 32, dataset);
	printf("\nData results stored\n");

	end = clock();
	cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;	
	printf("\nFinished training in %f seconds\n", cpu_time_used);

	return 0;
}