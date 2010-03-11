/*
 ================================================================
 
 Checkerboard Glyph
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */


#ifndef __CHECKERBOARD_GLYPH_H__
#define __CHECKERBOARD_GLYPH_H__

#include "Glyph.h"

class CheckerboardGlyph : public Glyph {
	
	
	Q_OBJECT
	
private:
	
	QRectF* rects;
	
	int nBlocks;
	int xBlocks;
	int blockSize;
	
	void onStarting();
	void onResized();
	
	void setupBlocks();
	
public:
	
	CheckerboardGlyph(QObject* parent=0);
	~CheckerboardGlyph();
	
	void render(QPainter* painter);
	

};


#endif