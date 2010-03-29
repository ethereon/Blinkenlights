/*
 ================================================================
 
 MainWindow
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#include "MainWindow.h"
#include "CheckerboardGlyph.h"
#include "RectGlyph.h"
#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
	
		
	double frequencies[] = {7.5,6};
	
	int glyphCount = 2;
	
	CheckerboardGlyph* boards = new CheckerboardGlyph[glyphCount];

	vector<Glyph*> glyphs;
	
	for(int i=0;i<glyphCount; ++i) {
		
		boards[i].setFrequency(frequencies[i]);
		glyphs.push_back(&(boards[i]));

	}
	
	presenter.setGlyphs(glyphs);
	
	this->setCentralWidget(&renderingSurface);
	
	presenter.setRenderingSurface(&renderingSurface);
	presenter.start();//&renderingSurface);

	isFullscreen = false;
	
	keyFullscreen = new QShortcut(QKeySequence("Ctrl+F"),this);

	connect(keyFullscreen, SIGNAL(activated()), this, SLOT(toggleFullscreen()));

}

MainWindow::~MainWindow() {

}

void MainWindow::toggleFullscreen() {
	
	isFullscreen = !isFullscreen;
	
	if(isFullscreen)
		this->showFullScreen();
	else 
		this->showNormal();


}