#include "Texture.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

Texture::Texture()
{
    m_width = 0;
    m_height = 0;
    m_channels = 0;
    m_texture = 0;
}

void Texture::Cleanup()
{
    glDeleteTextures(1, &m_texture);
}

void Texture::LoadTexture(string _fileName)
{
    glGenTextures(1, &m_texture);
    glBindTexture(GL_TEXTURE_2D, m_texture);

    // Set the texture wrapping/filtering options (on the currently bound texture)
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Load and generate the texture
    stbi_set_flip_vertically_on_load(true); //flip the y axis (image defualt has y on top) 
    GLubyte* data = stbi_load(_fileName.c_str(), &m_width, &m_height, &m_channels, 0);
    M_ASSERT(data != nullptr, "Failed to load texture");
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D); //creates the series of smaller versions of the texture

    // Free image data from RAM
    stbi_image_free(data);
}
