#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int predictData(char strArr[1024], int dataset[10][2][1024]){
	// Returns predicted int for provided model
	// For any specific number from 1_10:
	// 		OccuranceOf(Char-0_0 at 0_0) = No of Char-0_0's that occured at 0_0 / Total no of models for that number
	// 		V = OccuranceOf(Char-0_0 at 0_0) * OccuranceOf(Char-0_1 at 0_1) * ... * OccuranceOf(Char-1023_1023 at 1023_1023)
	// 		log(V) = [log(No of Char-0_0's that occured at 0_0) + log(No of Char-0_1's that occured at 0_1) + ... ]
	//				- [log(Total no of models for the number) + ]
	double resultArrLogBase10[10], aCount = 0.0, tCount = 0.0, maxVal = -9999999.99;
	int i, j, maxIndex = 0;
	for (i=0; i<10; i++) {
		resultArrLogBase10[i] = 0.0;
		for (j=0; j<1024; j++) {
			if (strArr[j] == ' ') {
				aCount = log(((double)dataset[i][0][j]));				   // No of spaces that occured at i_j (i*j expressed under one array here)
				tCount = log((double)(dataset[i][0][j]+dataset[i][1][j])); // Total no of models for the number
				resultArrLogBase10[i] = resultArrLogBase10[i] + (aCount - tCount);
			}
			else if (strArr[j] == '#') {
				aCount = log(((double)dataset[i][1][j]));				   // No of #'s that occured at i_j
				tCount = log((double)(dataset[i][0][j]+dataset[i][1][j])); //Total no of models for the number
				resultArrLogBase10[i] = resultArrLogBase10[i] + (aCount - tCount);
			}
		}
		if (resultArrLogBase10[i] > maxVal){
			maxVal = resultArrLogBase10[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

void storeDataset(size_t A, size_t B, size_t C, size_t D, int dataset[A][B][C][D]){
	// Stores result dataset in a txt file
	FILE *fp; fp = fopen("../misc/DataResults.txt", "w");
	int totalNumbers, featureSetOfNumber, featureSetsRows, featureSetsColumns;

	for (totalNumbers=0; totalNumbers<A; totalNumbers++){
		fprintf (fp, "%d\n", totalNumbers);
		for (featureSetOfNumber=0; featureSetOfNumber<B; featureSetOfNumber++){
			for (featureSetsRows=0; featureSetsRows<C; featureSetsRows++){
				for (featureSetsColumns=0; featureSetsColumns<D; featureSetsColumns++){
					fprintf(fp, "%d ", dataset[totalNumbers][featureSetOfNumber][featureSetsRows][featureSetsColumns]);
				}
			}
			fprintf (fp, "\n");
		}
	}
	fclose(fp);
}

void generateDataset(size_t A, size_t B, size_t C, int data[A][B][C]){
	// Loads existing training data of [A][B][C][D] into data[A][B][C] for validations
	char c;
	int num, ch, val=0, j;
	FILE *fp; fp = fopen("../misc/DataResults.txt", "r");

	for (c = getc(fp); c != EOF; c = getc(fp)){
		num = c - '0';
		c = getc(fp); //New Line
		j=0;	// This goes from 0 to 1023 (32 x 32) stored under a single array
		val=0;
		// Space Data
		while((c=getc(fp)) != EOF){
			if (c=='\n') break;
			if (c != ' ') {
				val = val*10 + (c-'0');	// Gets a number from stream of numbers with a space token
			}
			else {
				data[num][0][j] = val;
				j++;
				val=0;	// val is made zero with every space encounter
			}
		}
		j=0; val=0;
		// Hash Data
		while((c=getc(fp)) != EOF){
			if (c=='\n') 
				break;
			if (c != ' ') 
				val = val*10 + (c-'0');
			else{
				data[num][1][j] = val;
				j++;
				val=0;
			}
		}
    }
    fclose(fp);
}
