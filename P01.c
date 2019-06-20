#include <stdlib.h>
#include <GL/glut.h> //Windows

void DibujarPantalla(void);

int main(int argc, char** argv)
{
	//CONFIGURACIONES INICIALES
	glutInit(&argc, argv);				//&Paso por referencia 
	glutInitWindowPosition(100,100);	//posicion de la ventana (x,y)
	glutInitWindowSize(200, 200);		//Tamaño de la ventana (width, height)
	glutCreateWindow("HOLA MUNDO CRUEL!");//crear la ventana--El mensaje que aparece en la ventana 

	glClearColor(0,0,1,0); // Definir el color(RGB,),solo sirve con 0 o 1 y con decimales---color de fondo

	//ASIGNACION DE CALLBACKS (FUNCIONES DE SERVICIO A EVENTOS)
 	glutDisplayFunc(&DibujarPantalla);	//Funcion display-Recibe(&referencia a funcion)

 	//ESTADO DE ESPERA DE EVENTOS
 	glutMainLoop(); //Entra en el Bucle de procesamientos de datos
 	return 0;	
}

void DibujarPantalla()
{
	//Funciones OpenGl
	glClear(GL_COLOR_BUFFER_BIT);	//Borra la pantalla(contiene el color que se selecciono)

	glColor3f(0,1,0);//color para el objeto
	glRectf(-1,1,0,0);//Dibuja un rectangulo

	glColor3f(1,1,0);//color para el objeto
	glRectf(-1,1,-0.5,0.5);//Dibuja un rectangulo

	glFlush();//todo lo que aparece en la memoria lo pone en la ventana 
}
