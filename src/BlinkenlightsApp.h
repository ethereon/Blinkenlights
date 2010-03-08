/*
 ================================================================
 
 BlinkenlightsApp
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#ifndef __BLINKENLIGHTS_APP_H__
#define __BLINKENLIGHTS_APP_H__

#include "MainWindow.h"
#include <QtGui>

class BlinkenlightsApp : public QObject {
	
	Q_OBJECT
	
private:
	
	BlinkenlightsApp();
	
	QApplication* app;
	
	MainWindow* mainWindow;
	
	//Singleton pointer
	static BlinkenlightsApp* instance;
	
public:
	
	static BlinkenlightsApp* Instance();
	
	int execute(int argc, char** argv);
	
	
};


#endif