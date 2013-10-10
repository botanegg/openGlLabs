#include "Texture.h"

#include <stdlib.h>
#include <memory.h>

Texture::Texture() : data(0), textureId(0), width(8), height(8) {
    count++;
    data = new unsigned char[width * height * 3];

    for(int i = 0; i < width * height ; ++i) {
        int pos = i * 3;
        unsigned char c = (unsigned char)(((i + (i >> 3)) % 2) * 255);
        data[pos] = c;
        data[pos + 1] = count * 64 % 256;
        data[pos + 2] = c;
    }

    glEnable(GL_TEXTURE_2D);
    {
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    glDisable(GL_TEXTURE_2D);
}

Texture::Texture(const Texture &a): data(0), textureId(0), width(a.width), height(a.height) {
    count++;
    data = new unsigned char[width * height * 3];
    memcpy(data, a.data, width * height * 3);

    glEnable(GL_TEXTURE_2D);
    {
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    glDisable(GL_TEXTURE_2D);
}


Texture &Texture::operator= (const Texture &rhs) {
    if (this == &rhs) return *this;
    
    glDeleteTextures(1, &textureId);
    delete [] data;

    width = rhs.width;
    height = rhs.height;
    data = new unsigned char[width * height * 3];
    memcpy(data, rhs.data, width * height * 3);

    glEnable(GL_TEXTURE_2D);
    {
        glGenTextures(1, &textureId);
        glBindTexture(GL_TEXTURE_2D, textureId);

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    }
    glDisable(GL_TEXTURE_2D);
    return *this;
}

Texture::~Texture() {
    count--;

    glDeleteTextures(1, &textureId);
    delete [] data;
}

int Texture::count = 0;
