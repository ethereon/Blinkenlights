/*
 ================================================================
 
 MSequence State Controller
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#ifndef __M_SEQ_GEN_H__
#define __M_SEQ_GEN_H__

#include "StateController.h"

class MSequence : public StateController {
	

private:
	
	bool* sequence;
	
	int nBits;
	
	int cursor;
	
public:
	
	MSequence();
	~MSequence();
	
	
	void start();
	int getNextState();
	

};

#endif