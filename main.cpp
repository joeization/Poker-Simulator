#include <bits/stdc++.h>
#include "card.h"
#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "opengl32.lib")
using namespace std;
#define PI 3.14159265
#define MAXN 10
GLint ScreenWidth = 800;
GLint ScreenHeight = 600;
GLfloat eyex = 0;
GLfloat eyey = 0;
GLfloat eyez = 0;

GLfloat teyex = 0;
GLfloat teyey = 0;
GLfloat teyez = 0;

GLfloat sca = 0.02;

GLfloat deg = 0;

GLboolean key_buf[256];

GLfloat fp = 1000/60;

GLboolean onfocus;

GLboolean mouserdown;
GLboolean keyldown;
GLboolean mouseldown;

GLint select=-1;

card deck[52];

void processKeysDown(unsigned char key,GLint x,GLint y){
    if(!onfocus)return;
    if(key==27)exit(0);
    else key_buf[key]=1;
}

void processKeysUp(unsigned char key,GLint x,GLint y){
    if(!onfocus)return;
    if(key==27)exit(0);
    else key_buf[key]=0;
}

void ff(GLint a){

    GLboolean is=false;
    if(key_buf['w']){
        is=true;
        eyez+=0.5;
    }
    if(key_buf['s']){
        is=true;
        eyez-=0.5;
    }
    if(key_buf['a']){
        is=true;
        eyex-=0.5;
    }
    if(key_buf['d']){
        is=true;
        eyex+=0.5;
    }
    if(key_buf['+']||key_buf['=']){
        is=true;
        key_buf['+']=key_buf['=']=false;
        sca+=0.005;
    }
    if(key_buf['-']){
        is=true;
        key_buf['-']=false;
        sca-=0.005;
        if(sca<0)sca=0;
    }
    if(key_buf[13]){
        keyldown=true;
        if(select==-1){
            for(GLint i=0;i<52;i++){
                if(deck[i].mouse_on(eyex,eyez)){
                    select=i;
                    deck[i].ssel();
                    break;
                }
            }
        }
    }
    else{
        if(select!=-1&&!mouseldown){
            deck[select].ssel();
            select=-1;
        }
        keyldown=false;
    }
    if(key_buf[8]||key_buf[127]){
        for(GLint i=0;i<52;i++){
            if(deck[i].mouse_on(eyex,eyez)){
                deck[i].svis();
                break;
            }
        }
        key_buf[8]=key_buf[127]=false;
    }
    if(is&&onfocus)glutPostRedisplay();
    glutTimerFunc(fp,ff,0);
}

void RendScene() {
    //if(!onfocus)return;
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    if(onfocus)glutWarpPointer(ScreenWidth/2,ScreenHeight/2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glPushMatrix();

    if(select!=-1){
        deck[select].move_x(eyex);
        deck[select].move_z(eyez);
    }

    glScalef(sca,sca,sca);

    glRotatef(90,-1,0,0);
    glTranslatef(-eyex,0,-eyez);

    for(GLint s=0;s<52;s++){
        deck[s].draw();
    }

    glBegin(GL_LINES);
        glLineWidth(100);
        glColor3f(0,1,1);
        glVertex3f(eyex+1,0.5,eyez);
        glVertex3f(eyex-1,0.5,eyez);
        glVertex3f(eyex,0.5,eyez+1);
        glVertex3f(eyex,0.5,eyez-1);
    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}

void MouseFunc(GLint button, GLint state, GLint x, GLint y){
    if(!onfocus)return;
    else if(state == GLUT_DOWN){
        if(button == GLUT_RIGHT_BUTTON){
            mouserdown = GL_TRUE;
            for(GLint i=0;i<52;i++){
                if(deck[i].mouse_on(eyex,eyez)){
                    deck[i].svis();
                    break;
                }
            }
        }
        if(button == GLUT_LEFT_BUTTON){
            mouseldown = GL_TRUE;
            if(select==-1){
                for(GLint i=0;i<52;i++){
                    if(deck[i].mouse_on(eyex,eyez)){
                        select=i;
                        deck[i].ssel();
                        break;
                    }
                }
            }
        }
    }
    else{
        if(button == GLUT_RIGHT_BUTTON) mouserdown = GL_FALSE;
        if(button == GLUT_LEFT_BUTTON){
            if(select!=-1){
                deck[select].ssel();
                select=-1;
            }
            mouseldown = GL_FALSE;
        }
    }
    eyex+=(x-ScreenWidth/2)/15.0;
    eyez-=(y-ScreenHeight/2)/12.0;
    glutPostRedisplay();
}

void MouseMotionFunc(GLint x, GLint y){
    if(!onfocus)return;
    eyex+=(x-ScreenWidth/2)/15.0;
    eyez-=(y-ScreenHeight/2)/12.0;
    glutPostRedisplay();
}

void EntryFuc(GLint state){
    if(state==GLUT_ENTERED)onfocus=true;
    else onfocus=false;
}

void ReShape(GLint w,GLint h){
    ScreenWidth=w;
    ScreenHeight=h;
    gluPerspective(0,ScreenWidth/ScreenWidth*1.0,0.1,1000);
    glutPostRedisplay();
}

pair<GLint, GLint> li[52];

GLint main(GLint argc, char** argv) {

    memset(key_buf,0,sizeof(key_buf));

    for(GLint s=0;s<4;s++){
        for(GLint i=1;i<=13;i++){
            li[13*s+i-1]=make_pair(s,i);
        }
    }
    srand(time(0));
    random_shuffle(li,li+52);

    for(GLint s=0;s<4;s++){
        for(GLint i=1;i<=13;i++){
            deck[13*s+i-1] = card(li[13*s+i-1].second,li[13*s+i-1].first,(i-7)*11,0,(s-2)*21,1);
        }
    }
    srand(time(0));
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(ScreenWidth, ScreenHeight);
    gluPerspective(0,ScreenWidth/ScreenHeight*1.0,0.1,1000);
    glutCreateWindow("OpenGL");

    glClearColor(160.0/255, 82.0/255, 45.0/255, 1.0f);
    glEnable(GL_DEPTH_TEST);

    glutKeyboardFunc(processKeysDown);
    glutKeyboardUpFunc(processKeysUp);
    glutMouseFunc(MouseFunc);
    glutPassiveMotionFunc(MouseMotionFunc);
    glutMotionFunc(MouseMotionFunc);

    glutEntryFunc(EntryFuc);

    glutDisplayFunc(RendScene);
    glutIdleFunc(RendScene);
    glutTimerFunc(fp,ff,0);
    glutReshapeFunc(ReShape);

    glutSetCursor(GLUT_CURSOR_NONE);
    glutWarpPointer(ScreenWidth/2,ScreenHeight/2);

    glutMainLoop();

    return 0;
}