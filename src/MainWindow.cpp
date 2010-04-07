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
#include "BinaryOscillator.h"

#include <vector>

using namespace std;

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
	
	//TODO:Create GUI to do this. Free allocated objects

	double frequencies[] = {10};
	
	int glyphCount = 1;
	
//	CheckerboardGlyph* boards = new CheckerboardGlyph[glyphCount];		
	RectGlyph* boards = new RectGlyph[glyphCount];

	vector<Glyph*> glyphs;
	
	for(int i=0;i<glyphCount; ++i) {
		
		boards[i].setFrequency(frequencies[i]);
		glyphs.push_back(&(boards[i]));

	}
	
	presenter.setLayoutEngine(&layoutEngine);
	presenter.setGlyphs(glyphs);
	
	this->setCentralWidget(&renderingSurface);
	
	presenter.setRenderingSurface(&renderingSurface);
	presenter.start();

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