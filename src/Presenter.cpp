/*
 ================================================================
 
 Presenter
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */


#include "Presenter.h"

Presenter::Presenter(QWidget* parent) : QGLWidget(parent) {
	
	setAutoFillBackground(false);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(render()));
	timer->start(10);
	
	
	glyph.setFrequency(7.0);
	glyph.setDimensions(0, 0, 500, 500);
	glyph.start();
	
}

Presenter::~Presenter() {
	

}

void Presenter::render() {
	

	repaint();
	
}

void Presenter::resizeGL(int width, int height) {
	
	setFixedSize(width,height);
	layoutGlyphs();
	
}

void Presenter::paintEvent(QPaintEvent* /* event */)
{
	
	QPainter painter;
	painter.begin(this);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	painter.setPen(Qt::white);
	painter.setBrush(Qt::white);
	
	glyph.render(&painter);
	
	painter.end();
	
	
}



