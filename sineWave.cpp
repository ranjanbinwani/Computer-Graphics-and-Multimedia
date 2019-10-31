#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>

using namespace std; 

/* set cursor macro */
#define setCursor(crd)	SetConsoleCursorPosition ( GetStdHandle ( STD_OUTPUT_HANDLE ), crd )

/* settings */
#define SINEHEIGHT  20
#define DEGREESTEP  5

/* local functions */
void DrawSine (int degree); 

/* main */
int main()
{	
	system("CLS");
	DrawSine(360);
	system("pause");
	return 0;
}

/* draw a sine */
void DrawSine (int degree)
{
	COORD curPos = {0,0};

	for (int x = 0 ; x < degree ; x = x + DEGREESTEP )
	{		
		curPos.X = floor( ( x / DEGREESTEP ) + 1 );
		curPos.Y = floor( ( ( ( ( -1 * sin(x * 3.141 / 180 ) ) + 1) * ( SINEHEIGHT / 2 ) ) ) + 0.5 );
		
		setCursor( curPos );

		cout << "." ;
	}
	
	//pos y
	for(int i=0 ; i<SINEHEIGHT/2;i++){
		curPos.X = 0 ;
		curPos.Y = i;
		setCursor(curPos);
		cout<<SINEHEIGHT/2-i;
	}
	//neg y
	for(int i=SINEHEIGHT/2 ; i<SINEHEIGHT;i++){
		curPos.X = 0 ;
		curPos.Y = i;
		setCursor(curPos);
		cout<<(SINEHEIGHT/2-i);
	}

	for(int i=0 ; i < degree/DEGREESTEP;i++){
		curPos.X = i ;
		curPos.Y = SINEHEIGHT/2;
		setCursor(curPos);
		cout<<"-";
	}

	curPos.X = 0;
	curPos.Y = SINEHEIGHT+2 ;
	setCursor(curPos);
}
