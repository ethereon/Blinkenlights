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
#include <algorithm>
#include <assert.h>
#include "RenderingSurface.h"
#include "HiResTime.h"

using namespace std;

Presenter::Presenter(QWidget* parent) : QThread(parent) {
	
	renderingSurface = NULL;
	layoutEngine = NULL;
	
}

Presenter::~Presenter() {
	
}

void Presenter::setGlyphs(const vector<Glyph*> &argGlyphs) {
	
	this->glyphs = argGlyphs;
	
}


void Presenter::setRenderingSurface(RenderingSurface* argSurface) {
	
	
	this->renderingSurface = argSurface;
	
}

void Presenter::setLayoutEngine(LayoutEngine* engine) {
	
	layoutEngine = engine;
	
}

void Presenter::run() {

	int n = glyphs.size();
	
	assert(n!=0);
	assert(renderingSurface!=NULL);
	assert(layoutEngine!=NULL);
	
	renderingSurface->setPresenter(this);
		
	for(int i=0; i<n; ++i)
		glyphs[i]->start();

	isStopped = false;
	
	connect(this, SIGNAL(glyphStateChanged()), renderingSurface, SLOT(repaint()));
	
	HIRESTIME* epochs = new HIRESTIME[n];
	getCurrentTime(&(epochs[0]));
	
	for(int i=1;i<n;epochs[i++] = epochs[0]) ;
	
	while(!isStopped) {
		
		HIRESTIME currentTime;
		getCurrentTime(&currentTime);		
				
		for(int i=0;i<n;++i) {
			
			HIRESTIME delay = currentTime - epochs[i];
			
			if(delay>glyphs[i]->getTransitionInterval()) {
				
				glyphs[i]->toggleState();
				epochs[i] = currentTime;
				emit glyphStateChanged();
			}
			
		}
		
	}

	
	delete [] epochs;
	
}


void Presenter::renderGlyphs(QPainter& painter)
{
		
	int n = glyphs.size();
	
	for(int i=0;i<n; ++i) 
		glyphs[i]->render(&painter);
	
}

void Presenter::layoutGlyphs(int w, int h) {

	assert(layoutEngine!=NULL);
	
	layoutEngine->layoutGlyphs(&glyphs, w, h);
	
}


