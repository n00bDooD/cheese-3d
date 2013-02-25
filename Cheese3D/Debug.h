#ifndef DEBUG_H
#define DEBUG_H
#ifdef _DEBUG

#define CheckOpenGL() \
if (true) { \
    GLenum __error = glGetError(); \
    if(__error) std::cout <<  "OpenGL error! File: " << __FILE__ <<  ", Line: " << __LINE__ << ", Error:" << __error << std::endl; \
} else (void)0

#else
#define CheckOpenGL() (void)0
#endif //_DEBUG

#endif