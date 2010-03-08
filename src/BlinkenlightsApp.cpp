/*
 ================================================================
 
 BlinkenlightsApp
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#include "BlinkenlightsApp.h"
#include <assert.h>


BlinkenlightsApp* BlinkenlightsApp::instance = NULL;

BlinkenlightsApp::BlinkenlightsApp() {

}


BlinkenlightsApp* BlinkenlightsApp::Instance()
{
	
	if(!instance)
		instance = new BlinkenlightsApp();
	
	return instance;
}



int BlinkenlightsApp::execute(int argc, char** argv) {
	
	app = new QApplication(argc, argv);
	
	
	//Acquire the shared instance to the Main Window
	mainWindow = new MainWindow();
	
	mainWindow->resize(800,600);
	mainWindow->show();
	mainWindow->setWindowTitle(QApplication::translate("appName","Blinkenlights"));
	
	
	return app->exec();
	
}

