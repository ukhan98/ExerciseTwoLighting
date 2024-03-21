#ifndef RESOLUTION_H
#define RESOLUTION_H

struct Resolution
{
    int m_width;
    int m_height;

    Resolution(int _width, int _height)
    {
        m_width = _width;
        m_height = _height;
    }
};

#endif // RESOLUTION_H

//In the case of a monitor with an industry - standard Full HD 1080p resolution, this display has a resolution of 1920 x 1080. 
//This means that the screen will have a width of 1,920 pixels while the height of the screen will be 1,080 pixels.
//This results in a grand total of 2,073,600 pixels on - screen.