#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "appdev.h"

int main(void){
	rock r;
	printf("Application Development Rock!\n");
	printf("Enter your name: ");
	scanf("%s", r.rname);
	r.max = rand() % 50 + 51;
	r.min = rand() % 50 + 1;
	send_data(r);
	printf("Rockn'Roll\n");
	return 0;
}
