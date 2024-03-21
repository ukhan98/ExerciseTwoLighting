#include "Mesh.h"
#include "Shader.h"

Mesh::Mesh()
{
	m_shader = nullptr;
	m_texture = { };
	m_texture2 = { };

	m_vertexBuffer = 0;
	m_indexBuffer = 0; //you can use an index buffer to reuse vertices 
	//if you have a square composed of two triangles, you only need to store 
	//four vertices (the corners of the square) instead of 
	//six vertices (the corners plus the duplicated vertices for the triangles)
	
	m_position = { 0, 0, 0 };
	m_rotation = { 0, 0, 0 };

	//m_world = glm::mat4(1.0f);
}

Mesh::~Mesh()
{}

void Mesh::Create(Shader* _shader)
{
	m_shader = _shader;
	m_texture = Texture();
	m_texture.LoadTexture("../External/stb/Wood.jpg");
	m_texture2 = Texture();
	m_texture2.LoadTexture("../External/stb/Emoji.jpg");

	m_vertexData = {
		// Position           RGBA Color         Texture Coords
		50.0f,  50.0f, 0.0f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,  // top-right
		50.0f, -50.0f, 0.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,  // bottom-right
		-50.0f, -50.0f, 0.0f, 0.0f, 0.0f, 1.0f,  0.0f, 0.0f,  // bottom-left
		-50.0f,  50.0f, 0.0f, 0.0f, 0.0f, 0.0f,  0.0f, 1.0f   // top-left
	}; //this where we are setting colour of the corners of our mesh

	glGenBuffers(1, &m_vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, m_vertexData.size() * sizeof(float), m_vertexData.data(), GL_STATIC_DRAW);

	m_indexData = {
		2, 0, 3, 2, 1, 0
	};

	glGenBuffers(1, &m_indexBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indexData.size() * sizeof(GLubyte), m_indexData.data(), GL_STATIC_DRAW);

}

void Mesh::Cleanup()
{
	glDeleteBuffers(1, &m_vertexBuffer);
	glDeleteBuffers(1, &m_indexBuffer);
	m_texture.Cleanup();
	m_texture2.Cleanup();
}

void Mesh::Render(glm::mat4 _wvp)
{
	glUseProgram(m_shader->GetProgramID()); // Use our shader

	// 1st attribute buffer : vertices 
	glEnableVertexAttribArray(m_shader->GetAttrVertices());

	glVertexAttribPointer(m_shader->GetAttrVertices(), // The attribute we want to configure
		3,					// size (3 per vertex)
		GL_FLOAT,			// type
		GL_FALSE,			// normalized?
		8 * sizeof(float),	// stride
		(void*)0);			// array buffer offset

	// 2nd attribute buffer: colors
	glEnableVertexAttribArray(m_shader->GetAttrColors());
	glVertexAttribPointer(
		m_shader->GetAttrColors(), // The attribute we want to configure
		4,                          // size (4 components per color value)
		GL_FLOAT,                   // type
		GL_FALSE,                   // normalized?
		8 * sizeof(float),          // stride (7 floats per vertex definition)
		(void*)(3 * sizeof(float))  // array buffer offset
	);

	// 3rd attribute buffer: texCoords
	glEnableVertexAttribArray(m_shader->GetAttrTexCoords());
	glVertexAttribPointer(m_shader->GetAttrTexCoords(), // The attribute we want to configure
		2,                            // size (2 texture coordinates per vertex)
		GL_FLOAT,                     // type
		GL_FALSE,                     // normalized?
		8 * sizeof(float),            // stride (7 floats per vertex definition)
		(void*)(6 * sizeof(float)));  // array buffer offset

	//_wvp *= m_world;
	//glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer);
	//glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &_wvp[0][0]);
	// Draw the triangle!
	//glDrawArrays(GL_TRIANGLES, 0, m_vertexData.size() / 7); // it knows we are rendering triangles (GL_TRIANGLES)														//start from 0 and divide total data points by 7 to get # of trianlges possible
	//glDisableVertexAttribArray(m_shader->GetAttrVertices());

	// 4th attribute : MVP
	m_rotation.y += 0.000f; //test with no rotation first
	glm::mat4 transform = glm::rotate(_wvp, m_rotation.y, glm::vec3(0, 1, 0));
	glUniformMatrix4fv(m_shader->GetAttrWVP(), 1, GL_FALSE, &transform[0][0]);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBuffer); // Bind the vertex buffer
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_indexBuffer); // Bind the index buffer
	
	glActiveTexture(GL_TEXTURE0); //texture unit 0 //used for differentiation of textures
	glBindTexture(GL_TEXTURE_2D, m_texture.GetTexture());
	glUniform1i(m_shader->GetSampler1(), 0);

	glActiveTexture(GL_TEXTURE1); //texture unit 1 //used for differentiation of textures
	glBindTexture(GL_TEXTURE_2D, m_texture2.GetTexture());
	glUniform1i(m_shader->GetSampler2(), 1); //use 1 to show z-index

	glDrawElements(GL_TRIANGLES, m_indexData.size(), GL_UNSIGNED_BYTE, (void*)0);
	glDisableVertexAttribArray(m_shader->GetAttrColors());
	glDisableVertexAttribArray(m_shader->GetAttrVertices());
	glDisableVertexAttribArray(m_shader->GetAttrTexCoords());

}

void Mesh::SetShaderYuvUniforms(float y, float u, float v) {
	
	// Activate the shader program
	glUseProgram(m_shader->GetProgramID());

	// Set the uniforms for the YUV values
	glUniform1f(glGetUniformLocation(m_shader->GetProgramID(), "yValue"), y);
	glUniform1f(glGetUniformLocation(m_shader->GetProgramID(), "uValue"), u);
	glUniform1f(glGetUniformLocation(m_shader->GetProgramID(), "vValue"), v);

}


