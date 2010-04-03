/*
 *  GridLayoutEngine.cpp
 *  Blinkenlights
 *
 *  Created by Saumitro Dasgupta on 4/2/10.
 *  Copyright 2010 __MyCompanyName__. All rights reserved.
 *
 */

#include "GridLayoutEngine.h"
#include <assert.h>
#include <cmath>
#include <algorithm>

using namespace std;

GridLayoutEngine::GridLayoutEngine() {

	maxGlyphsPerRow = 2;
	spacing = 2;
	
}

GridLayoutEngine::~GridLayoutEngine() {

}


void GridLayoutEngine::layoutGlyphs(vector<Glyph*>* glyphs, int width, int height) {
	
	int n = glyphs->size();
	
	assert(n!=0);
		
	int glyphsPerRow = min(n, maxGlyphsPerRow);
	int glyphsPerCol = ceil(n/(double)maxGlyphsPerRow);

	int glyphWidth = ((width-spacing)/glyphsPerRow)-spacing;
	int glyphHeight = ((height-spacing)/glyphsPerCol)-spacing;
	
	for(int i=0; i<n; ++i) {
		
		int row = i/glyphsPerRow;
		int col = i%glyphsPerRow;

		int x = col*(glyphWidth + spacing);
		int y = row*(glyphHeight + spacing);

		
		(*glyphs)[i]->setDimensions(x+spacing,y+spacing,glyphWidth, glyphHeight);
		
	}

}