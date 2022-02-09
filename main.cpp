#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#include "glm.h"
#include "Texture.h"
#include <iostream>
#include <mmsystem.h>

#define M_PI			3.14
#define DEF_dollyStepSize	0.4
#define DEF_angleSensitivity	0.025


using namespace std;

static float ypoz = 0, zpoz = 0;
float cX =2, cY = 0.75,cZ = 5;
float aX=0, aY = 0,aZ=0;
float mX=0, mY = 0,mZ=-50;

GLMmodel* punteroM1 = NULL;
GLMmodel* punteroM2 = NULL;
GLMmodel* punteroM3 = NULL;
GLMmodel* punteroM4 = NULL;
GLMmodel* punteroM5 = NULL;
GLMmodel* punteroM6 = NULL;
GLMmodel* punteroM7 = NULL;
GLMmodel* punteroM8 = NULL;
GLMmodel* punteroM9 = NULL;
GLMmodel* punteroM10 = NULL;
GLMmodel* punteroM11 = NULL;
GLMmodel* punteroM12 = NULL;
GLMmodel* punteroM13 = NULL;
GLMmodel* punteroM14 = NULL;
GLMmodel* punteroM15 = NULL;
GLMmodel* punteroM16 = NULL;
GLMmodel* punteroM17 = NULL;
GLMmodel* punteroM18 = NULL;
GLMmodel* punteroM19 = NULL;
GLMmodel* punteroM20 = NULL;
GLMmodel* punteroM21 = NULL;
GLMmodel* punteroM22 = NULL;
GLMmodel* punteroM23 = NULL;
GLMmodel* punteroM24 = NULL;
GLMmodel* punteroM25 = NULL;
GLMmodel* punteroM26 = NULL;
GLMmodel* punteroM27 = NULL;
GLMmodel* punteroM28 = NULL;
GLMmodel* punteroM29 = NULL;
GLMmodel* punteroM30 = NULL;
GLMmodel* punteroM31 = NULL;
GLMmodel* punteroM32 = NULL;
GLMmodel* punteroM33 = NULL;
GLMmodel* punteroM34 = NULL;
GLMmodel* punteroM35 = NULL;
GLMmodel* punteroM36 = NULL;
GLMmodel* punteroM37 = NULL;
GLMmodel* punteroM38 = NULL;
GLMmodel* punteroM39 = NULL;
GLMmodel* punteroM40 = NULL;

///ANGULOS DE ROTACION
float anguloPuerta = 0;

///MOVIMIENTO DE CAMARA
int	isInMouseDrag = false;
int	mouseIsInverted = true;
int	viewPortCenterX = -1;
int	viewPortCenterY = -1;
int	oldCursorID = 0;
int	oldCursorX = 0;
int	oldCursorY = 0;


GLfloat	camX = 2.0;
GLfloat	camY = 0.75;
GLfloat	camZ = 5.0;
GLfloat	camYaw = 0.0;
GLfloat	camPitch = -50.0;

GLuint	texture;
Texture	treeTextureAr[40];

