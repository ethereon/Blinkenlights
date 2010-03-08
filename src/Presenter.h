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
#include <QGLWidget>
#include "RectGlyph.h"
#include "CheckerboardGlyph.h"

class Presenter : public QGLWidget {
	
	
	Q_OBJECT
	
	
public slots:

	void render();
	
	
private:
	
	QTimer* timer;
	
	void paintEvent(QPaintEvent *event);
	void resizeGL(int width, int height);
	CheckerboardGlyph glyph;
	
public:
	
	Presenter(QWidget* parent = 0);
	~Presenter();
	
	
	
};


#endif