/*
 *  GridLayoutEngine.h
 *  Blinkenlights
 *
 *  Created by Saumitro Dasgupta on 4/2/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
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