bool LoadTreeTextures()
{
	int i;
	if (LoadTGA(&treeTextureAr[0], "modelos/grass_08_v2+.tga") && LoadTGA(&treeTextureAr[1], "modelos/T_House.tga") && LoadTGA(&treeTextureAr[2], "modelos/background.tga")
        && LoadTGA(&treeTextureAr[3], "modelos/casaP.tga") && LoadTGA(&treeTextureAr[4], "modelos/tex_wall_inside_1.tga")
        && LoadTGA(&treeTextureAr[5], "modelos/tex_floor_1.tga") && LoadTGA(&treeTextureAr[6], "modelos/dormitorio/cama.tga")
        && LoadTGA(&treeTextureAr[7], "modelos/dormitorio/mesita.tga")&& LoadTGA(&treeTextureAr[8], "modelos/dormitorio/armario.tga")
        && LoadTGA(&treeTextureAr[9], "modelos/dormitorio/osito.tga") && LoadTGA(&treeTextureAr[10], "modelos/bano/toalla.tga")
        && LoadTGA(&treeTextureAr[11], "modelos/bano/banera.tga") && LoadTGA(&treeTextureAr[12], "modelos/bano/ph.tga")
        && LoadTGA(&treeTextureAr[13], "modelos/sala/calendario.tga") && LoadTGA(&treeTextureAr[14], "modelos/sala/librero.tga")
        && LoadTGA(&treeTextureAr[15], "modelos/sala/mesatv.tga") && LoadTGA(&treeTextureAr[16], "modelos/sala/mueble.tga")
        && LoadTGA(&treeTextureAr[18], "modelos/sala/sillon.tga")
        && LoadTGA(&treeTextureAr[19], "modelos/sala/tv.tga") && LoadTGA(&treeTextureAr[20], "modelos/cocina/cocina.tga")
        && LoadTGA(&treeTextureAr[21], "modelos/cocina/durazno.tga")&& LoadTGA(&treeTextureAr[22], "modelos/cocina/fresa.tga")
        && LoadTGA(&treeTextureAr[23], "modelos/cocina/frigider.tga") && LoadTGA(&treeTextureAr[24], "modelos/cocina/lavador.tga")
        && LoadTGA(&treeTextureAr[25], "modelos/cocina/manzana.tga") && LoadTGA(&treeTextureAr[26], "modelos/cocina/mesa.tga")
        && LoadTGA(&treeTextureAr[27], "modelos/cocina/naranja.tga") && LoadTGA(&treeTextureAr[28], "modelos/cocina/olla.tga")
        && LoadTGA(&treeTextureAr[29], "modelos/cocina/pera.tga") && LoadTGA(&treeTextureAr[30], "modelos/cocina/banana.tga")
        && LoadTGA(&treeTextureAr[31], "modelos/cocina/plato.tga") && LoadTGA(&treeTextureAr[32], "modelos/cocina/uvas.tga")
        && LoadTGA(&treeTextureAr[33], "modelos/bano/water.tga"))

    {

		for (i = 0; i < 34; i++)
        {
			glGenTextures(1, &treeTextureAr[i].texID);
			glBindTexture(GL_TEXTURE_2D, treeTextureAr[i].texID);
			glTexImage2D(GL_TEXTURE_2D, 0, treeTextureAr[i].bpp / 8, treeTextureAr[i].width, treeTextureAr[i].height, 0, treeTextureAr[i].type, GL_UNSIGNED_BYTE, treeTextureAr[i].imageData);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			glEnable(GL_TEXTURE_2D);
			if (treeTextureAr[i].imageData)
			{
				free(treeTextureAr[i].imageData);
			}
		}
		return true;
	}
	else
	{
		return false;
	}
}

void enterMouseDrag( int x, int y )
{
    if( isInMouseDrag )
        return;
    isInMouseDrag = true;
    if( viewPortCenterX < 0 )
    {
        viewPortCenterX = glutGet( GLUT_WINDOW_WIDTH ) / 2;
        viewPortCenterY = glutGet( GLUT_WINDOW_HEIGHT ) / 2;
    }
    oldCursorID = glutGet( GLUT_WINDOW_CURSOR );
    oldCursorX = x;
    oldCursorY = y;
    glutSetCursor( GLUT_CURSOR_NONE );
    glutWarpPointer( viewPortCenterX, viewPortCenterY );
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	LoadTreeTextures();
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	enterMouseDrag( 0, 0 );
}

