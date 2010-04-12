/*
 ================================================================
 
 Grid Layout Engine
 Blinkenlights / The Myelin Project
 
 Copyright (C) 2010 Saumitro Dasgupta.
 This code is made available under the MIT License.
 <http://www.opensource.org/licenses/mit-license.html>
 
 ================================================================
 */

#ifndef __GRID_LAYOUT_ENGINE_H__
#define __GRID_LAYOUT_ENGINE_H__

#include "LayoutEngine.h"

class GridLayoutEngine : public LayoutEngine {
	
	int maxGlyphsPerRow;
	
	int spacing;
	
public:
	
	GridLayoutEngine();
	~GridLayoutEngine();
	
	void setMaxGlyphsPerRow(int count) { maxGlyphsPerRow = count; }
	
	void setSpacing(int argSpacing) { spacing = argSpacing; }
	
	void layoutGlyphs(vector<Glyph*>* glyphs, int width, int height);
	
};

#endif