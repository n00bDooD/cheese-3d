#ifndef CHEESERENDERER_H
#define	CHEESERENDERER_H

#include <stdlib.h>
#include <vector>
#include "Quad.h"

class cheeseRenderer {
private:
	vector<quad> primitives_;

public:
	cheeseRenderer(void);
	~cheeseRenderer(void);
	void addPrimitives(quad*);
	bool draw(void);
} ;

#endif