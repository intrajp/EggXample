/*
 * main.cpp - for EggXample.
 * This file contains the contents of saj.
 *
 *  Copyright (C) 2022 Shintaro Fujiwara
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 *  02110-1301 USA
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <error.h>

//
// Shell sort.
//

const int MAX=10;
const int SHELL=3;
using namespace std;

//Try to change the array elements for debug.
//int int_arr[MAX] = {125,16,4,355,75,18,0,75,59,32};
//int int_arr[MAX] = {0,125,16,4,355,75,18,75,59,32};
int int_arr[MAX] = {16,4,355,125,0,75,18,75,59,32};

int g_arr[SHELL] = {4,3,1};

void shell_sort(int arr[]);

int main()
{
    puts("\n==== Start ====");
    for (int i=0;i<MAX;i++)
        printf("%d ",int_arr[i]);
    shell_sort(int_arr);
    cout << endl;
    exit(EXIT_SUCCESS);
}

// This function do shell sort the array.
void shell_sort(int arr[])
{
    int temp=0;
    int m;
    int s;
    int x;
    int y;
    for (int m=0;m<SHELL;m++) {
        s = MAX / g_arr[m];
        printf("\n==== SHELL is %d ====\n",g_arr[m]);
        for(s;s>0;s--) {
            for(int i=0;i<MAX;i++) {	
                x = g_arr[m] * s + i;
                y = g_arr[m] * (s-1) + i;
                if (x>MAX-1)
                    continue;
                if (y>MAX-1)
                    break;
                printf("Compare arr[%d]:%d and arr[%d]:%d\n",y,arr[y],x,arr[x]);
                if (arr[x] < arr[y]) {
                    temp = arr[y];
                    arr[y] = arr[x];
                    arr[x] = temp;
                    for (int i=0; i<MAX;i++)
                        printf("%d ",arr[i]);
                    cout << endl;
	        } else {
                    cout << "skip" << endl;
                }
            }
        }
    }
    puts("\n==== Result ====");
    for (int i=0; i<MAX;i++)
        printf("%d ",arr[i]);
    cout << endl;
}
