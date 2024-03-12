#include "mbed.h"

#define BUTTON_1 p5
#define BUTTON_2 p6
#define BUTTON_3 p7
#define BUTTON_4 p8

#define RED_LED p9
#define YELLOW_LED p10
#define BLUE_LED p11


// Define the Input pins
	DigitalIn in1(p5);
	DigitalIn in2(BUTTON_2);
	DigitalIn in3(BUTTON_3);
	DigitalIn in4(BUTTON_4);

//Define the Output pins
	DigitalOut red(RED_LED);
	DigitalOut ylw(YELLOW_LED);
	DigitalOut ble(BLUE_LED);

//Define Input/Output buses
	BusIn inp(BUTTON_1, BUTTON_2, BUTTON_3, BUTTON_4);
	BusOut out(RED_LED, YELLOW_LED, BLUE_LED);

void ControlLED_DigitalIO ();
void ControlLED_BusIO ();


int main()
{
    while(1) {
        //ControlLED_DigitalIO ();
        ControlLED_BusIO ();
        wait(0.25);
    }
}

void ControlLED_DigitalIO (){
          red = (!in4&&(!in3||in2)) || (in4&&in3&&in2&&in1);
          ylw = (in4^in3) || (in4&&in3&&in2&&in1);
          ble = in4;
}

void ControlLED_BusIO (){
    switch (inp){
    case 0 ... 3:
        out = 0b0100;
        break;
    case 4 ... 5:
        out = 0b0010;
        break;
    case 6 ... 7:
        out = 0b0011;
        break;
    case 8 ... 11:
        out = 0b0101;
        break;
    case 12 ... 14:
        out = 0b0001;
        break;
    case 15:
        out = 0b0111;
        break;

    }
}

