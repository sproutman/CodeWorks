/*
 * main.c
 *
 *  Created on: 2013-4-27
 *      Author: root
 */

#include <stdio.h>
#include "test.h"

void test(int state)
{
	printf("state=%d\n", state);
}



int main()
{
	on_state_changed = test;
	start();
	return 0;
}
