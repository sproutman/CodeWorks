/*
 * test.c
 *
 *  Created on: 27 Apr, 2013
 *      Author: root
 */

#include <stdio.h>
#include "test.h"

on_state_changed_callback on_state_changed = NULL;

void start() {
	printf("start\n");
	if (on_state_changed != NULL) {
		on_state_changed(5);
	}
}
