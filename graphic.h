#include <gl/glut.h>
#ifndef GRAPHIC_H
#define GRAPHIC_H

//7 segment mapping
const GLint mp[10]={119, 18, 93, 91, 58, 107, 111, 114, 127, 123};

class graphic{
    static constexpr GLfloat hei = 0.1;

public:

    static void DrawBlankCard(GLfloat midx, GLfloat midy, GLfloat midz,GLboolean ep){
        glBegin(GL_QUADS);
            if(!ep)
                glColor3f(1,1,1);
            else
                glColor3f(0.5,0.5,0.5);
            glVertex3f(-5+midx,0+midy,-10+midz);
            glVertex3f(-5+midx,0+midy,10+midz);
            glVertex3f(5+midx,0+midy,10+midz);
            glVertex3f(5+midx,0+midy,-10+midz);

        glEnd();
        glBegin(GL_LINES);
            glColor3f(0,0,0);
            glLineWidth(100);
            glVertex3f(-5+midx,0+midy,-10+midz);
            glVertex3f(-5+midx,0+midy,10+midz);
            glVertex3f(-5+midx,0+midy,10+midz);
            glVertex3f(5+midx,0+midy,10+midz);
            glVertex3f(5+midx,0+midy,10+midz);
            glVertex3f(5+midx,0+midy,-10+midz);
            glVertex3f(5+midx,0+midy,-10+midz);
            glVertex3f(-5+midx,0+midy,-10+midz);
        glEnd();
    }

    static void DrawSpade(GLfloat midx, GLfloat midy, GLfloat midz, GLboolean neg){
        GLfloat bas;
        if(neg)bas=-1;
        else bas=1;

        glBegin(GL_POLYGON);
            glColor3f(0,0,0);

            glVertex3f(0*bas+midx,hei+midy,-4.5*bas+midz);
            glVertex3f(2*bas+midx,hei+midy,0.5*bas+midz);
            glVertex3f(1.5*bas+midx,hei+midy,1.5*bas+midz);
            glVertex3f(-1.5*bas+midx,hei+midy,1.5*bas+midz);
            glVertex3f(-2*bas+midx,hei+midy,0.5*bas+midz);
            glVertex3f(0*bas+midx,hei+midy,-4.5*bas+midz);

        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3f(0,0,0);
            glVertex3f(0*bas+midx,hei+midy,1.5*bas+midz);
            glVertex3f(-1*bas+midx,hei+midy,3.5*bas+midz);
            glVertex3f(1*bas+midx,hei+midy,3.5*bas+midz);

        glEnd();
    }

    static void DrawDiamond(GLfloat midx, GLfloat midy, GLfloat midz, GLboolean neg){
        GLfloat bas;
        if(neg)bas=-1;
        else bas=1;

        glBegin(GL_QUADS);
            glColor3f(178.0/255,34.0/255,34.0/255);

            glVertex3f(0*bas+midx,hei+midy,-4.5*bas+midz);
            glVertex3f(2*bas+midx,hei+midy,0*bas+midz);
            glVertex3f(0*bas+midx,hei+midy,4.5*bas+midz);
            glVertex3f(-2*bas+midx,hei+midy,0*bas+midz);

        glEnd();
    }

    static void DrawHeart(GLfloat midx, GLfloat midy, GLfloat midz, GLboolean neg){
        GLfloat bas;
        if(neg)bas=-1;
        else bas=1;

        glBegin(GL_POLYGON);
            glColor3f(178.0/255,34.0/255,34.0/255);

            glVertex3f(0*bas+midx,hei+midy,-0.5*bas+midz);
            glVertex3f(1*bas+midx,hei+midy,-2.25*bas+midz);
            glVertex3f(2*bas+midx,hei+midy,0*bas+midz);
            glVertex3f(0*bas+midx,hei+midy,4.5*bas+midz);
            glVertex3f(-2*bas+midx,hei+midy,0*bas+midz);
            glVertex3f(-1*bas+midx,hei+midy,-2.25*bas+midz);

        glEnd();
    }

