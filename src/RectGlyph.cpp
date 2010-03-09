/*
 ================================================================
 
 Rectangular Glyph
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */


#include "RectGlyph.h"


void RectGlyph::onStarting() {
	
	rectangle.setRect(rX,rY,rWidth,rHeight);
	
}

void RectGlyph::render(QPainter* painter) {
	
	if(state)
		painter->drawRect(rectangle);
	
}
