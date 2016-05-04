#include "Draw.h"

void Draw::Square(float x, float y, float width, float height)
{
	glBegin(GL_TRIANGLES);
	glVertex2f(x, y);
	glVertex2f(x + width, y);
	glVertex2f(x + width, y + height);

	glVertex2f(x + width, y + height);
	glVertex2f(x, y + height);
	glVertex2f(x, y);
	glEnd();
}

void Draw::Text(float x, float y, std::string text)
{
	glColor3f(0, 0, 1);
	glRasterPos2f(x,y);
	for (int i = 0; i < text.length() ; i++)
	{
		if(text[i] == '.')
		{
			break;
		}
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,text[i]);
	}
}

void Draw::Hex(float x, float y, float scale)
{
	glBegin(GL_POLYGON);
	glEnd();


	//glVertex3f(x, y + (scale / 2), 0.0);
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + (scale / 3), y, 0.0);
	//
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + (scale / 3), y, 0.0);
	//glVertex3f(x + 2 * (scale / 3), y, 0.0);
	//
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + 2 * (scale / 3), y, 0.0);
	//glVertex3f(x + scale, y + (scale / 2), 0.0);
	//
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + scale, y + (scale / 2), 0.0);
	//glVertex3f(x + 2 * (scale / 3), y + (scale), 0.0);
	//
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x + 2 * (scale / 3), y + (scale), 0.0);
	//glVertex3f(x + 1 * (scale / 3), y + (scale), 0.0);
	//
	//glVertex3f(x + 1 * (scale / 3), y + (scale), 0.0);
	//glVertex3f(x + (scale / 2), y + (scale / 2), 0.0);
	//glVertex3f(x, y + (scale / 2), 0.0);
}