#ifndef TEXTURE_H
#define TEXTURE_H

#include "StandardIncludes.h"

class Texture
{
public:
    // Constructors / Destructors
    Texture();
    virtual ~Texture() { }

    // Accessors
    GLuint GetTexture() { return m_texture; }

    // Methods
    void LoadTexture(string _fileName);
    void Cleanup();

private:
    // Members
    int m_width;
    int m_height;
    int m_channels;   //likely holds the number of color channels in the texture
    GLuint m_texture; //this ID is used to reference the texture for binding it to a shader
};

#endif // TEXTURE_H


