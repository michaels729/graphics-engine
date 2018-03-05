#ifndef FILM_H
#define FILM_H

class Film
{
public:
    virtual void write(int posX, int posY, int r, int g, int b) = 0;
};

#endif // FILM_H
