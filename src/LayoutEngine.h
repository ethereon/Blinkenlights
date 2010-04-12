/*
 ================================================================
 
 Layout Engine Interface
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
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