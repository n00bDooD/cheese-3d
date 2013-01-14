#include "Mesh.h"


Mesh::Mesh(GLfloat* vertices,GLuint* elements)
{
	m_vertices = vertices;
	m_elements = elements;
}

void Mesh::SetVertices (GLfloat* verts) {
	m_vertices = verts;
}

GLfloat* Mesh::GetVertices() {
	return m_vertices;
}

void Mesh::SetElements (GLuint* elems) {
	m_elements = elems;
}

GLuint* Mesh::GetElements () {
	return m_elements;
}


Mesh::~Mesh(void)
{
	delete[] &m_elements;
	delete[] &m_vertices;
}
