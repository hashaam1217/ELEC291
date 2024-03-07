/*  floorf.c: Returns the integer smaller or equal than x

    Copyright (C) 2001-2011  Jesus Calvino-Fraga, jesusc (at) ece.ubc.ca

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA */

#include <math.h>

#pragma overlayto ?lib?dseg?1

#ifdef C51_STACK_AUTO
#define data
#endif

float floorf (float x)
{
    data long int r;
    
    r=x;
    if (r<=0)
        return (r+((r>x)?-1:0));
    else
        return r;
}