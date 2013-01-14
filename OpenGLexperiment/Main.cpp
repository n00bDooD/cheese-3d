#include <glload/gl_3_3.h> //OpenGL version 3.3, core profile. C-style functions.
#include <glload/gll.h>    //The C-style loading interface.
 
//Include headers for FreeGLUT/GLFW/other GL tools.
 
int main(int argc, char *argv[])
{
  //Initialize OpenGL and bind the context
 
  if(LoadFunctions() == LS_LOAD_FAILED)
    //exit in some way
 
  //Loading succeeded. Now use OpenGL functions.
 
  //Do OpenGL stuff.
  GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);
  ...
}