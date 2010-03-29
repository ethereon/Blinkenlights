/*
 ================================================================
 
 Rendering Surface
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#ifndef __RENDERING_SURFACE_H__
#define __RENDERING_SURFACE_H__

#include <QtGui>
#include <QGLWidget>
#include <Presenter.h>

class RenderingSurface : public QGLWidget {
	
	Q_OBJECT
	
	
private:

	Presenter* presenter;
	
	void paintEvent(QPaintEvent *event);
	void resizeGL(int width, int height);

	
public:
	
	RenderingSurface(QWidget* parent=0);
	~RenderingSurface();
	
	void setPresenter(Presenter* argPresenter);
	
	
};

#endif