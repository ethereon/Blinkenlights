/*
 ================================================================
 
 Glyph
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#ifndef __GLYPH_H__
#define __GLYPH_H__

#include <QtGui>

class Glyph : public QObject {
	
	
	Q_OBJECT
	
protected:
	
	double halfPeriod;
	
	QTimer timer;
	
	bool state;
	
	double rX,rY,rWidth,rHeight;
	
	virtual void onStarting() {};
	virtual void onResized() {};
	
public slots:
	
	void toggleState();
	
	
public:
	
	
	Glyph(QObject* Parent = 0);
	~Glyph();
		
	void setFrequency(double f);
	void start();
	void stop();
	
	void setDimensions(double argX, double argY, double argW, double argH); 
	
	virtual void render(QPainter* painter) = 0;

};
		
#endif