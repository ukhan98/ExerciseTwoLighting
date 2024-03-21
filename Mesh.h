#ifndef MESH_H 
#define MESH_H

#include "StandardIncludes.h" // Include standard project-wide includes and definitions
#include "Texture.h"

class Shader; // Forward declaration of the Shader class

// Mesh class: Represents a 3D mesh object in the scene.
class Mesh
{
public:
	// Constructors / Destructors 
	Mesh(); // Constructor: Initializes a new instance of the Mesh class.
	virtual ~Mesh(); // Destructor: Cleans up resources used by the Mesh instance.

	// Methods
	void Create(Shader* _shader); // Initializes the mesh with a specific shader.
	void Cleanup(); // Cleans up resources associated with the mesh, such as buffers.
	void Render(glm::mat4 _wvp); // Renders the mesh using a world-view-projection matrix.
	void SetShaderYuvUniforms(float y, float u, float v);

private:
	Shader* m_shader; // Pointer to the Shader object used for rendering the mesh.
	GLuint m_vertexBuffer; // OpenGL identifier for the vertex buffer.
	std::vector<GLfloat> m_vertexData; // Array of vertex data (positions, normals, etc.).
	
	glm::mat4 m_world; // World matrix representing the mesh's position and orientation in the scene.
      
	Texture m_texture;
	Texture m_texture2;
	GLuint m_indexBuffer; // GPU buffer
	std::vector<GLubyte> m_indexData; // Store index data in RAM
    
	glm::vec3 m_position;
    glm::vec3 m_rotation;
};

#endif // MESH_H