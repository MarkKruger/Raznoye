#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include "Matrix.h"

int main() {
	Matrix sqrt_array(4, 4);
	Vector sqrt_arr(16);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			sqrt_array[i][j] = sqrt(i + j + 1);
		}
	}

	int k = 0;
	for (int i = 3; i >= 0; i--) {
		for (int j = 0; j < 4; j++) {
			sqrt_arr[k] = sqrt_array[i][j];
			k++;
		}
	}

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("%.2f ", sqrt_array[i][j]);
		}
		puts("\n");
	}

	for (int i = 0; i < 16; i++) {
		printf("%.4f ", sqrt_arr[i]);
	}

	return 0;
}
