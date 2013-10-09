#ifndef _TEXTURE_H
#define _TEXTURE_H

#include <GL/glut.h>

class Texture {
public:
    static int count;
    unsigned char *data;
    GLuint textureId;
    int width;
    int height;

    Texture();
    ~Texture();

    Texture(const Texture &a);
    Texture &operator= (const Texture &rhs);
};

#endif /* _TEXTURE_H */
