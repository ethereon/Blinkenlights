/*
 ================================================================
 
 Presenter
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#ifndef __PRESENTER_H__
#define __PRESENTER_H__

#include <QtGui>
#include "Glyph.h"
#include <vector>

class RenderingSurface;

class Presenter : public QThread {
	
	
	Q_OBJECT
	
private:
	
	volatile bool isStopped;
	
	std::vector<Glyph*> glyphs;
	int spacing;
	
	RenderingSurface* renderingSurface;
	
	
signals:
	
	void glyphStateChanged();
	
	
public:
	
	Presenter(QWidget* parent = 0);
	~Presenter();

	void run();
	void stop();
	
	void setRenderingSurface(RenderingSurface* argSurface);
	void setGlyphs(const std::vector<Glyph*> &argGlyphs);
	void setSpacing(int argSpacing);
	void layoutGlyphs(int w, int h);
	void renderGlyphs(QPainter& painter);
	
};


#endif