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
#include <assert.h>

using namespace std;

Presenter::Presenter(QWidget* parent) : QGLWidget(parent) {
	
	setAutoFillBackground(false);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(render()));
	

	
	glyphs = NULL;
	spacing = 2;

}

Presenter::~Presenter() {
	
}

void Presenter::setGlyphs(std::vector<Glyph*>* argGlyphs) {
	
	this->glyphs = argGlyphs;
	
}

void Presenter::render() {
	
	repaint();
	
}

void Presenter::resizeGL(int /* width */, int /* height */) {
		
	if(glyphs!=NULL)
		layoutGlyphs();
	
}

void Presenter::start() {
	
	
	assert(glyphs!=NULL);
	
	layoutGlyphs();
	
	int n = glyphs->size();
	
	for(int i=0; i<n; ++i)
		(*glyphs)[i]->start();

	
	timer->start(10);	
	
}

void Presenter::layoutGlyphs() {

	assert(glyphs!=NULL);

	
	int w = this->width();
	int h = this->height();
	
	int n = glyphs->size();
	
	int glyphWidth = ((w-spacing)/n)-spacing;
	int glyphHeight = h - (2*spacing);
	
	for(int i=0; i<n; ++i) {
		
		int x = glyphWidth*i;
		
		(*glyphs)[i]->setDimensions(x+spacing,spacing,glyphWidth, glyphHeight);
		
	}
	
	
}

void Presenter::paintEvent(QPaintEvent* /* event */)
{
	
	QPainter painter;
	painter.begin(this);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	painter.setPen(Qt::white);
	painter.setBrush(Qt::white);
	
	int n = glyphs->size();
	
	for(int i=0;i<n; ++i) 
		(*glyphs)[i]->render(&painter);


	
	painter.end();
	
	
}



