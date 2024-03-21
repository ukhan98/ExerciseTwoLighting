#ifndef GAME_CONTROLLER_H 
#define GAME_CONTROLLER_H

#include "StandardIncludes.h"
#include "Shader.h"
#include "Mesh.h"
#include "Camera.h"

class GameController : public Singleton<GameController>
{
public:

	// Construtors / Destructors 
	GameController();
	virtual ~GameController() { }

	// Method Declarations (will be implemented in .cpp file of this .h )  
	void Initialize();
	void RunGame();
	//void RunCalculator();

private:
	Shader m_shader;
	Camera m_camera;
	Mesh m_mesh;
};

#endif // GAME_CONTROLLER_H

