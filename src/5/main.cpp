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
// Selection sort.
//

const int MAX=10;
using namespace std;

//Try to change the array elements for debug.
//int int_arr[MAX] = {125,16,4,355,75,18,0,75,59,32};
//int int_arr[MAX] = {0,125,16,4,355,75,18,75,59,32};
int int_arr[MAX] = {16,4,355,125,0,75,18,75,59,32};

void selection_sort(int arr[]);

int main()
{
    for (int i=0;i<MAX;i++)
        printf("%d ",int_arr[i]);
    selection_sort(int_arr);
    cout << endl;
    exit(EXIT_SUCCESS);
}

// This function do selection sort the array.
void selection_sort(int arr[])
{
    int temp=0;
    int smallest=200000;
    int smallest_element=0;
    for(int i=0;i<MAX;i++) {	
        smallest_element=0;
        for (int j=i;j<MAX;j++) {
            if (smallest > arr[j]) {
                smallest = arr[j];
                smallest_element = j;
            }
        }
        temp = arr[i];
        arr[i] = smallest;
        arr[smallest_element] = temp;
        if (i == 0)
            puts("\n==== selecting ====");
        for (int i=0; i<MAX;i++)
            printf("%d ",arr[i]);
        cout << endl;
        smallest=200000;
    }
    puts("\n==== Result ====");
    for (int i=0; i<MAX;i++)
        printf("%d ",arr[i]);
    cout << endl;
}
