#ifndef FILM_H
#define FILM_H

class Film
{
public:
    virtual void write(uint32_t xPos, uint32_t yPos, float zDepth, float r, float g, float b) = 0;
};

#endif // FILM_H
