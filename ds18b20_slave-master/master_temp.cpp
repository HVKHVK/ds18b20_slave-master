#include <iostream>
#include <errno.h>
#include <unistd.h>
#include <stdint.h>
#include <wiringPiI2C.h>

using namespace std;

int main()
{
    int8_t temp;
    int send, data, id;
    
	send = wiringPiI2CSetup (0x0B);

	while (1)
	{
		wiringPiI2CWrite (send, 1);

        data = wiringPiI2CRead (send);
		sleep(1);
        data = wiringPiI2CRead (send);
        sleep(1);

		temp = wiringPiI2CRead (send);
   
        cout << "Temp: "<< (int)temp << endl;
		cout << "\n" << endl;
        break;
	}	
}

