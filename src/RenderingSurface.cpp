/*
 ================================================================
 
 Rendering Surface
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#include "RenderingSurface.h"

#ifdef __APPLE__

#include <OpenGL/OpenGL.h>
#include <OpenGL/gl.h>

#endif


RenderingSurface::RenderingSurface(QWidget* parent) : QGLWidget(parent) {
	
	makeCurrent();
	
#ifdef __APPLE__
	
	GLint sync = 1;
	CGLContextObj ctx = CGLGetCurrentContext();
	CGLSetParameter (ctx, kCGLCPSwapInterval, &sync);
	
	
#endif
	
	setAutoFillBackground(false);
	
	presenter = NULL;


}

RenderingSurface::~RenderingSurface() {

}


void RenderingSurface::setPresenter(Presenter* argPresenter) {
	
	presenter = argPresenter;
	
}

void RenderingSurface::paintEvent(QPaintEvent* /* event */)
{
	if (presenter==NULL) return;
	
	QPainter painter;
	painter.begin(this);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	painter.setPen(Qt::white);
	painter.setBrush(Qt::white);
	
	presenter->renderGlyphs(painter);	
	
	painter.end();
	
	
}

void RenderingSurface::resizeGL(int width, int height) {

	if(presenter!=NULL)
		presenter->layoutGlyphs(width, height);

	
}
