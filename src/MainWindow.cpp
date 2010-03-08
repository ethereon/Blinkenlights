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


MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent) {
	
	
	presenter = new Presenter(this);
	
	this->setCentralWidget(presenter);

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