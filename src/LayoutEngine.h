/*
 *  LayoutEngine.h
 *  Blinkenlights
 *
 *  Created by Saumitro Dasgupta on 4/2/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __LAYOUT_ENGINE_H__
#define __LAYOUT_ENGINE_H__

#include <vector>
#include "Glyph.h"

using namespace std;

class LayoutEngine {

public:
	
	LayoutEngine() {}
	~LayoutEngine() {}
	
	
	virtual void layoutGlyphs(vector<Glyph*>* glyphs, int width, int height)=0;
	
};

#endif