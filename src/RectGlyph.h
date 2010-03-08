/*
 ================================================================
 
 Rectangular Glyph
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */


#ifndef __RECT_GLYPH_H__
#define __RECT_GLYPH_H__

#include "Glyph.h"

class RectGlyph : public Glyph {
	
	Q_OBJECT
	
private:
	
	QRectF rectangle;
	
	void onStart();
	
public:
	
	void render(QPainter* painter);
};

#endif