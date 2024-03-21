#ifndef SHADER_H
#define SHADER_H

#include "..\Lighting\StandardIncludes.h"

class Shader
{
public:
    // Constructors / Destructors
    Shader();
    virtual ~Shader() { }

    // Accessors
    GLuint GetProgramID() { return m_programID; }
    GLuint GetAttrVertices() { return m_attrVertices; }

    GLuint GetAttrColors() { return m_attrColors; }
    GLuint GetAttrWVP() { return m_attrWVP; } //access WVP matrix in the vertex shader .txt file

    GLuint GetAttrTexCoords() { return m_attrTexCoords; }
    GLuint GetSampler1() { return m_sampler1; }
    GLuint GetSampler2() { return m_sampler2; }

    // Methods
    void LoadShaders(const char* _vertexFilePath, const char* _fragmentFilePath);
    void Cleanup();


private:
    // Methods
    void CreateShaderProgram(const char* _vertexFilePath, const char* _fragmentFilePath);
    GLuint LoadShaderFile(const char* _filePath, GLenum _type);
    void LoadAttributes();
    void EvaluateShader(int _infoLength, GLuint _id);

    // Members
    GLuint m_programID; // ID of our shader program
    GLuint m_attrVertices; // Handle for the attribute vertex buffer

    GLuint m_attrColors;
    GLuint m_attrWVP;

    GLuint m_attrTexCoords;
    GLuint m_sampler1;
    GLuint m_sampler2;

    GLint m_result = GL_FALSE;
    int m_infoLogLength;
};

#endif // SHADER_H

 