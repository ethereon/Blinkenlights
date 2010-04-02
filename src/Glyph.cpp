/*
 ================================================================
 
 Glyph
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */


#include "Glyph.h"

#ifdef _WIN32
#include <sys/time.h>
#endif

Glyph::Glyph(QObject* parent) : QObject(parent)
{ 
	
	state = 0;

	this->setDimensions(0, 0, 100, 100);
	
}

Glyph::~Glyph() {
	
}

void Glyph::toggleState() {
	

	state = !state;
	
}

void Glyph::setFrequency(double f) 
{
	
	this->frequency = f;
	
	this->transitionInterval = (1./(2*f))*1000000;
	

}


void Glyph::setDimensions(int argX, int argY, int argW, int argH) {
	
	rX = argX;
	rY = argY;
	rWidth = argW;
	rHeight = argH;
	
	onResized();
}


void Glyph::start() {

	
	this->onStarting();
	
}

void Glyph::stop() {
	


}

