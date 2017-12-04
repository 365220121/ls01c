#ifndef  __UART_DRIVER_H
#define  __UART_DRIVER_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>

#include <semaphore.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>
#include <malloc.h>
#include <termios.h>
#include "math.h"
#include <stdbool.h>
#include <sys/time.h>

#define PACKSIZE  1811
#define PACKLEN   (PACKSIZE/5-2)
 

enum Command
{
	START_SCAN = 0, STOP_DATA = 1, STOP_MOTOR = 2, STOP_MOTOR_AND_DATA = 4, START_MOTOR_AND_DATA = 6,RESET = 8
};

struct basedata
{
	int flag;
	int start;
	int end;
	int curr;
	unsigned char data[PACKSIZE];
	struct basedata *next;
};

#pragma pack(1)
typedef struct _lslidar_response_measurement_node_t
{
	unsigned char sync_quality;
	unsigned short angle_q6_checkbit; //Ω«∂»
	unsigned short distance_q2;            //æ‡¿Î
	
} lslidar_response_measurement_node_t;

class lidar_driver
{

public:

	int OpenLidarSerial(const char* port, unsigned int baudrate);
	
	int SendLidarCommand(Command cmd);
	
	int GetLidarScanData(double *angle, double *distance, int len, double *speed);
	
	void CloseLidarSerial(void);
};

#endif