void graficar(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    glPushMatrix();

        glRotatef( -camPitch, 1.0, 0.0, 0.0 );
        glRotatef( -camYaw, 0.0, 1.0, 0.0 );
        glTranslatef( -camX, -camY, -camZ );
        glPushMatrix();
            glScalef(1.8,1.8,1.8);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[0].texID);
            glmDraw(punteroM1, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[2].texID);
            glmDraw(punteroM2, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[1].texID);
            glmDraw(punteroM3, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[3].texID);
            glmDraw(punteroM4, GLM_SMOOTH | GLM_TEXTURE);

            glPushMatrix();
                glTranslatef(-0.292814, 0.573137, 1.324023);
                glRotatef(-anguloPuerta, 0,1,0);
                glTranslatef(0.292814, -0.573137, -1.324023);
                glBindTexture(GL_TEXTURE_2D, treeTextureAr[3].texID);
                glmDraw(punteroM38, GLM_SMOOTH | GLM_TEXTURE);
            glPopMatrix();

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[1].texID);
            glmDraw(punteroM5, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[4].texID);
            glmDraw(punteroM6, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[4].texID);
            glmDraw(punteroM7, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[5].texID);
            glmDraw(punteroM8, GLM_SMOOTH | GLM_TEXTURE);

            /// DORMITORIO

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[6].texID);
            glmDraw(punteroM9, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[7].texID);
            glmDraw(punteroM10, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[8].texID);
            glmDraw(punteroM11, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[9].texID);
            glmDraw(punteroM12, GLM_SMOOTH | GLM_TEXTURE);

            ///BAÑO

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[33].texID);
            glmDraw(punteroM13, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[33].texID);
            glmDraw(punteroM14, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[10].texID);
            glmDraw(punteroM15, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[33].texID);
            glmDraw(punteroM16, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[12].texID);
            glmDraw(punteroM17, GLM_SMOOTH | GLM_TEXTURE);

            ///SALA

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[13].texID);
            glmDraw(punteroM18, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[14].texID);
            glmDraw(punteroM19, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[15].texID);
            glmDraw(punteroM20, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[16].texID);
            glmDraw(punteroM21, GLM_SMOOTH | GLM_TEXTURE);


            glBindTexture(GL_TEXTURE_2D, treeTextureAr[18].texID);
            glmDraw(punteroM23, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[19].texID);
            glmDraw(punteroM24, GLM_SMOOTH | GLM_TEXTURE);

            ///COCINA

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[20].texID);
            glmDraw(punteroM25, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[21].texID);
            glmDraw(punteroM26, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[22].texID);
            glmDraw(punteroM27, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[23].texID);
            glmDraw(punteroM28, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[24].texID);
            glmDraw(punteroM29, GLM_SMOOTH | GLM_TEXTURE);        //x

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[25].texID);
            glmDraw(punteroM30, GLM_SMOOTH | GLM_TEXTURE);         //x

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[26].texID);
            glmDraw(punteroM31, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[27].texID);
            glmDraw(punteroM32, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[28].texID);
            glmDraw(punteroM33, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[29].texID);
            glmDraw(punteroM34, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[30].texID);
            glmDraw(punteroM35, GLM_SMOOTH | GLM_TEXTURE);         //x

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[31].texID);
            glmDraw(punteroM36, GLM_SMOOTH | GLM_TEXTURE);

            glBindTexture(GL_TEXTURE_2D, treeTextureAr[32].texID);
            glmDraw(punteroM37, GLM_SMOOTH | GLM_TEXTURE);

        glPopMatrix();
    glPopMatrix();
	glutSwapBuffers();
}

void exitMouseDrag( int x, int y )
{
    if( !isInMouseDrag )
        return;
    isInMouseDrag = false;
    glutSetCursor( oldCursorID );
    glutWarpPointer( oldCursorX, oldCursorY );
}

void clampCamera()
{
    if( camPitch > 90.0 )
        camPitch = 90.0;
    else if( camPitch < -90.0 )
        camPitch = -90.0;
    while( camYaw < 0.0 )
        camYaw += 360.0;
    while( camYaw >= 360.0 )
        camYaw -= 360.0;
}

void dollyCamera( GLfloat dollyBy, GLfloat dollyAngle )
{
    GLfloat actualAngleInRadians;
    actualAngleInRadians = ( ( camYaw + dollyAngle ) * M_PI / 180.0 );
    camX -= sin( actualAngleInRadians ) * dollyBy * DEF_dollyStepSize;
    camZ -= cos( actualAngleInRadians ) * dollyBy * DEF_dollyStepSize;
    cout << camX << "   ";
    cout << camZ << endl;
}

