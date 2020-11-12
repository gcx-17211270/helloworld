#ifndef __SLOWESTKEY_H_HELLO_QIU__
#define __SLOWESTKEY_H_HELLO_QIU__

#include <stdio.h>

#ifdef __cplusplus
extern "C"
{
#endif
	void slowestKey_callback();
	char slowestKey(int* releaseTimes, int releaseTimesSize, char* keysPressed);
	int maxNum(int a, int b);
#ifdef __cplusplus
}
#endif

#endif