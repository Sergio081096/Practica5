//Semestre 2018 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Cano Olguin Luis Sergio	    		******//
//*************		Visual Studio 2012					******//
//************************************************************//
#include "Main.h"

float transZ = -5.0f;
float transX = 0.0f;
float angleX = 0.0f;
float angleY = 0.0f;
int screenW = 0.0;
int screenH = 0.0;
float angHombro=0.0f;
float angCodo=0.0f;
float angMano=0.0f;
float angPulgar1=0.0f;
float angPulgar2=0.0f;
float angDedo21=0.0f;
float angDedo22=0.0f;
float angDedo23=0.0f;
float angDedo31=0.0f;
float angDedo32=0.0f;
float angDedo33=0.0f;
float angDedo41=0.0f;
float angDedo42=0.0f;
float angDedo43=0.0f;
float angDedo51=0.0f;
float angDedo52=0.0f;
float angDedo53=0.0f;



GLfloat Position[]= { 0.0f, 3.0f, 0.0f, 1.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

void InitGL ( void )     // Inicializamos parametros
{

	glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing

	//Configuracion luz
	glLightfv(GL_LIGHT0, GL_POSITION, Position);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, Position2);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glEnable ( GL_COLOR_MATERIAL );
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(void)
{
	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

		glBegin(GL_POLYGON);	//Front
			glNormal3f( 0.0f, 0.0f, 1.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glNormal3f( 1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glNormal3f( 0.0f, 0.0f, -1.0f);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glNormal3f( -1.0f, 0.0f, 0.0f);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glNormal3f( 0.0f, -1.0f, 0.0f);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glNormal3f( 0.0f, 1.0f, 0.0f);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTranslatef(transX, 0.0f, transZ);
	glRotatef(angleY, 0.0, 1.0, 0.0);
	glRotatef(angleX, 1.0, 0.0, 0.0);
	//Poner Código Aquí.
	//cabeza
		glPushMatrix();	
		glTranslatef(0.0,-0.5,0.0);
			glColor3f(1.0,1.0,0.2);
			prisma();//0,0
		glPopMatrix();	
		//torso
		glPushMatrix();	
			glColor3f(1.0,1.0,1.0);
			glTranslatef(0.0,-2.5,0.0);
			glScalef(3.0,3.0,1.0);
			prisma();
		glPopMatrix();
		//manos
		glPushMatrix();	
			glColor3f(0.0,0.0,1.0);
			glTranslatef(3.0,-1.5,0.0);
			glScalef(-3.0,-1.0,1.0);
			//prisma();
		glPopMatrix();	
		glPushMatrix();	
			glColor3f(0.0,0.0,1.0);
			glTranslatef(-3.0,-1.5,0.0);
			glScalef(3.0,1.0,1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();	
		glColor3f(0.0,1.0,1.0);
			glTranslatef(-3.0,-1.5,0.0);
			glScalef(3.0,1.0,1.0);
			prisma();
		glPopMatrix();
		//piernas
		glPushMatrix();	
			glColor3f(0.0,1.0,1.0);
			glTranslatef(-1.0,-7.5,0.0);
			glScalef(1.0,7.0,1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();	
			glColor3f(0.0,1.0,1.0);
			glTranslatef(1.0,-7.5,0.0);
			glScalef(1.0,7.0,1.0);
			prisma();
		glPopMatrix();
		//mano
		glPushMatrix();	
			glColor3f(0.0,1.0,1.0);
			glTranslatef(5.5,-1.5,0.0);
			glScalef(2.0,2.0,1.0);
			//prisma();
		glPopMatrix();
		glPushMatrix();	
			glColor3f(0.0,1.0,1.0);
			glTranslatef(-5.5,-1.5,0.0);
			glScalef(2.0,2.0,1.0);
			prisma();
		glPopMatrix();
		//pies
		glPushMatrix();	
			glColor3f(0.0,1.0,1.0);
			glTranslatef(2.0,-12.5,0.0);
			glScalef(3.0,3.0,1.0);
			prisma();
		glPopMatrix();
		glPushMatrix();	
			glColor3f(0.0,1.0,1.0);
			glTranslatef(-2.0,-12.5,0.0);
			glScalef(3.0,3.0,1.0);
			prisma();
		glPopMatrix();
	//brazo detallado
		glTranslatef(1.85,-1.5,0.0);
	glPushMatrix();
	//rotar hombro
	//glTranslatef(3.0,-1.5,0.0);
	if((angHombro>=-20.0)&&(angHombro<=180.0))
		glRotatef(angHombro,0.0,0.0,1.0);//Tt--Yy
	else if(angHombro<-20.0)
		{
		glRotatef(-20.0,0.0,0.0,1.0);
		angHombro=-20.0;
		}
	else if(angHombro>180.0)
		{
		glRotatef(180.0,0.0,0.0,1.0);
		angHombro=180.0;
		}
	//glRotatef(angHombro,0.0,0.0,1.0);//Tt--Yy
	//hombro
		glPushMatrix();
			glColor3f(0.0,1.0,0.0);
			glScalef(0.5,0.5,0.5);
			prisma();
		glPopMatrix();
		//bisep
		glTranslatef(0.0,-0.75,0.0);
		glPushMatrix();
			glColor3f(1.0,0.0,0.0);			
			glScalef(0.5,1.0,0.45);
			prisma();
		glPopMatrix();
		//codo
		//rotar codo
		glTranslatef(0.0,-0.75,0.0);
		if((angCodo>=0.0)&&(angCodo<=120.0))
			glRotatef(angCodo,0.0,0.0,1.0);//Uu--Ii
		else if(angCodo<0.0)
			{
			glRotatef(0.0,0.0,0.0,1.0);//Uu--Ii
			angCodo=0.0;
			}
		else if(angCodo>120.0)
			{
			glRotatef(120.0,0.0,0.0,1.0);//Uu--Ii
			angCodo=120.0;
			}
		//glRotatef(angCodo,0.0,0.0,1.0);//Uu--Ii
		glPushMatrix();
			glColor3f(0.0,1.0,0.0);
			glScalef(0.5,0.5,0.5);
			prisma();
		glPopMatrix();
		//ante-brazo
		glTranslatef(0.0,-0.75,0.0);
		glPushMatrix();
			glColor3f(1.0,0.0,0.0);
			glScalef(0.5,1.0,0.4);
			prisma();
		glPopMatrix();
		//mano
		glTranslatef(0.0,-0.375,0.0);
		//rotar mano
		if((angMano>=-50.0)&&(angMano<=10.0))
			glRotatef(angMano,1.0,0.0,0.0);//Oo--Pp
		else if(angMano<-50.0)
			{
			glRotatef(-50.0,1.0,0.0,0.0);//Oo--Pp
			angMano=-50.0;
			}
		else if(angMano>10.0)
			{
			glRotatef(10.0,1.0,0.0,0.0);//Oo--Pp
			angMano=10.0;
			}
		//glRotatef(angMano,0.0,0.0,1.0);//Oo--Pp
		glTranslatef(0.0,-0.375,0.0);
		glPushMatrix();
			glColor3f(0.0,0.0,1.0);
			glScalef(0.5,0.5,0.2);
			prisma();
		glPopMatrix();
		//dedo--pulgar		
		glPushMatrix();
			glTranslatef(0.25,0.0,0.0);
			if((angPulgar1>=-50.0)&&(angPulgar1<=0.0))
				glRotatef(angPulgar1,0.0,1.0,0.0);//L--l
			else if(angPulgar1<-50.0)
				{
				glRotatef(-50.0,0.0,1.0,0.0);//L--l
				angPulgar1=-50.0;
				}
			else if(angPulgar1>0.0)
				{
				glRotatef(0.0,0.0,1.0,0.0);//L--l
				angPulgar1=0.0;
				}
			//glRotatef(angPulgar1,0.0,1.0,0.0);//L--l
			glTranslatef(0.1,0.1,0.0);			
			//p1
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);
				glScalef(0.2,0.1,0.1);
				prisma();
			glPopMatrix();
			//p2
			glTranslatef(0.1,0.0,0.0);
			if((angPulgar2>=-70.0)&&(angPulgar2<=0.0))
				glRotatef(angPulgar2,0.0,1.0,0.0);//M--m
			else if(angPulgar2<-70.0)
				{
				glRotatef(-70.0,0.0,1.0,0.0);//M--m
				angPulgar2=-70.0;
				}
			else if(angPulgar2>0.0)
				{
				glRotatef(0.0,0.0,1.0,0.0);//M--m
				angPulgar2=0.0;
				}
			//glRotatef(angPulgar2,0.0,1.0,0.0);//M--m
			glTranslatef(0.1,0.0,0.0);
			glPushMatrix();
				glColor3f(1.0,0.0,0.0);
				glScalef(0.2,0.1,0.1);
				prisma();
			glPopMatrix();
		glPopMatrix();
		//dedo2
		glPushMatrix();		
			glTranslatef(0.25,-0.175,0.0);
			if((angDedo21>=-60.0)&&(angDedo21<=0.0))
				glRotatef(angDedo21,1.0,0.0,0.0);//N--n
			else if(angDedo21<-60.0)
				{
				angDedo21=-60.0;
				glRotatef(angDedo21,1.0,0.0,0.0);//N--n
				}
			else if(angDedo21>0.0)
				{
				angDedo21=0.0;
				glRotatef(angDedo21,1.0,0.0,0.0);//N--n
				}
			//glRotatef(angDedo21,1.0,0.0,0.0);//N--n
			glTranslatef(0.0,-0.175,0.0);
			glPushMatrix();
				glColor3f(1.0,0.0,0.1);
				glScalef(0.1,0.2,0.1);
				prisma();
			glPopMatrix();
			//2
			glTranslatef(0.0,-0.1,0.0);
			if((angDedo22>=-90.0)&&(angDedo22<=0.0))
				glRotatef(angDedo22,1.0,0.0,0.0);//B--b
			else if(angDedo22<-90.0)
				{
				angDedo22=-90.0;
				glRotatef(angDedo22,1.0,0.0,0.0);//B--b
				}
			else if(angDedo22>0.0)
				{
				angDedo22=0.0;
				glRotatef(angDedo22,1.0,0.0,0.0);//B--b
				}
			//glRotatef(angDedo22,1.0,0.0,0.0);//B--b
			glTranslatef(0.0,-0.1,0.0);
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);
				glScalef(0.1,0.2,0.1);
				prisma();
			glPopMatrix();
			//3
			glTranslatef(0.0,-0.1,0.0);
			if((angDedo23>=-85.0)&&(angDedo23<=0.0))
				glRotatef(angDedo23,1.0,0.0,0.0);//V--v
			else if(angDedo23<-85.0)
				{
				angDedo23=-85.0;
				glRotatef(angDedo23,1.0,0.0,0.0);//V--v
				}
			else if(angDedo23>0.0)
				{
				angDedo23=0.0;
				glRotatef(angDedo23,1.0,0.0,0.0);//V--v
				}
			//glRotatef(angDedo23,1.0,0.0,0.0);//V--v
			glTranslatef(0.0,-0.1,0.0);
			glPushMatrix();
				glColor3f(0.0,0.0,1.0);
				glScalef(0.1,0.2,0.1);
				prisma();
			glPopMatrix();			
		glPopMatrix();
		//dedo3
		glPushMatrix();		
			glTranslatef(0.1,-0.2,0.0);
			if((angDedo31>=-85.0)&&(angDedo31<=0.0))
				glRotatef(angDedo31,1.0,0.0,0.0);//C--c
			else if(angDedo31<-85.0)
				{
				angDedo31=-85.0;
				glRotatef(angDedo31,1.0,0.0,0.0);//C--c
				}
			else if(angDedo31>0.0)
				{
				angDedo31=0.0;
				glRotatef(angDedo31,1.0,0.0,0.0);//C--c
				}
			//glRotatef(angDedo31,1.0,0.0,0.0);//C--c
			glTranslatef(0.0,-0.2,0.0);
			glPushMatrix();			
				glColor3f(1.0,0.0,0.1);
				glScalef(0.1,0.3,0.1);
				prisma();
			glPopMatrix();
			//2
			glTranslatef(0.0,-0.15,0.0);
			if((angDedo32>=-90.0)&&(angDedo32<=0.0))
				glRotatef(angDedo32,1.0,0.0,0.0);//X--x
			else if(angDedo32<-90.0)
				{
				angDedo32=-90.0;
				glRotatef(angDedo32,1.0,0.0,0.0);//X--x
				}
			else if(angDedo32>0.0)
				{
				angDedo32=0.0;
				glRotatef(angDedo32,1.0,0.0,0.0);//X--x
				}
			//glRotatef(angDedo32,1.0,0.0,0.0);//X--x
			glTranslatef(0.0,-0.15,0.0);
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);
				glScalef(0.1,0.3,0.1);
				prisma();
			glPopMatrix();
			//3
			glTranslatef(0.0,-0.15,0.0);
			if((angDedo33>=-85.0)&&(angDedo33<=0.0))
				glRotatef(angDedo33,1.0,0.0,0.0);//Z--z
			else if(angDedo33<-85.0)
				{
				angDedo33=-85.0;
				glRotatef(angDedo33,1.0,0.0,0.0);//Z--z
				}
			else if(angDedo33>0.0)
				{
				angDedo33=0.0;
				glRotatef(angDedo33,1.0,0.0,0.0);//Z--z
				}
			//glRotatef(angDedo33,1.0,0.0,0.0);//Z--z
			glTranslatef(0.0,-0.15,0.0);
			glPushMatrix();
				glColor3f(0.0,0.0,1.0);
				glScalef(0.1,0.3,0.1);
				prisma();
			glPopMatrix();			
		glPopMatrix();
		//dedo4
		glPushMatrix();		
			glTranslatef(-0.05,-0.175,0.0);
			if((angDedo41>=-85.0)&&(angDedo41<=0.0))
				glRotatef(angDedo41,1.0,0.0,0.0);//J--j
			else if(angDedo41<-85.0)
				{
				angDedo41=-85.0;
				glRotatef(angDedo41,1.0,0.0,0.0);//J--j
				}
			else if(angDedo41>0.0)
				{
				angDedo41=0.0;
				glRotatef(angDedo41,1.0,0.0,0.0);//J--j
				}
			//glRotatef(angDedo41,1.0,0.0,0.0);//J--j
			glTranslatef(0.0,-0.175,0.0);
			glPushMatrix();
				glColor3f(1.0,0.0,0.1);
				glScalef(0.1,0.2,0.1);
				prisma();
			glPopMatrix();
			//2
			glTranslatef(0.0,-0.1,0.0);
			if((angDedo42>=-90.0)&&(angDedo42<=0.0))
				glRotatef(angDedo42,1.0,0.0,0.0);//H--h
			else if(angDedo42<-90.0)
				{
				angDedo42=-90.0;
				glRotatef(angDedo42,1.0,0.0,0.0);//H--h
				}
			else if(angDedo42>0.0)
				{
				angDedo42=0.0;
				glRotatef(angDedo42,1.0,0.0,0.0);//H--h
				}
			//glRotatef(angDedo42,1.0,0.0,0.0);//H--h
			glTranslatef(0.0,-0.1,0.0);
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);
				glScalef(0.1,0.2,0.1);
				prisma();
			glPopMatrix();
			//3
			glTranslatef(0.0,-0.1,0.0);
			if((angDedo43>=-85.0)&&(angDedo43<=0.0))
				glRotatef(angDedo43,1.0,0.0,0.0);//G--g
			else if(angDedo43<-85.0)
				{
				angDedo43=-85.0;
				glRotatef(angDedo43,1.0,0.0,0.0);//G--g
				}
			else if(angDedo43>0.0)
				{
				angDedo43=0.0;
				glRotatef(angDedo43,1.0,0.0,0.0);//G--g
				}
			//glRotatef(angDedo43,1.0,0.0,0.0);//G--g
			glTranslatef(0.0,-0.1,0.0);
			glPushMatrix();
				glColor3f(0.0,0.0,1.0);
				glScalef(0.1,0.2,0.1);
				prisma();
			glPopMatrix();
		glPopMatrix();
		//dedo5
		glPushMatrix();		
			glTranslatef(-0.2,-0.15,0.0);
			if((angDedo51>=-85.0)&&(angDedo51<=0.0))
				glRotatef(angDedo51,1.0,0.0,0.0);///F--f
			else if(angDedo51<-85.0)
				{
				angDedo51=-85.0;
				glRotatef(angDedo51,1.0,0.0,0.0);///F--f
				}
			else if(angDedo51>0.0)
				{
				angDedo51=0.0;
				glRotatef(angDedo51,1.0,0.0,0.0);///F--f
				}
			//glRotatef(angDedo51,1.0,0.0,0.0);///F--f
			glTranslatef(0.0,-0.15,0.0);
			glPushMatrix();
				glColor3f(1.0,0.0,0.1);
				glScalef(0.1,0.15,0.1);
				prisma();
			glPopMatrix();
			//2
			glTranslatef(0.0,-0.075,0.0);
			if((angDedo52>=-90.0)&&(angDedo52<=0.0))
				glRotatef(angDedo52,1.0,0.0,0.0);///K--k
			else if(angDedo52<-90.0)
				{
				angDedo52=-90.0;
				glRotatef(angDedo52,1.0,0.0,0.0);///K--k
				}
			else if(angDedo52>0.0)
				{
				angDedo52=0.0;
				glRotatef(angDedo52,1.0,0.0,0.0);///K--k
				}
			//glRotatef(angDedo52,1.0,0.0,0.0);///K--k
			glTranslatef(0.0,-0.075,0.0);
			glPushMatrix();
				glColor3f(0.0,1.0,0.0);
				glScalef(0.1,0.15,0.1);
				prisma();
			glPopMatrix();
			//3
			glTranslatef(0.0,-0.075,0.0);
			if((angDedo53>=-85.0)&&(angDedo53<=0.0))
				glRotatef(angDedo53,1.0,0.0,0.0);///E--e
			else if(angDedo53<-85.0)
				{
				angDedo53=-85.0;
				glRotatef(angDedo53,1.0,0.0,0.0);///E--e
				}
			else if(angDedo53>0.0)
				{
				angDedo53=0.0;
				glRotatef(angDedo53,1.0,0.0,0.0);///E--e
				}
			//glRotatef(angDedo53,1.0,0.0,0.0);///E--e
			glTranslatef(0.0,-0.075,0.0);
			glPushMatrix();
				glColor3f(0.0,0.0,1.0);
				glScalef(0.1,0.15,0.1);
				prisma();
			glPopMatrix();			
		glPopMatrix();
	glPopMatrix();
	//prisma();
	glPushMatrix();
	glPopMatrix();
	//prisma();

		
  											
	glutSwapBuffers ( );
  // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	//glOrtho(-5,5,-5,5,0.2,20);	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	//glLoadIdentity();									
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'E':
			angDedo53 +=0.7f;
			break;
		case 'e':
			angDedo53 -=0.7f;
			break;
		case 'K':
			angDedo52 +=0.7f;
			break;
		case 'k':
			angDedo52 -=0.7f;
			break;
		case 'F':
			angDedo51 +=0.7f;
			break;
		case 'f':
			angDedo51 -=0.7f;
			break;
		case 'G':
			angDedo43 +=0.7f;
			break;
		case 'g':
			angDedo43 -=0.7f;
			break;
		case 'H':
			angDedo42 +=0.7f;
			break;
		case 'h':
			angDedo42 -=0.7f;
			break;
		case 'J':
			angDedo41 +=0.7f;
			break;
		case 'j':
			angDedo41 -=0.7f;
			break;
		case 'Z':
			angDedo33 +=0.7f;
			break;
		case 'z':
			angDedo33 -=0.7f;
			break;
		case 'X':
			angDedo32 +=0.7f;
			break;
		case 'x':
			angDedo32 -=0.7f;
			break;
		case 'C':
			angDedo31 +=0.7f;
			break;
		case 'c':
			angDedo31 -=0.7f;
			break;
		case 'V':
			angDedo23 +=0.7f;
			break;
		case 'v':
			angDedo23 -=0.7f;
			break;
		case 'B':
			angDedo22 +=0.7f;
			break;
		case 'b':
			angDedo22 -=0.7f;
			break;
		case 'N':
			angDedo21 +=0.7f;
			printf("Posicion en Z: %f\n", angDedo21);
			break;
		case 'n':
			angDedo21 -=0.7f;
			printf("Posicion en Z: %f\n", angDedo21);
			break;
		case 'M':
			angPulgar2 +=0.7f;
			break;
		case 'm':
			angPulgar2 -=0.7f;
			break;		
		case 'L':
			angPulgar1 +=0.5f;
			break;
		case 'l':
			angPulgar1 -=0.5f;
			break;
		case 'o':
		case 'O':
			angMano +=0.5f;
			break;
		case 'p':
		case 'P':
			angMano -=0.5f;
			break;
		case 't':
		case 'T':
			angHombro +=0.5f;
			printf("Posicion en Z: %f\n", angHombro);
			break;
		case 'y':
		case 'Y':
			angHombro -=0.5f;
			printf("Posicion en Z: %f\n", angHombro);
			break;
		case 'i':
		case 'I':
			angCodo +=0.5f;
			break;
		case 'u':
		case 'U':
			angCodo -=0.5f;
			break;
		case 'w':
		case 'W':
			transZ +=0.2f;
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			break;
		case 'a':
		case 'A':
			transX +=0.2f;
			break;
		case 'd':
		case 'D':
			transX -=0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:		// Presionamos tecla ARRIBA...
		angleX +=2.0f;
		break;
    case GLUT_KEY_DOWN:		// Presionamos tecla ABAJO...
		angleX -=2.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY +=2.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -=2.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 5"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}
