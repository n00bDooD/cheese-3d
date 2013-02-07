#ifndef VERTEXDATAFORMAT_H
#define VERTEXDATAFORMAT_H

#include "Global.h"
#include <vector>

struct vertexAttrib {
	char* name;
	GLint size;
	GLenum type;
	GLboolean normalized;

	vertexAttrib();
	vertexAttrib(const vertexAttrib&);
	vertexAttrib(char*,GLint,GLenum,GLboolean);
} ;

class vertexDataFormat {
	std::vector<vertexAttrib> vertexAttributes_;

public:
	int count() const; // { return vertexAttributes_.size() }
	vertexAttrib& getAttribute(char*);
	vertexAttrib& getAttribute(unsigned int);
	void addAttribute(vertexAttrib&);
	void deleteAttribute(char*);
} ;

#endif