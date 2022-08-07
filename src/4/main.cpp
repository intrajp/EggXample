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
// Bubble sort.
//

const int MAX=10;
using namespace std;

//Try to change the array elements for debug.
//int int_arr[MAX] = {125,16,4,355,75,18,0,75,59,32};
//int int_arr[MAX] = {0,125,16,4,355,75,18,75,59,32};
int int_arr[MAX] = {16,4,355,125,0,75,18,75,59,32};

void bubble_sort(int arr[]);

int main()
{
    puts("Order by numbers descent of numbers below to the numbers you input.");
    for (int i=0;i<MAX;i++)
        printf("%d ",int_arr[i]);
    bubble_sort(int_arr);
    cout << endl;
    exit(EXIT_SUCCESS);
}

// This function do bubble sort up to the second parameter.
void bubble_sort(int arr[])
{
    int temp=0;
    for(int i=0;i<MAX;i++) {	
        for(int j=MAX-1;j>=0;j--){
            if (arr[j] < arr[j-1]) {
                temp = arr[j];
                arr[j] = arr[j-1];
                arr[j-1] = temp;
            }
        }
        if ( i == 0) {
            cout << endl;
            puts("==== Bubbling ====");
        }
        for (int k=0; k<MAX;k++)
            printf("%d ",arr[k]);
        cout << endl;
    }
    puts("==== Result ====");
    for (int i=0; i<MAX;i++)
        printf("%d ",arr[i]);
    cout << endl;
}
