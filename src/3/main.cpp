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

using namespace std;

static const int MAX=10;
//int int_arr[MAX] = {45,36,3,52,71,18,0,34,65,199};
int int_arr[MAX] = {8,3,1,5,2,1,4,7};
//
// Sorting an array by insertion sort.
//


void insertion_sort(int arr[MAX]);

int main()
{
    for (int i=0; i<MAX;i++)
        printf("%d ",int_arr[i]);
    cout << endl; 
    insertion_sort(int_arr);
    exit(EXIT_SUCCESS);
}

/* This function sort an array by an insertion sort. */
void insertion_sort(int arr[MAX])
{
    int tmp = 0;
    int insertion_element = 0;
    int break_all = 0;
    puts("==== Insertion sort ====");
    for (int i=0;i<MAX;i++) {
        break_all = 0;
        if (i == 0)
            continue;
        else if (i == 1) {
            if (arr[i] < arr[i-1]) {
                tmp = arr[i];
                arr[i] = arr[i-1];
                arr[i-1] = tmp;
                for (int i=0; i<MAX;i++){
                    printf("%d ",int_arr[i]);
                }
                cout << endl; 
            }
        } else {
            int j=i-1;
            int k=0;
            while (j>=0) {
                if (arr[i-1] <= arr[i]) {
                    j--;
                    continue;
                }
                if ((arr[j] < arr[i]) || j == 0) {
                    if ((j == 0) && (arr[j] >= arr[i]))
                        insertion_element = j;
                    else
                        insertion_element = j+1;
                    tmp = arr[i];
                    for(k=i;k>=insertion_element;k--)
                        arr[k] = arr[k-1];
                    arr[insertion_element] = tmp;
                    // Let's check.
                    for (int i=0; i<MAX;i++)
                        printf("%d ",int_arr[i]);
                    cout << endl; 
                }
                j--;
            }
        }
    }
    puts("==== Result ====");
    for (int i=0; i<MAX;i++)
        printf("%d ",int_arr[i]);
    cout << endl; 
}
