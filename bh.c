/*  
 *  BH1750FVI read for Raspberry Pi
 *
 *  Copyright (C) 2014 EverPi - everpi[at]tsar[dot]in
 *  blog.everpi.net 
 * 
 *  This file is part of BH1750FVI.
 *
 *  BH1750FVI is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  BH1750FVI is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with BH1750FVI.  If not, see <http://www.gnu.org/licenses/>.
 *
 */


#include <stdio.h>
#include <wiringPiI2C.h>

int main(){
	
	int fd = 0;
	unsigned int data = 0;	

	fd = wiringPiI2CSetup(0x23) ;
	
	while(1){
		data = wiringPiI2CReadReg16(fd,0x10);
		fprintf(stderr,"%d lx\n", (int)(((data>>8)+((data&0xff)<<8)) / 1.2) );
		
		usleep(500000);
        }

	return 0;
}
