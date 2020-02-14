#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * SIZE: 2565 3350 x 3350 3374
 * TIME: 5m22s
 */

// #define RAND rand() % 2500 + 1000
#define RAND rand() % 11

void printMatrix(FILE *file, int rows, int columns) {
	int i, j;

	fprintf(file, "%d %d\n", rows, columns);
	for (i = 0; i < rows; i++) {
		for (j = 0; j < columns; j++) {
			if (rand() % 2)
				//fprintf(file, "%d ", RAND + 1500);
				fprintf(file, "%d ", RAND);
			else
				//fprintf(file, "%d ", -(RAND + 1500));
				fprintf(file, "%d ", RAND);
		}
		fprintf(file, "\n");
	}
}

int main(void) {
	srand(time(NULL));
	int rows, columns;
	FILE *file;

	if ((file = fopen("matrix.in", "w")) == NULL) {
		perror("File INPUT!");
		exit(EXIT_FAILURE);
	}

	rows = 1500;//1000;//2565; //RAND;
	columns = 2350;//1000;//3350; //RAND;
	printf("Generating A: %dx%d\n", rows, columns);
	printMatrix(file, rows, columns);

	rows = columns;
	columns = 2000;//1000;//3374;//RAND;
	printf("Generating B: %dx%d\n", rows, columns);
	printMatrix(file, rows, columns);

	fclose(file);

	return EXIT_SUCCESS;
}