void teclado(unsigned char key, int x, int y)
{
	switch (key)
	{
	    /// Movimiento hacia adelante
        case 'w':
        case 'W':
            dollyCamera( DEF_dollyStepSize, 0.0 );
            break;

        /// Movimiento hacia atras
        case 's':
        case 'S':
            dollyCamera( DEF_dollyStepSize, 180.0 );
            break;

        /// Strafe hacia la izquierda
        case 'a':
        case 'A':
            dollyCamera( DEF_dollyStepSize, 90.0 );
            break;

        /// Strafe derecha
        case 'd':
        case 'D':
            dollyCamera( DEF_dollyStepSize, 270.0 );
            break;


        /// Toggle 'inverted' mouse.
        case 'i':
        case 'I':
            mouseIsInverted = !mouseIsInverted;
            break;

        case 'T':
        case 't':   if(anguloPuerta==0)
                    {
                        anguloPuerta = anguloPuerta + 110;
                    }
                    else
                    {
                        if(anguloPuerta==110)
                        {
                          anguloPuerta = anguloPuerta - 110;
                        }
                    }
                    break;

        case 'f':   if((camX >= -0.245 && camX <= 0.595549) && (camZ >= -0.0394939 && camZ <= 1.88605))
                        PlaySound(TEXT("AUDIOS/MUEBLES.wav"),NULL,SND_ASYNC);
                    if((camX >= 1.34261 && camX <= 2.0) && (camZ >= 0.162931 && camZ <= 1.12395))
                        PlaySound(TEXT("AUDIOS/TV.wav"),NULL,SND_ASYNC);
                    if((camX >= 0.6 && camX <= 1.255) && (camZ >= 1.7825 && camZ <= 2.2622))
                        PlaySound(TEXT("AUDIOS/SILLON.wav"),NULL,SND_ASYNC);
                    if((camX >= 1.19283 && camX <= 1.8331) && (camZ >= -0.32168 && camZ <= 0.157934))
                        PlaySound(TEXT("AUDIOS/CUADROS.wav"),NULL,SND_ASYNC);
                    if((camX >= -2.6113 && camX <= -2.15255) && (camZ >= 1.37197 && camZ <= 1.69135))
                        PlaySound(TEXT("AUDIOS/TOALLA.wav"),NULL,SND_ASYNC);
                    if((camX >= -2.91926 && camX <= -1.85) && (camZ >= -0.5 && camZ <= -0.0925))
                        PlaySound(TEXT("AUDIOS/CAMA.wav"),NULL,SND_ASYNC);
                    if((camX >= -2.55 && camX <= -2.0) && (camZ >= 0.5 && camZ <= 0.9))
                        PlaySound(TEXT("AUDIOS/ARMARIO.wav"),NULL,SND_ASYNC);
                    if((camX >= -1.65156 && camX <= -1.33156) && (camZ >= -1.20415 && camZ <= -0.565745))
                        PlaySound(TEXT("AUDIOS/MANZANA.wav"),NULL,SND_ASYNC);
                    if((camX >= -0.75 && camX <= -0.45) && (camZ >= -0.5 && camZ <= -0.385))
                        PlaySound(TEXT("AUDIOS/NARANJA.wav"),NULL,SND_ASYNC);
                    if((camX >= 0.1085 && camX <= 0.272789) && (camZ >= -1.00995 && camZ <= -0.692489))
                        PlaySound(TEXT("AUDIOS/UVA.wav"),NULL,SND_ASYNC);
                    if((camX >= 1.24695 && camX <= 1.56085) && (camZ >= -2.11435 && camZ <= -1.62995))
                        PlaySound(TEXT("AUDIOS/COCINA.wav"),NULL,SND_ASYNC);
                    if((camX >= 0.891221 && camX <= 1.6) && (camZ >= -1.13065 && camZ <= -0.51712))
                        PlaySound(TEXT("AUDIOS/REFRI.wav"),NULL,SND_ASYNC);
                    if((camX >= 1.24 && camX <= 1.55) && (camZ >= -1.4 && camZ <= -0.9895))
                        PlaySound(TEXT("AUDIOS/PLATO.wav"),NULL,SND_ASYNC);
                    break;
	}
	glutPostRedisplay();
}

void specialFunc( int key, int x, int y )
{
	switch( key )
	{
        //giro  a la izquierda
        case GLUT_KEY_LEFT:
            camYaw += 1.0;
            clampCamera();
            break;

        // giro a la derecha.
        case GLUT_KEY_RIGHT:
            camYaw -= 1.0;
            clampCamera();
            break;

        // mirar hacia arriba.
        case GLUT_KEY_UP:
            camPitch += 1.0;
            clampCamera();
            break;

        // mirar hacia abajo
        case GLUT_KEY_DOWN:
            camPitch -= 1.0;
            clampCamera();
            break;
	}
}

