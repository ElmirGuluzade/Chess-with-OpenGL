#include<GL/glut.h>
#include<iostream>
#include<cmath>
#include<string>
using namespace std;
int winW = 500;
int winH = 500;
int beginX = -175;
int beginY = -125;
int beginning = -200;
int ferq = -beginning/4;

int arrX[32] = {beginX, 
beginX+50, 
beginX+100, 
beginX+150,
beginX+200,
beginX+250, 
beginX+300,
beginX+350,
beginX,
-beginX,
beginX+50,
-beginX-50,
beginX+100,
-beginX-100,
beginX+150,
beginX+200,
beginX,
beginX+50, 
beginX+100, 
beginX+150,
beginX+200,
beginX+250, 
beginX+300,
beginX+350,
beginX,
-beginX,
beginX+50,
-beginX-50,
beginX+100,
-beginX-100,
beginX+150,
beginX+200,
};
int arrY[32] = {beginY,
beginY,
beginY,
beginY,
beginY,
beginY,
beginY,
beginY,
beginX,
beginX,
beginX,
beginX,
beginX,
beginX,
beginX,
beginX,
-beginY,
-beginY,
-beginY,
-beginY,
-beginY,
-beginY,
-beginY,
-beginY,
-beginX,
-beginX,
-beginX,
-beginX,
-beginX,
-beginX,
-beginX,
-beginX
};

void pawn(int begin,int last, string color){	  
	if(color == "red"){
		glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);
		glVertex2f(begin-10, last+10);
        glVertex2f(begin+10, last+10);
        glVertex2f(begin, last-10);
    	glEnd();
	}
	else{
		glBegin(GL_TRIANGLES);
		glColor3f(0,0,0);
		glVertex2f(begin-10, last-10);
        glVertex2f(begin+10, last-10);
        glVertex2f(begin, last+10);
    	glEnd();
	}
}

void rook(int begin,int last, string color){
	if(color == "red"){
		glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex2f(begin-15, last+15); // top left
		glVertex2f(begin+15, last+15); // top right 
		glVertex2f(begin+15, last-15); // bottom right
		glVertex2f(begin-15, last-15); // bottom left
		glEnd();
	}
	else{
		glBegin(GL_QUADS);
		glColor3f(0,0,0);
		glVertex2f(begin-15, last+15); // top left
		glVertex2f(begin+15, last+15); // top right 
		glVertex2f(begin+15, last-15); // bottom right
		glVertex2f(begin-15, last-15); // bottom left
		glEnd();
	}
}

void knight(int begin,int last, string color){
	if(color == "red"){
	glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);
		glVertex2f(begin-10, last-5); //left
        glVertex2f(begin+10, last+15); //right
        glVertex2f(begin+10, last-15); //bottom
   	glEnd();
   	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex2f(begin-10, last+15); // top left
		glVertex2f(begin+10, last+15); // top right 
		glVertex2f(begin+10, last-5); // bottom right
		glVertex2f(begin-10, last-5); // bottom left
	glEnd();
	}
	else{
	glBegin(GL_TRIANGLES);
		glColor3f(0,0,0);
		glVertex2f(begin-10, last+5); //left
        glVertex2f(begin+10, last-15); //right
        glVertex2f(begin+10, last+15); //bottom
   	glEnd();
   	glBegin(GL_QUADS);
		glColor3f(0,0,0);
		glVertex2f(begin-10, last-15); // top left
		glVertex2f(begin+10, last-15); // top right 
		glVertex2f(begin+10, last+5); // bottom right
		glVertex2f(begin-10, last+5); // bottom left
	glEnd();
	}
}

void bishop(int begin,int last, string color){
	if(color == "red"){
		glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);
		glVertex2f(begin-20, last+15);
        glVertex2f(begin+20, last+15);
        glVertex2f(begin, last-20);
    	glEnd();
	}
	else{
		glBegin(GL_TRIANGLES);
		glColor3f(0,0,0);
		glVertex2f(begin-20, last-15);
        glVertex2f(begin+20, last-15);
        glVertex2f(begin, last+20);
    	glEnd();
	}
}

