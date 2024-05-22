 #include "iGraphics.h"
#include <string.h>
#include <stdbool.h>
#include<ctype.h>

int level2 = 0; // if it is set to one level 2 will display
char str[300], str2[300], encrypt[300]; // for storing the input
int len = 0;
int mode = 1; // level 2 round 1 is mode 1 
int levels=1 ;// all level page

// Function prototypes
void alllevels();// alllevels
void alllevelsmouse (int button,int state,int mx,int my);
 
void game2(); // declaring for whole game 2
void game2keyboard(unsigned char key); // controlling keyboard
void cipher(char *text, int key); // encrpyting declaration
void game2imouse(int button,int state,int mx,int my);// controlling mouse event for level 2


void iDraw()
{   
    if(levels ==1)
    {
       alllevels();
    }

    if (level2 == 1)
    {
        game2(); // call 
        
    }
}

void iMouseMove(int mx, int my)
{
}

void iMouse(int button, int state, int mx, int my)
{   
          if(levels==1)
          {
            alllevelsmouse(button,state,mx,my);
          }
         if(level2==1)
          {
            game2imouse(button,state,mx,my);
          }

}

  


void iKeyboard(unsigned char key)
{
    if (level2 == 1)
    {
        game2keyboard(key);
    }
}

void iSpecialKeyboard(unsigned char key)
{
}

void cipher(char *text, int key) // encrypting the text
{
    int i;
    for (i = 0; text[i] != '\0'; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            encrypt[i] = 'a' + (text[i] - 'a' + key) % 26;
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            encrypt[i] = 'A' + (text[i] - 'A' + key) % 26;
        }
    }
}
void alllevels()
{
    iShowBMP2(0,0,"all levels.bmp",0);
}

void game2()
{
    if (mode == 1)  // The beginning screen will appear
    {
        iShowBMP2(0, 0, "round 2 images\\level2-1.bmp", 0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 1",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92, 64, 51);
        iText(500, 275, str, GLUT_BITMAP_TIMES_ROMAN_24); // the user input show in brown color
    }
    else if (mode == 2)
    {
        iSetColor(255, 255, 255); // activate for showing encrpt message for round 1
        iText(480, 220, encrypt, GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,180,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=3; // update to go to next page
        
        
    }
    else if (mode == -1) // wrong answer game over show
    {
        iShowBMP2(0, 0, "round 2 images\\game over.bmp", 0);
    }
    else if(mode==4) //round 2 begin and showing user input
    {
        iShowBMP2(0,0,"round 2 images\\level2-2.bmp",0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 2",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92,64,51);
        iText(500,275,str,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(mode==5) //round 2 encrypt text
    {
        iSetColor(255,255,255);
        iText(480,220,encrypt,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,180,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=6;

    }
    else if(mode==7)// round 3 begin answer && user input
    {
        iShowBMP2(0,0,"round 2 images\\level2-3.bmp",0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 3",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92,64,51);
        iText(500,220,str,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(mode==8) //round 3 encrypt text
    {
        iSetColor(255,255,255);
        iText(480,180,"energy",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,130,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=9;
    }
    else if(mode==10) //round 4 begin image && user input
    {
        iShowBMP2(0,0,"round 2 images\\level2-4.bmp",0);
        iSetColor(255,255,255);
        iText(450,50,"ROUND 4",GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(92,64,51);
        iText(500,220,str,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    else if(mode==11) // round 4  encrypt text
    {    
        iSetColor(255,255,255);
        iText(480,180,encrypt,GLUT_BITMAP_TIMES_ROMAN_24);
        iSetColor(255,255,255);
        iText(450,130,"Correct answer",GLUT_BITMAP_TIMES_ROMAN_24);
        mode=12;
    }

    

    
}

void game2keyboard(unsigned char key)
{
    int i;
	if(mode == 1) // round 1 user input
	{
        if(key == '\r')
		{
			mode = 0;
			strcpy(str2, str);
            if(strcmp(str,"12")==0)
            {
                 cipher("gibgvwbs",12);
                 mode=2;
            }
            else
            {
                mode=-1;
            }
			printf("%s\n", str2);
			for(i = 0; i < len; i++)
				str[i] = 0;
			len = 0;
		}
		else
		{
			str[len] = key;
			len++;
		}
    }
    if(mode==4) // round 2 user input
    {
        if(key=='\r')
        {
            mode=0;
            strcpy(str2,str);
            if(strcmp(str,"6")==0)
            {
                cipher("pifuncfy",6);
                mode=5;
            }
            else 
            {
                mode=-1;
            }
            printf("%s\n",str2);
            for(i=0;i<len;i++)
            str[i]=0;
            len=0;
        }
        else
        {
            str[len]=key;
            len++;
        }
    }
    
    if(mode==7) // round 3 user input
    {
        if(key=='\r')
        {
            mode=0;
            strcpy(str2,str);
        
         if(strcmp(str,"3")==0) 
         {
            cipher("bkbodv",3);
            mode=8;
         }
         else
         {
            mode=-1;
         }
         printf("%s\n",str);
         for(i=0;i<len;i++) 
         str[i]=0;
         len=0;
        }
        else
        {
            str[len]=key;
            len++;
        }
    }
     if(mode==10) // round 4 user input
     {
        if(key=='\r')
        {
            mode=0;
            strcpy(str2,str);
            if(strcmp(str,"2")==0)
            {
                cipher("bcapwnr",2);
                mode=11;
            }
            else
            {
                mode=-1;
            }
            for(i=0;i<len;i++)
            str[i]=0;
            len=0;
        }
        else
        {
            str[len]=key;
            len++;
        }
     }
     if(key=='x') exit(0); // for exiting game


    
        
}
void alllevelsmouse(int button,int state,int mx,int my)
{
       if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
       {
          
          if(levels==1 && (mx>=115 && mx <= 457) && (my>=403))
          {
            //level1=1;
            //levels=0;
          }
          if(levels==1 && (mx>=116 &&mx<=458) && (my>=189 && my<=263))
          {
             level2=1;
             levels=0;
          }
          if(levels==1 && (mx>=116 && mx <=452) && (my>=62 && my<=140))
          {
            //level3=1;
            //levels=0;
          }
          if(levels==1 && (mx>=119 && mx<=218) && (my>=453 && my<=558))
          {
            //homepage=0;
            //levels=0;
          }
       }

}
void game2imouse(int button,int state,int mx,int my)
{
       if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
       {
        if(mode==3)
        {
            mode=4;
        }
        else if(mode==6)
        {
            mode=7;
        }
       else  if(mode==9)
        {
            mode=10;
        }
       
       }
       
} 
        
int main()
{
    iInitialize(1024,600,"Brain Code: Renovo");
    return 0;
}
    
        
       
        
        
        
       



    
    
    
        
    
        
        




    
        
        
    
        
    
   
    
