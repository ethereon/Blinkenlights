/*
 ================================================================
 
 Checkerboard Glyph
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */


#include "CheckerboardGlyph.h"


CheckerboardGlyph::CheckerboardGlyph(QObject* parent) : Glyph(parent) {
	
	rects = NULL;
	blockSize = 40;
}

CheckerboardGlyph::~CheckerboardGlyph() {
	
	if(rects!=NULL)
		delete [] rects;
	
}


void CheckerboardGlyph::onStarting() {
	
	setupBlocks();
	
}

void CheckerboardGlyph::setupBlocks() {
	
	bool startTimer = false;
	
	if(timer.isActive())  {
		startTimer = true;
		timer.stop();
	}
	
	if(rects!=NULL)
		delete [] rects;

	this->xBlocks = (int)(rWidth / blockSize);
	
	int yBlocks = (int)(rHeight / blockSize);
	
	nBlocks = xBlocks*yBlocks;
	
	rects = new QRectF[nBlocks];
	
	for(int i=0;i<nBlocks; ++i) {
		
		int vert = ((int)(i/xBlocks));
		int horiz = (i%xBlocks);
		
		rects[i].setRect(rX+(horiz*blockSize), rY+(vert*blockSize), blockSize, blockSize);
		
	}
	
	if(startTimer)
		timer.start();
	
}

void CheckerboardGlyph::onResized() {
	
	setupBlocks();
	
}

void CheckerboardGlyph::render(QPainter* painter) {
	
	for(int i=0;i<nBlocks; ++i)
		if((i%2) == (state ^ ( (xBlocks%2==0) && ((i/xBlocks)%2==1) )))
			painter->drawRect(rects[i]);
		
	
}
