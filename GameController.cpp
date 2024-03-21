#include "GameController.h" 
#include "WindowController.h"
#include "ChangePixelToolWindow.h" //need this to show the toolwindow
//#include "CalculatorForm.h"

GameController::GameController()
{
	m_shader = {};
	m_camera = {};
	m_mesh = {};
}

void GameController::Initialize()
{
	GLFWwindow* window = WindowController::GetInstance().GetWindow(); // Call this first, as it creates a window required by GLEW 
	M_ASSERT(glewInit() == GLEW_OK, "Failed to initialize GLEW."); // Initialize GLEW
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // black blue background

	//create a default prespective camera
	m_camera = Camera(WindowController::GetInstance().GetResolution());
}

void GameController::RunGame()
{
	// show the C++/CLi tool window 
	Lighting::ChangePixelToolWindow^ window = gcnew Lighting::ChangePixelToolWindow(&m_mesh);
	window->Show(); 

	//create and compile our GLSL program from the shaders
	m_shader = Shader();
	m_shader.LoadShaders("Shaders/SimpleVertexShader.vertexshader.txt", "Shaders/SimpleFragmentShader.fragmentshader.txt");

	m_mesh = Mesh();
	m_mesh.Create(&m_shader);

	GLFWwindow* win = WindowController::GetInstance().GetWindow();  
	do
	{
		glClear(GL_COLOR_BUFFER_BIT); // Clear the screen
		m_mesh.Render(m_camera.GetProjection() * m_camera.GetView());
		glfwSwapBuffers(WindowController::GetInstance().GetWindow()); // Swap the front and back buffers
		glfwPollEvents();
	} while (glfwGetKey(win, GLFW_KEY_ESCAPE) != GLFW_PRESS && // Check if the ESC key was pressed 
		glfwWindowShouldClose(win) == 0); // Check if the window was closed

	m_mesh.Cleanup();
	m_shader.Cleanup();
}


