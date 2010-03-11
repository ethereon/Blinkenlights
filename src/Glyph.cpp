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

Glyph::Glyph(QObject* parent) : QObject(parent)
{ 
	
	state = 0;

	this->setDimensions(0, 0, 100, 100);
	connect(&timer, SIGNAL(timeout()), this, SLOT(toggleState()));
	
}

Glyph::~Glyph() {
	
}

void Glyph::toggleState() {
	
	state = !state;
	
}

void Glyph::setFrequency(double f) 
{
	
	this->halfPeriod = (1./(2*f))*1000;
	
	this->timer.setInterval(halfPeriod);

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
	this->timer.start();
	
}

void Glyph::stop() {
	
	this->timer.stop();

}

