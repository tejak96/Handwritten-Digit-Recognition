#include "bayes_classifier.h"
#include <time.h>

int main(void){
	int dataResults[10][2][1024];
	int predictedResult, result, accuracy, count=0, sum=0;
	int i1, i2, i3;
	char c, strArr[1024];

	FILE *fp;

	// For time measurements
	clock_t start, end;
	double cpu_time_used;

	printf("\nTesting on optdigits-orig [Validation].wdep\n");
	start = clock();

	// Initialization
	for (i1=0; i1<10; i1++) for (i2=0; i2<2; i2++) for (i3=0; i3<1024; i3++) dataResults[i1][i2][i3]=0;

	// Fetches data results generated from training
	printf("\nPicking up data results\n");
	generateDataset(10, 2, 1024, dataResults);

	if( (fp = fopen("../datasets/optdigits-orig [Validation].wdep", "r")) == NULL) {
		printf("\nValidation Set not found, please check the location\n");
		exit(1);
	}

	// Scan through the validations file
	i1 = 0;
	for (c = getc(fp); c != EOF; c = getc(fp)) {
		if (c == ' ' || c =='#') {
			strArr[i1] = c;
			i1++;
		}
		if (c == '-') {
			result = getc(fp) - '0';
			i1=0;
			c = getc(fp); //New Line
			//printf("%d %s\n",result,strArr);
			predictedResult = predictData(strArr, dataResults);

			count++;
			if (predictedResult == result) sum++;
		}
	}

	end = clock();
	cpu_time_used = ((double)(end-start))/CLOCKS_PER_SEC;	
	printf("\nFinished testing in %f seconds\n", cpu_time_used);

	// Display results
	printf("\n\nTotal Test Models \t: %d\n", count);
	printf("Correct predictions \t: %d\n", sum);
	printf("Accuracy \t\t: %f\n", ((float)sum/(float)count)*100);

	return 0;
}