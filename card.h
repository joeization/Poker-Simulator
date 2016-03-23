#include "graphic.h"
#include <algorithm>
#include <iostream>
#ifndef CARD_H
#define CARD_H

#define SPADE 3
#define CLUB 0
#define HEART 2
#define DIAMOND 1
class card{
private:
    GLint point;
    std::string rp;
    GLint suit;
    GLfloat midx,midy,midz;
    GLboolean neg;
    GLboolean vis;
    GLboolean sel;
public:
    card(GLint _point, GLint _suit,
        GLfloat _midx=0,GLfloat _midy=0,GLfloat _midz=0,GLboolean _neg=0);
    card();
    ~card();
    void draw();
    void move_x(GLint d);
    void move_z(GLint d);
    GLboolean mouse_on(GLfloat x,GLfloat y);
    void svis();
    void ssel();
};
#endif