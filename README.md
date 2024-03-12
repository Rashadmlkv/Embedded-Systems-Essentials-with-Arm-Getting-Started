ARM's course on edX.

task 0.0 and 0.1 combined:

I have used mbed api's command to build switch & led io interface.

DigitalIn and DigitalOut commands defines i/o pins while BusIn & BusOut combines them. GPIO's can only output in binary.
In ControlLED_DigitalIO function, program checks input voltage and assignes value to output pin. In that case pin with high voltage turns on.

ControlLED_BusIO function, does same aproach while using different human readeble code. case's here checks inputs, for example:
case 15 is 1111 in binary. It means while all 4 buttons pressed, all leds will turn on. 

To call a pin program uses reverse order of defined pins, that how computer works(?). In that case to call Red led which defined first, i used 0001.(least bit and most bit order).
