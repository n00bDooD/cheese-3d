#ifndef MATERIAL_H
#define MATERIAL_H

class material {
private:
	char* fragmentShader_;
	char* vertexShader_;
public:
	material(char*, char*);
	char* getFragmentShader(void);
	char* getVertexShader(void);
} ;

#endif