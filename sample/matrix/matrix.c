#include <stdio.h>
#include <stdint.h>
#include <unistd.h>

#include "wiringPi.h"
#include "wiringPiSPI.h"

#define RED_DATA 0
#define BULE_DATA 1
#define GREEN_DARA 2

int main(int argc, char *argv[])
{
    int rc = 0;
    static uint8_t data[4] = {0x0, 0x0, 0x0, 0x0};
    
    rc = wiringPiSetup();
    printf("[%s %d]rc[%d]\n", __FUNCTION__, __LINE__, rc);
    rc = wiringPiSPISetup(0, 500000);
    printf("[%s %d]rc[%d]\n", __FUNCTION__, __LINE__, rc);
    
    while(1)
    {
        static uint8_t heart[8] = {0x00, 0x66, 0xFF, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};
        int j;
        int x = 2;

        for (j = 0; j < 8; j++)
        {
            data[0] = ~heart[j];
            data[1] = 0xFF;
            data[2] = 0xFF;
            data[3] = 0x01 << j;
            printf("%x %x %x %x\n", data[0], data[1], data[2], data[3]);
            wiringPiSPIDataRW(0, data, sizeof(data));
            delay(x);
        }
    }

    return 0;
}