void queen(int begin,int last, string color){
	if(color == "red"){
	glBegin(GL_TRIANGLES);
		glBegin(GL_TRIANGLES);
		glColor3f(1,0,0);
		glVertex2f(begin-15, last-5); //left
        glVertex2f(begin+15, last-5); //right
        glVertex2f(begin, last-20); //bottom
   	glEnd();
   	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex2f(begin-15, last+17); // top left
		glVertex2f(begin+15, last+17); // top right 
		glVertex2f(begin+15, last-5); // bottom right
		glVertex2f(begin-15, last-5); // bottom left
	glEnd();
	}
	else{
		glBegin(GL_TRIANGLES);
		glColor3f(0,0,0);
		glVertex2f(begin-15, last+5); //left
        glVertex2f(begin+15, last+5); //right
        glVertex2f(begin, last+20); //bottom
   	glEnd();
   	glBegin(GL_QUADS);
		glColor3f(0,0,0);
		glVertex2f(begin-15, last-17); // top left
		glVertex2f(begin+15, last-17); // top right 
		glVertex2f(begin+15, last+5); // bottom right
		glVertex2f(begin-15, last+5); // bottom left
	glEnd();
	}
}


void king(int begin, int last, string color){
	if(color == "red"){
	glBegin(GL_QUADS);
		glColor3f(0,0,0);
		glVertex2f(begin-5, last-15); // top left
		glVertex2f(begin+5, last-15); // top right 
		glVertex2f(begin+5, last); // bottom right
		glVertex2f(begin-5, last); // bottom left
	glEnd();
   	glBegin(GL_QUADS); 
		glColor3f(1,0,0);
		glVertex2f(begin-15, last+20); // top left
		glVertex2f(begin+15, last+20); // top right 
		glVertex2f(begin+15, last-5); // bottom right
		glVertex2f(begin-15, last-5); // bottom left
	glEnd();
	}
	else{
	glBegin(GL_QUADS);
		glColor3f(1,0,0);
		glVertex2f(begin-5, last+15); // top left
		glVertex2f(begin+5, last+15); // top right 
		glVertex2f(begin+5, last); // bottom right
		glVertex2f(begin-5, last); // bottom left
	glEnd();
   	glBegin(GL_QUADS); 
		glColor3f(0,0,0);
		glVertex2f(begin-15, last-20); // top left
		glVertex2f(begin+15, last-20); // top right 
		glVertex2f(begin+15, last+5); // bottom right
		glVertex2f(begin-15, last+5); // bottom left
	glEnd();
	}
}

void blackPieces(){
	pawn(arrX[0],arrY[0], "black");
	pawn(arrX[1],arrY[1], "black");
	pawn(arrX[2],arrY[2], "black");
	pawn(arrX[3],arrY[3], "black");
	pawn(arrX[4],arrY[4], "black");
	pawn(arrX[5],arrY[5], "black");
	pawn(arrX[6],arrY[6], "black");
	pawn(arrX[7],arrY[7], "black");
	rook(arrX[8],arrY[8], "black");
	rook(arrX[9], arrY[9], "black");
	knight(arrX[10],arrY[10], "black");
	knight(arrX[11],arrY[11], "black");
	bishop(arrX[12],arrY[12], "black");
	bishop(arrX[13],arrY[13], "black");
	queen(arrX[14],arrY[14], "black");
	king(arrX[15],arrY[15], "black");
}

void whitePieces(){
	pawn(arrX[16],arrY[16], "red");
	pawn(arrX[17],arrY[17], "red");
	pawn(arrX[18],arrY[18], "red");
	pawn(arrX[19],arrY[19], "red");
	pawn(arrX[20],arrY[20], "red");
	pawn(arrX[21],arrY[21], "red");
	pawn(arrX[22],arrY[22], "red");
	pawn(arrX[23],arrY[23], "red");
	rook(arrX[24],arrY[24], "red");
	rook(arrX[25], arrY[25], "red");
	knight(arrX[26],arrY[26], "red");
	knight(arrX[27],arrY[27], "red");
	bishop(arrX[28],arrY[28], "red");
	bishop(arrX[29],arrY[29], "red");
	queen(arrX[30],arrY[30], "red");
	king(arrX[31],arrY[31], "red");		
}

