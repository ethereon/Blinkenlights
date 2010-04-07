/*
 ================================================================
 
 Binary Oscillator
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */


#ifndef __BINARY_OSCILLATOR_H__
#define __BINARY_OSCILLATOR_H__


class BinaryOscillator : public StateController {
	
	bool state;

public:
	
	BinaryOscillator() { state = 0; }
	~BinaryOscillator() {}
	
	void start() { state = 0; }
	int getNextState() { state = !state; return state; }

};

#endif