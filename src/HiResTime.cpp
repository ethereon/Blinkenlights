/*
 ================================================================
 
 High Resolution Time Routines
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */


#include "HiResTime.h"

#ifdef _WIN32

#include <windows.h>

#else

#include <time.h>
#include <sys/time.h>

#endif



void getCurrentTime(HIRESTIME* t) {

#ifdef _WIN32

	LARGE_INTEGER frequency, currentCount;

	QueryPerformanceFrequency(&frequency); // Units is ( counts / sec )
	
	QueryPerformanceCounter(&currentCount);
	
	*t = (HIRESTIME)(currentCount.QuadPart/(frequency.QuadPart/1000000));
	
#else

	timeval tv;
	gettimeofday(&tv, NULL);
	*t = (HIRESTIME)tv.tv_usec;
	
#endif

}