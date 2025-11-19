#pragma once

#define N 20

typedef struct{
	int min, max;
	char rname[N];
}rock;

//function declaration
void send_data(rock);

