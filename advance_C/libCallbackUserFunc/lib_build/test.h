/*
 * test.h
 *
 *  Created on: 27 Apr, 2013
 *      Author: root
 */

#ifndef TEST_H_
#define TEST_H_

typedef void (*on_state_changed_callback)(int);
extern on_state_changed_callback on_state_changed;
extern void start();

#endif /* TEST_H_ */