    static void DrawClub(GLfloat midx, GLfloat midy, GLfloat midz, GLboolean neg){
        GLfloat bas;
        if(neg)bas=-1;
        else bas=1;

        glBegin(GL_QUADS);
            glColor3f(0,0,0);

            glVertex3f(0*bas+midx,hei+midy,-5.0*bas+midz);
            glVertex3f(-1*bas+midx,hei+midy,-1.5*bas+midz);
            glVertex3f(0*bas+midx,hei+midy,0*bas+midz);
            glVertex3f(1*bas+midx,hei+midy,-1.5*bas+midz);

            glVertex3f(0*bas+midx,hei+midy,0*bas+midz);
            glVertex3f(-1.5*bas+midx,hei+midy,-1*bas+midz);
            glVertex3f(-3.5*bas+midx,hei+midy,0*bas+midz);
            glVertex3f(-1.5*bas+midx,hei+midy,1*bas+midz);

            glVertex3f(0*bas+midx,hei+midy,0*bas+midz);
            glVertex3f(1.5*bas+midx,hei+midy,-1*bas+midz);
            glVertex3f(3.5*bas+midx,hei+midy,0*bas+midz);
            glVertex3f(1.5*bas+midx,hei+midy,1*bas+midz);

        glEnd();

        glBegin(GL_TRIANGLES);
            glColor3f(0,0,0);

            glVertex3f(1*bas+midx,hei+midy,3*bas+midz);
            glVertex3f(0*bas+midx,hei+midy,0*bas+midz);
            glVertex3f(-1*bas+midx,hei+midy,3*bas+midz);

        glEnd();
    }

    static void DrawCardAce(GLfloat midx, GLfloat midy, GLfloat midz){
        glBegin(GL_LINES);
            glLineWidth(100);
            glColor3f(0,0,0);
            glVertex3f(2.7+midx,hei+midy,-9.0+midz);
            glVertex3f(3.7+midx,hei+midy,-6.0+midz);
            
            glVertex3f(2.7+midx,hei+midy,-9.0+midz);
            glVertex3f(1.7+midx,hei+midy,-6.0+midz);
            
            glVertex3f(3.2+midx,hei+midy,-7.5+midz);
            glVertex3f(2.2+midx,hei+midy,-7.5+midz);

            glVertex3f(-2.7+midx,hei+midy,9.0+midz);
            glVertex3f(-3.7+midx,hei+midy,6.0+midz);
            
            glVertex3f(-2.7+midx,hei+midy,9.0+midz);
            glVertex3f(-1.7+midx,hei+midy,6.0+midz);
            
            glVertex3f(-3.2+midx,hei+midy,7.5+midz);
            glVertex3f(-2.2+midx,hei+midy,7.5+midz);
        glEnd();
    }

    static void DrawCardKing(GLfloat midx, GLfloat midy, GLfloat midz){
        glBegin(GL_LINES);
            glLineWidth(100);
            glColor3f(0,0,0);

            glVertex3f(3+midx,hei+midy,-8.5+midz);
            glVertex3f(3+midx,hei+midy,-6+midz);

            glVertex3f(3+midx,hei+midy,-7.25+midz);
            glVertex3f(1.5+midx,hei+midy,-6+midz);

            glVertex3f(3+midx,hei+midy,-7.25+midz);
            glVertex3f(1.5+midx,hei+midy,-8.5+midz);

            glVertex3f(-3+midx,hei+midy,8.5+midz);
            glVertex3f(-3+midx,hei+midy,6+midz);

            glVertex3f(-3+midx,hei+midy,7.25+midz);
            glVertex3f(-1.5+midx,hei+midy,6+midz);

            glVertex3f(-3+midx,hei+midy,7.25+midz);
            glVertex3f(-1.5+midx,hei+midy,8.5+midz);
        glEnd();
    }

    static void DrawCardQueen(GLfloat midx, GLfloat midy, GLfloat midz){
        glBegin(GL_LINES);
            glLineWidth(100);
            glColor3f(0,0,0);

            glVertex3f(3+midx,hei+midy,-8.5+midz);
            glVertex3f(3+midx,hei+midy,-6.5+midz);

            glVertex3f(1.5+midx,hei+midy,-8.5+midz);
            glVertex3f(1.5+midx,hei+midy,-6.5+midz);

            glVertex3f(3+midx,hei+midy,-6.5+midz);
            glVertex3f(1.5+midx,hei+midy,-6.5+midz);

            glVertex3f(3+midx,hei+midy,-8.5+midz);
            glVertex3f(1.5+midx,hei+midy,-8.5+midz);

            glVertex3f(2.25+midx,hei+midy,-7.25+midz);
            glVertex3f(1.6875+midx,hei+midy,-5.4375+midz);

            glVertex3f(-3+midx,hei+midy,8.5+midz);
            glVertex3f(-3+midx,hei+midy,6.5+midz);

            glVertex3f(-1.5+midx,hei+midy,8.5+midz);
            glVertex3f(-1.5+midx,hei+midy,6.5+midz);

            glVertex3f(-3+midx,hei+midy,6.5+midz);
            glVertex3f(-1.5+midx,hei+midy,6.5+midz);

            glVertex3f(-3+midx,hei+midy,8.5+midz);
            glVertex3f(-1.5+midx,hei+midy,8.5+midz);

            glVertex3f(-2.25+midx,hei+midy,7.25+midz);
            glVertex3f(-1.6875+midx,hei+midy,5.4375+midz);

        glEnd();
    }