void content(){
    int X = beginning, Y = beginning, loop = 0, loop2 = 0, sequence = 0;
    while(loop < 8){
        while(loop2 < 8){
            glBegin(GL_POLYGON);
            if(sequence % 2 != 0){
       			glColor3f(1,1,1);
   			}else{
       			glColor3f(0.3,0.15,0);
  		   }
            glVertex2i(X,Y); glVertex2i(X,Y+ferq);
            glVertex2i(X+ferq,Y+ferq); glVertex2i(X+ferq,Y);
            X += ferq;
            glEnd();
            sequence++; loop2++;
        }
        loop++; loop2=0; sequence++;
        Y += ferq; X = beginning;
    }
}

void letters(){
	int letterbegin = -180;
	int letterlast = -220;
  //Bottom
  int x = letterbegin , y = letterlast;
  
  glColor3f(1,1,1);
  
  string s = "ABCDEFGH";
  
  int length = s.length();
  
  for (int i = 0; i < length; i++) {
    glRasterPos2i(x, y);
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);
    x = x + ferq;
  }
  
  //Top
   x = letterbegin , y = 220;
   
  glColor3f(1,1,1);
  
  for (int i = 0; i < length; i++) {
    glRasterPos2i(x, y);
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);
    x = x + ferq;
  }
  
  //Left
  x = letterlast;y = letterbegin;
  
  string num = "12345678";
  
  length = num.length();
  
  for(int i = 0; i < length; i++){
    glRasterPos2i(x, y);
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, num[i]);
    y = y + ferq;      
  }
  //Right
  
   x = -letterlast;y = letterbegin;
   
  for(int i = 0; i < length; i++){
    glRasterPos2i(x, y);
    glutBitmapCharacter(GLUT_BITMAP_8_BY_13, num[i]);
    y = y + ferq;      
  }
  
}
int turn = 0;
int points[100];
int check = 0;
void myMouse(int button,int state, int x, int y){
		if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		x = x - winW/2;
		y = winH/2 - y;
		if(turn % 2 == 1){
			x = -x;
			y = -y;
		}	
		if(check<4){
			points[check] = x;
			check++;
			points[check] = y;
			check++;
		}
		int exp;
		if(check == 4){
			for(int i=0;i<32;i++){
			if(arrX[i]-24 < points[0] && arrX[i] + 24 > points[0] && arrY[i]-25 < points[1] && arrY[i] + 25 > points[1]){
				arrX[i] = points[2];
				arrY[i] = points[3];	
				break;	
			}
		}
			turn++;
			check = 0;
		}		

	    glutPostRedisplay();
		}
}



void display(){
  glClear(GL_COLOR_BUFFER_BIT);
  glPushMatrix();
  if(turn % 2 == 1){
  	glRotatef(180,0,0,0);
  }
    content();
    letters();
    whitePieces();
    blackPieces();
    glPopMatrix();
  glutSwapBuffers();
}
//
void myKey(unsigned char key, int x, int y){
	if(key == 'c'){
		exit(0);
	}
}
int checker = 0;
void reshape(int w,int h){
    glViewport(0,0,w,h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    w = winW;
    h = winH;
    gluOrtho2D(-w/2,w/2,-h/2,h/2);
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_RGB);
  glutInitWindowPosition(0, 0);
  glutInitWindowSize(winW, winH);
  glutCreateWindow("ChessBoard");
  glutReshapeFunc(reshape);
  glutDisplayFunc(display);
  glutMouseFunc(myMouse);
  glutKeyboardFunc(myKey);
  glutMainLoop();
}

