
/*
 ================================================================
 
 MSequence State Controller
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#include "MSequence.h"
#include <cmath>

int getPeriod(int n) {
	
	return (int)pow(2.0,(int)n)-1;
	
}

void genMaxSequence(int n, const int* polynomial, bool* seqOut) {
	
	bool* reg = new bool[n+1];
	
	int period = getPeriod(n);
	
	for(int i=1;i<n+1;reg[i++]=1) {}
	
	for(int i=0; i<period; ++i) {
		
		reg[0] = 0;
		
		for(int j=1; j<=polynomial[0]; ++j) {
			
			reg[0] = reg[0]^reg[polynomial[j]];
			
		}
		
		for(int j=n; j>0; --j) {
			
			reg[j]=reg[j-1];
			seqOut[(j-1)+(i*n)] = reg[j];
			
		}
		
	}
	
	delete [] reg;
	
}


MSequence::MSequence() {

	const int poly[] = {2, 5, 2};
	
	nBits = 5*getPeriod(5);
	
	sequence = new bool[nBits];
	
	genMaxSequence(5, poly, sequence);
	
	
}


MSequence::~MSequence() {

	delete [] sequence;

}

void MSequence::start() {

	cursor = -1;
	
}

int MSequence::getNextState() {

	cursor = (cursor+1)%nBits;
	
	return sequence[cursor];
	
}