    static void DrawCardJack(GLfloat midx, GLfloat midy, GLfloat midz){
        glBegin(GL_LINES);
            glLineWidth(100);
            glColor3f(0,0,0);

            glVertex3f(3+midx,hei+midy,-8.5+midz);
            glVertex3f(1+midx,hei+midy,-8.5+midz);

            glVertex3f(2+midx,hei+midy,-8.5+midz);
            glVertex3f(2+midx,hei+midy,-6+midz);

            glVertex3f(2+midx,hei+midy,-6+midz);
            glVertex3f(2.75+midx,hei+midy,-7+midz);

            glVertex3f(-3+midx,hei+midy,8.5+midz);
            glVertex3f(-1+midx,hei+midy,8.5+midz);

            glVertex3f(-2+midx,hei+midy,8.5+midz);
            glVertex3f(-2+midx,hei+midy,6+midz);

            glVertex3f(-2+midx,hei+midy,6+midz);
            glVertex3f(-2.75+midx,hei+midy,7+midz);
        glEnd();
    }
    //7-segment LCD!?

    static void DrawSegOne(GLfloat midx, GLfloat midy, GLfloat midz, GLfloat dx){

            glVertex3f(3+midx-dx,hei+midy,-8.5+midz);
            glVertex3f(2+midx-dx,hei+midy,-8.5+midz);

            glVertex3f(-3+midx+dx,hei+midy,8.5+midz);
            glVertex3f(-2+midx+dx,hei+midy,8.5+midz);

    }

    static void DrawSegTwo(GLfloat midx, GLfloat midy, GLfloat midz, GLfloat dx){

            glVertex3f(3+midx-dx,hei+midy,-8.5+midz);
            glVertex3f(3+midx-dx,hei+midy,-7.5+midz);

            glVertex3f(-3+midx+dx,hei+midy,8.5+midz);
            glVertex3f(-3+midx+dx,hei+midy,7.5+midz);

    }

    static void DrawSegThree(GLfloat midx, GLfloat midy, GLfloat midz, GLfloat dx){

            glVertex3f(2+midx-dx,hei+midy,-8.5+midz);
            glVertex3f(2+midx-dx,hei+midy,-7.5+midz);

            glVertex3f(-2+midx+dx,hei+midy,8.5+midz);
            glVertex3f(-2+midx+dx,hei+midy,7.5+midz);

    }

    static void DrawSegFour(GLfloat midx, GLfloat midy, GLfloat midz, GLfloat dx){

            glVertex3f(3+midx-dx,hei+midy,-7.5+midz);
            glVertex3f(2+midx-dx,hei+midy,-7.5+midz);

            glVertex3f(-3+midx+dx,hei+midy,7.5+midz);
            glVertex3f(-2+midx+dx,hei+midy,7.5+midz);

    }

    static void DrawSegFive(GLfloat midx, GLfloat midy, GLfloat midz, GLfloat dx){

            glVertex3f(3+midx-dx,hei+midy,-7.5+midz);
            glVertex3f(3+midx-dx,hei+midy,-6.5+midz);

            glVertex3f(-3+midx+dx,hei+midy,7.5+midz);
            glVertex3f(-3+midx+dx,hei+midy,6.5+midz);

    }

    static void DrawSegSix(GLfloat midx, GLfloat midy, GLfloat midz, GLfloat dx){

            glVertex3f(2+midx-dx,hei+midy,-7.5+midz);
            glVertex3f(2+midx-dx,hei+midy,-6.5+midz);

            glVertex3f(-2+midx+dx,hei+midy,7.5+midz);
            glVertex3f(-2+midx+dx,hei+midy,6.5+midz);

    }

    static void DrawSegSeven(GLfloat midx, GLfloat midy, GLfloat midz, GLfloat dx){

            glVertex3f(3+midx-dx,hei+midy,-6.5+midz);
            glVertex3f(2+midx-dx,hei+midy,-6.5+midz);

            glVertex3f(-3+midx+dx,hei+midy,6.5+midz);
            glVertex3f(-2+midx+dx,hei+midy,6.5+midz);

    }

    static void DrawCardNum(GLint num, GLfloat midx, GLfloat midy, GLfloat midz, GLfloat dx){
        GLint bas=64;
        for(GLint i=0;i<=6;i++){
            if((bas>>i)&mp[num]){
                if(i==0)
                    DrawSegOne(midx,midy,midz,dx);
                else if(i==1)
                    DrawSegTwo(midx,midy,midz,dx);
                else if(i==2)
                    DrawSegThree(midx,midy,midz,dx);
                else if(i==3)
                    DrawSegFour(midx,midy,midz,dx);
                else if(i==4)
                    DrawSegFive(midx,midy,midz,dx);
                else if(i==5)
                    DrawSegSix(midx,midy,midz,dx);
                else if(i==6)
                    DrawSegSeven(midx,midy,midz,dx);
            }
        }
    }

};

#endif