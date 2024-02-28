/*
    tserver.c: telnet server for serial port emulation

    Copyright (C) 2009-2012  Jesus Calvino-Fraga, jesusc (at) ece.ubc.ca
    
	This program is free software; you can redistribute it and/or modify it
	under the terms of the GNU General Public License as published by the
	Free Software Foundation; either version 2, or (at your option) any
	later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program; if not, write to the Free Software
	Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/

// IMPORTANT: compile using /MT and link with ws2_32.lib and wininet.lib

#include <windows.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>
#include <process.h>
#include "s51.h"

volatile int connected=0;

SOCKET server, client;
WSADATA wsaData;
SOCKADDR_IN local, from;
int fromlen=sizeof(from);
int wsaret;
    
UINT ServerThread(LPVOID pParam)
{	
    //printf("Starting serial port Telnet server on port 23.\r\n");
    
    //WSAStartup initializes the program for calling WinSock.
    //The first parameter specifies the highest version of the 
    //WinSock specification, the program is allowed to use.
    wsaret=WSAStartup(0x101,&wsaData);

    //WSAStartup returns zero on success.
    if(wsaret!=0) //If it fails we exit.
    {
        return 0;
    }

    //Now we populate the sockaddr_in structure

    local.sin_family=AF_INET; //Address family
    local.sin_addr.s_addr=INADDR_ANY; //Wild card IP address
    local.sin_port=htons((u_short)23); //port to use

    //the socket function creates our SOCKET
    server=socket(AF_INET,SOCK_STREAM,0);

    //If the socket() function fails we exit
    if(server==INVALID_SOCKET)
    {
        return 0;
    }

    //bind links the socket we just created with the sockaddr_in 
    //structure. Basically it connects the socket with 
    //the local address and a specified port.
    //If it returns non-zero quit, as this indicates error

    if(bind(server,(const struct sockaddr *)&local,sizeof(local))!=0)
    {
        return 0;
    }

    //listen instructs the socket to listen for incoming 
    //connections from clients. The second arg is the backlog
    if(listen(server,10)!=0)
    {
        return 0;
    }

    while(1)//we are looping endlessly
    {
        //char temp[64];
        char recvbuf[64];
        int iResult;
        
        //accept() will accept an incoming client connection
        client=accept(server, (struct sockaddr*)&from,&fromlen);

        //sprintf(temp,"Your IP is %s\r\nPress 'X' to exit program.\r\n",inet_ntoa(from.sin_addr));

        //send(client,temp,strlen(temp),0);
        //printf("Connection from %s\r\n",inet_ntoa(from.sin_addr));
		connected=1;
		
		while(1)
		{
			fd_set read_set;
			TIMEVAL select_timeout;
			// Need to use select() before using recv() to prevent blocking.
	        read_set.fd_count=1;
	        read_set.fd_array[0]=client;
	        select_timeout.tv_sec=0L;
	        select_timeout.tv_usec=100000L;
			if(select(0, &read_set, NULL, NULL, &select_timeout)!=0)
			{
				//iResult = recv(client, recvbuf, 1, MSG_PEEK ); // We can check how many bytes there are available!
				iResult = recv(client, recvbuf, 1, 0);
				if(iResult>0)
				{
					if(SCON&0x10) // If recepcion enabled
					{
						SBUF=recvbuf[0];
						SCON|=0x01; // RI=1
					}
				}
				else break; // Connection gracefully closed!
			}
		}
		
        closesocket(client);
        connected=0;
    }

    closesocket(server);
    WSACleanup();

    return 0;
}

void send_telnet(char * buff, int size)
{
	send(client,buff,1,0);
}

