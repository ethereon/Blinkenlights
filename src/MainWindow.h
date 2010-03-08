/*
 ================================================================
 
 MainWindow
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#ifndef __MAINWINDOW_H__
#define	__MAINWINDOW_H__


#include <QtGui>
#include "Presenter.h"

class MainWindow : public QMainWindow {
	
    Q_OBJECT
	
	
private:
	
	Presenter* presenter;
	
	bool isFullscreen;

	QShortcut* keyFullscreen;
	
private slots:
	
	void toggleFullscreen();
	
public:
	
	MainWindow(QWidget* parent=0);	
    ~MainWindow();
		
};

#endif