void mouseFunc( int button, int state, int x, int y )
{
    if( button == GLUT_LEFT_BUTTON && state == GLUT_DOWN )
	{
        if( !isInMouseDrag )
            enterMouseDrag( x, y );
        else
            exitMouseDrag( x, y );
	}
}

void allMotionFunc( int x, int y )
{
    int deltaX, deltaY;

    if( !isInMouseDrag )
        return;
    deltaX = x - viewPortCenterX;
    deltaY = y - viewPortCenterY;
    if( deltaX == 0 && deltaY == 0 )
        return;
    glutWarpPointer( viewPortCenterX, viewPortCenterY );
    camYaw -= DEF_angleSensitivity * deltaX;
    camPitch -= DEF_angleSensitivity * deltaY * ( mouseIsInverted ? 1.0 : 1.0 );
    clampCamera();
    glutPostRedisplay();
}

void redimensionar(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(67.5,(GLfloat)w/(GLfloat)h,0.01,1000.0);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(900, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Bienvenido a mi casita");
	init();

	punteroM1 = glmReadOBJ("modelos/tierra.obj");
	punteroM2 = glmReadOBJ("modelos/cielo.obj");
	punteroM3 = glmReadOBJ("modelos/arboles.obj");
	punteroM4 = glmReadOBJ("modelos/casaP.obj");
	punteroM5 = glmReadOBJ("modelos/calabazas.obj");
	punteroM6 = glmReadOBJ("modelos/paredes.obj");
	punteroM7 = glmReadOBJ("modelos/puerta.obj");
	punteroM8 = glmReadOBJ("modelos/piso.obj");
	punteroM9 = glmReadOBJ("modelos/dormitorio/cama.obj");
	punteroM10 = glmReadOBJ("modelos/dormitorio/mesita.obj");
	punteroM11 = glmReadOBJ("modelos/dormitorio/armario.obj");
	punteroM12 = glmReadOBJ("modelos/dormitorio/osito.obj");
	punteroM13 = glmReadOBJ("modelos/bano/lavamanos.obj");
	punteroM14 = glmReadOBJ("modelos/bano/water.obj");
	punteroM15 = glmReadOBJ("modelos/bano/toalla.obj");
	punteroM16 = glmReadOBJ("modelos/bano/banera.obj");
	punteroM17 = glmReadOBJ("modelos/bano/ph.obj");
	punteroM18 = glmReadOBJ("modelos/sala/calendario.obj");
	punteroM19 = glmReadOBJ("modelos/sala/librero.obj");
	punteroM20 = glmReadOBJ("modelos/sala/mesatv.obj");
	punteroM21 = glmReadOBJ("modelos/sala/mueble.obj");
	punteroM23 = glmReadOBJ("modelos/sala/sillon.obj");
	punteroM24 = glmReadOBJ("modelos/sala/tv.obj");
	punteroM25 = glmReadOBJ("modelos/cocina/cocina.obj");
	punteroM26 = glmReadOBJ("modelos/cocina/durazno.obj");
	punteroM27 = glmReadOBJ("modelos/cocina/fresa.obj");
	punteroM28 = glmReadOBJ("modelos/cocina/frigider.obj");
	punteroM29 = glmReadOBJ("modelos/cocina/lavador.obj");
	punteroM30 = glmReadOBJ("modelos/cocina/manzana.obj");
	punteroM31 = glmReadOBJ("modelos/cocina/mesa.obj");
	punteroM32 = glmReadOBJ("modelos/cocina/naranja.obj");
	punteroM33 = glmReadOBJ("modelos/cocina/olla.obj");
	punteroM34 = glmReadOBJ("modelos/cocina/pera.obj");
	punteroM35 = glmReadOBJ("modelos/cocina/platano.obj");
	punteroM36 = glmReadOBJ("modelos/cocina/plato.obj");
	punteroM37 = glmReadOBJ("modelos/cocina/uvas.obj");
	punteroM38 = glmReadOBJ("modelos/puertaCasa.obj");

	glutDisplayFunc(graficar);
	glutKeyboardFunc(teclado);
    glutSpecialFunc(specialFunc );
    glutMouseFunc(mouseFunc);
    glutMotionFunc(allMotionFunc);
    glutPassiveMotionFunc(allMotionFunc);
	glutReshapeFunc(redimensionar);
	glutMainLoop();
	return 0;
}

