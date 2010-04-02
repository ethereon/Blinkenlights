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
#include <time.h>


class Glyph : public QObject {
	
	
	Q_OBJECT
	
protected:
	
	double transitionInterval;
	
	double frequency;
	
	bool state;
	
	
	int rX,rY,rWidth,rHeight;
	
	virtual void onStarting() {};
	virtual void onResized() {};
	
public slots:
	
	void toggleState();
	
	
public:
	
	
	Glyph(QObject* Parent = 0);
	~Glyph();
		
	double getFrequency() const { return frequency; }
	double getTransitionInterval() const { return transitionInterval; }
	void setFrequency(double f);
	void start();
	void stop();
	
	void setDimensions(int argX, int argY, int argW, int argH); 
	
	virtual void render(QPainter* painter) = 0;
	
	bool operator <(const Glyph& v) { return frequency < v.getFrequency(); }

};
		
#endif