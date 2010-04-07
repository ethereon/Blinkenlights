
/*
 ================================================================
 
 State Controller
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */


#ifndef __STATE_CONTROLLER_H__
#define __STATE_CONTROLLER_H__


class StateController {

	
public:
	
	StateController() {}
	~StateController() {}
	
	virtual void start()=0;
	virtual int getNextState()=0;
	
	
};

#endif