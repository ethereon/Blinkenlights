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
#include "LayoutEngine.h"

class RenderingSurface;

class Presenter : public QThread {
	
	
	Q_OBJECT
	
private:
	
	volatile bool isStopped;
	
	std::vector<Glyph*> glyphs;
	
	RenderingSurface* renderingSurface;
	
	LayoutEngine* layoutEngine;
	
	
signals:
	
	void glyphStateChanged();
	
	
public:
	
	Presenter(QWidget* parent = 0);
	~Presenter();

	void run();
	
	void stop();
	
	void setRenderingSurface(RenderingSurface* argSurface);
	
	void setGlyphs(const std::vector<Glyph*> &argGlyphs);

	void setLayoutEngine(LayoutEngine* engine);
	
	void renderGlyphs(QPainter& painter);
	
	void layoutGlyphs(int w, int h);
	
};


#endif