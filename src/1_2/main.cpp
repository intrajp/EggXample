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

//Try to change the array elements for debug.
//int int_arr[10] = {125,16,4,355,75,18,0,75,59,32};
//int int_arr[10] = {0,125,16,4,355,75,18,75,59,32};
int int_arr[10] = {16,4,355,125,0,75,18,75,59,32};

// Bubble sort solution.
//
void bubble_sort(int a, int num);
bool check_number(string str);
int check_int(int x, int y, string a);
void bubble_sort(int a);

int main()
{
    puts("Order by numbers descent of numbers below to the numbers you input.");
    for (int i=0; i<10;i++){
        printf("%d ",int_arr[i]);
    }
    string user_num;
    int check_i = 1;
    do {
        cout << endl << "Please input number less than 10: ";
        cin >> user_num;
        printf("\n");
        if(check_number(user_num)==false) {
            puts("Error.");
            continue;
        }
        check_i = check_int(0, 10, user_num);
    } while ( check_i == 1);
    printf("Your input:%d\n",stoi(user_num));
    bubble_sort(10,stoi(user_num));
    cout << endl;
    exit(EXIT_SUCCESS);
}

// This function checks if given parameter is all digit.
bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
   if (isdigit(str[i]) == false)
      return false;
      return true;
}

// This funcion checks if the number is in the range.
int check_int(int x, int y, string a)
{
    int num;
    //Refer https://www.freecodecamp.org/news/string-to-int-in-c-how-to-convert-a-string-to-an-integer-example/
    num = stoi(a);
    try {
        throw num; 
    }
    catch (int num) {
        if ((num <= x) || (num > y)) {
            puts("Error.");
            return 1;
        } else {
            return 0;
        }
    }
    catch (...) {
        puts("Unkown error.");
        return 1;
    }
    return 1;
}

// This function do bubble sort up to the second parameter.
void bubble_sort(int a, int num)
{
    int temp=0;
    for(int i=0;i<a;i++) {	
        for(int j=a;j>0;j--){
            if (int_arr[j] > int_arr[j-1]) {
                temp = int_arr[j-1];
                int_arr[j-1] = int_arr[j];
                int_arr[j] = temp;
            }
        }
    }
    puts("==== Result ====");
    for (int i=0; i<num;i++){
        printf("%d ",int_arr[i]);
    }
}
