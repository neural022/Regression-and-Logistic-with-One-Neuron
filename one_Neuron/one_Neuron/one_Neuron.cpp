// one_Neuron.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
#include "stdlib.h"
#include "time.h"
#define LEARNING_RATE 0.001
#define W1 0.3
#define W2 0.3
#define W3 0.4

float w[3] = { 0.5, 0.2, 0.3 };
float x[3];
float y;

void set_example()
{
	for (int i = 0; i < 3; i++) x[i] = rand() % 100 + 1;
	y = W1 * x[0] + W2 * x[1] + W3 * x[2];
}

int main()
{
	srand(time(NULL)); rand();

	for (int i = 0; i < 50; i++)
	{
		set_example();
		float yy = w[0] * x[0] + w[1] * x[1] + w[2] * x[2];
		printf("目標結果(W = 0.3 0.3 0.4)y = %6.2f\t目前結果(w = 0.5 0.2 0.3)yy = %6.2f\t誤差值y-yy = %6.2f\n", y, yy, y - yy);
		//	目前權重 + 誤差結果
		w[0] += LEARNING_RATE * x[0] * (y - yy);
		w[1] += LEARNING_RATE * x[1] * (y - yy);
		w[2] += LEARNING_RATE * x[2] * (y - yy);
		float sum = w[0] + w[1] + w[2];
		for (int j = 0; j < 3; j++) w[j] = w[j] / sum;
		printf("%6.2f\t%6.2f\t%6.2f\n", w[0], w[1], w[2]);
	}


	return 0;
}



