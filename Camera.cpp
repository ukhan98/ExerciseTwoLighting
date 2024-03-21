#include "Camera.h"

Camera::Camera()
{
    m_projection = { };
    m_view = { };
}

Camera::Camera(Resolution _screenResolution)
{
    // Projection matrix: 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units 
    //we can adjust field of view to look at smaller section of screen appearing closer to triangles
    m_projection = glm::perspective(glm::radians(90.0f),
        (float)_screenResolution.m_width / (float)_screenResolution.m_height,
        0.1f, /* near clipping range, bjects closer to the camera than this distance will not be rendered.*/
        135.0f); /*far clipping range*/ 
    
    /*why does increasing this far clipping range show the whole wood image 
    upon rotation, at 100 only half of the image was being rendered*/ 
    /*gets too far upon rotation and breaks out of scene i.e (scene max = far clipping range)*/

 

    // Camera matrix
    m_view = glm::lookAt(
        glm::vec3(0, 0, 100), // Camera is at (4,3,3), in World Space //we can adjust this to look at the traingles closer or further (closer smaller value)
        glm::vec3(0, 0, 0), // and looks at the origin
        glm::vec3(0, 1, 0)  // Head is up (set to 0,-1,0 to look upside-down)
    );
}

Camera::~Camera()
{
}
