# include "iGraphics.h"
# include "gl.h"
#include<stdio.h>
#include<math.h>
int cx=0,dx,i,sign=1,curve=1,one=1,two=1,three=1,four=1,five=1,help=1,a1=72,a2=102,a3=122,a4=95;
double f1=0.04,f2=0.05,f3=0.03,f4=0.02,phase=0.00,temp;
void iDraw()
{
	iClear();
	//instruction picture
	if(help)
	{
	    iShowBMP( 150, 10, "help.bmp");
	    iSetColor(0, 0, 0);
	    iText(160, 650, "Toggle Help/Main page: F1", GLUT_BITMAP_TIMES_ROMAN_24);
        iText(160, 620, "Toggle curve show/hide: s/S", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 590, "Toggle tracer show/hide: <curve no> such as 1,2,3,4..", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 560, "Pause animation :p/P", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 530, "Resume animation: r/R", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 500, "Increase amplitude: a", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 470, "Decrease amplitude : A", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 440, "Increase frequency:f", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 410, "Decrease frequency: F", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 380, "Increase speed: +", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 350, "Decrease speed: -", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 320, "Phase left shift: Left arrow key(<-)", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 290, "Phase right shift: Right arrow key(->)", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 260, "Increase/ Decrease amplitude : Mouse dragging", GLUT_BITMAP_TIMES_ROMAN_24);
	    iText(160, 230, "Exit: END", GLUT_BITMAP_TIMES_ROMAN_24);
	}
	//Curves
	else
    {
        if(curve)
        {
            //static curves
            for(i=1;i<1350;i=i+1)
            {
                iSetColor(250, 0, 0);
                iPoint(i,350+a1*sin(f1*i+phase),0);
                iSetColor(143, 0, 255);
                iPoint(i,350+a2*sin(f2*i+phase),0);
                iSetColor(0, 255, 0);
                iPoint(i,350+a3*cos(f3*i+phase),0);
                iSetColor(0, 191, 255);
                iPoint(i,350+a4*cos(f4*i+phase),0);
                iSetColor(250, 250, 0);
                iPoint(i,(350+a1*sin(f1*i+phase)+a2*sin(f2*i+phase)+a3*cos(f3*i+phase)+a4*cos(f4*i+phase)),0);
            }
        }
        //ball traces
        if(one)
        {
            iSetColor(255, 0, 0);
            iFilledCircle(cx, 350+a1*sin(f1*cx+phase), 5, 100);
        }
        if(two)
        {
            iSetColor(143, 0, 255);
            iFilledCircle(cx, 350+a2*sin(f2*cx+phase), 5, 100);
        }
        if(three)
        {
            iSetColor(0, 255, 0);
            iFilledCircle(cx, 350+a3*cos(f3*cx+phase), 5, 100);
        }
        if(four)
        {
            iSetColor(0, 191, 255);
            iFilledCircle(cx, 350+a4*cos(f4*cx+phase), 5, 100);
        }
        if(five)
        {
            iSetColor(255, 255, 0);
            iFilledCircle(cx, 350+a1*sin(f1*cx+phase)+a2*sin(f2*cx+phase)+a3*cos(f3*cx+phase)+a4*cos(f4*cx+phase), 5, 100);
        }
        //middle line
        iSetColor(255, 255, 255);
        iLine(0,350,1350, 350);
    }
}
/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    //temp used for amplitude bounding
    if(my-(350+a1*sin(f1*mx+phase))<10 && my-(350+a1*sin(f1*mx+phase))>-10)
    {
        temp=a1;
        if(my>350)
            a1=a1+my-(350+a1*sin(f1*mx+phase));
        else
            a1=a1-my+(350+a1*sin(f1*mx+phase));
        if(a1<0 || a1>350)
            a1=temp;
    }
    else if(my-(350+a2*sin(f2*mx+phase))<10 && my-(350+a2*sin(f2*mx+phase))>-10)
    {
        temp=a2;
        if(my>350)
             a2=a2+my-(350+a2*sin(f2*mx+phase));
        else
             a2=a2-my+(350+a2*sin(f2*mx+phase));
        if(a2<0 || a2>350)
            a2=temp;
    }
    else if(my-(350+a3*cos(f3*mx+phase))<10 && my-(350+a3*cos(f3*mx+phase))>-10)
    {
        temp=a3;
        if(my>350)
            a3=a3+my-(350+a3*cos(f3*mx+phase));
        else
            a3=a3-my+(350+a3*cos(f3*mx+phase));
        if(a3<0 || a3>350)
            a3=temp;
    }
    else if(my-(350+a4*cos(f4*mx+phase))<10 && my-(350+a4*cos(f4*mx+phase))>-10)
    {
        temp=a4;
        if(my>350)
            a4=a4+my-(350+a4*cos(f4*mx+phase));
        else
            a4=a4-my+(350+a4*cos(f4*mx+phase));
        if(a4<0 || a4>350)
            a4=temp;
    }
}
/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
    }
}
/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p'||key == 'P')
	{
		iPauseTimer(0);
	}
	if(key == 'r'||key == 'R')
	{
		iResumeTimer(0);
	}
	if(key == 'f')
	{
	    if(f1<0.15)
            f1=f1+0.001;
        if(f2<0.15)
            f2=f2+0.001;
        if(f3<0.15)
            f3=f3+0.001;
        if(f4<0.15)
            f4=f4+0.001;
	}
	if(key == 'F')
	{
	    if(f1>0)
            f1=f1-0.001;
        if(f2>0)
            f2=f2-0.001;
		if(f3>0)
            f3=f3-0.001;
		if(f4>0)
            f4=f4-0.001;
	}
	if(key == 'a')
	{
		if(a1<=350)
            a1=a1+3;
		if(a2<=350)
            a2=a2+3;
		if(a3<=350)
            a3=a3+3;
		if(a4<=350)
            a4=a4+3;
	}
	if(key == 'A')
	{
		if(a1>0)
            a1=a1-3;
		if(a2>0)
            a2=a2-3;
		if(a3>0)
            a3=a3-3;
		if(a4>0)
            a4=a4-3;
	}
	//sign used to define direction
	if(key == '+')
    {
        if(sign==1)
            dx++;
        else if(sign==0)
            dx--;
    }
    if(key == '-'&&dx)
    {
        if(sign==1)
            dx--;
        else if(sign==0)
            dx++;
    }
    if(key == 's'||key == 'S')
    {
        if(curve)
            curve=0;
        else
            curve=1;
    }
    if(key == '1')
    {
        if(one)
            one=0;
        else
            one=1;
    }
    if(key == '2')
    {
        if(two)
            two=0;
        else
            two=1;
    }
    if(key == '3')
    {
        if(three)
            three=0;
        else
            three=1;
    }
    if(key == '4')
    {
        if(four)
            four=0;
        else
            four=1;
    }
    if(key == '5')
    {
        if(five)
            five=0;
        else
            five=1;
    }
}
/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{
	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_F1)
    {
        if(help)
            help=0;
        else
            help=1;
    }
    if(key == GLUT_KEY_LEFT)
    {
        phase=phase+0.3;
    }
    if(key == GLUT_KEY_RIGHT)
    {
        phase=phase-0.3;
    }
}
void ballChange()
{
    cx += dx;
	if(cx > 1350)
    {
        dx = -dx;
        sign=0;
    }
    if(cx<0)
    {
         dx=-dx;
         sign=1;
    }
}
int main()
{
	iSetTimer(5, ballChange);
	dx = 5;
	iInitialize(1350,700, "Curve");
	return 0;
}


