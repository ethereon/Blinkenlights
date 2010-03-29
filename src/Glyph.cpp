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
#include <sys/time.h>

Glyph::Glyph(QObject* parent) : QObject(parent)
{ 
	
	state = 0;

	this->setDimensions(0, 0, 100, 100);
	connect(&timer, SIGNAL(timeout()), this, SLOT(toggleState()));
	
}

Glyph::~Glyph() {
	
}

void Glyph::toggleState() {
	
	timeval tv;
	gettimeofday(&tv, NULL);
	suseconds_t uSecs = tv.tv_usec;
	
	suseconds_t delta = uSecs - markTime;
	markTime = uSecs;
	
	printf("%f:%d\n", frequency, delta);
	
	
	state = !state;
	
}

void Glyph::setFrequency(double f) 
{
	
	this->frequency = f;
	
	this->transitionInterval = (1./(2*f))*1000000;
	
//	this->timer.setInterval(halfPeriod);

}


void Glyph::setDimensions(int argX, int argY, int argW, int argH) {
	
	rX = argX;
	rY = argY;
	rWidth = argW;
	rHeight = argH;
	
	onResized();
}


void Glyph::start() {
	
	timeval tv;
	gettimeofday(&tv,NULL);
	markTime = tv.tv_usec;
	
	this->onStarting();
	//this->timer.start();
	
	
	
}

void Glyph::stop() {
	
//	this->timer.stop();

}

