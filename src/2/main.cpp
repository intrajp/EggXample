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

//
// What is the largest difference between two numbers?
//

static const int MAX=10;

void get_biggest_difference(int num, int arr[MAX]);
bool check_number(string str);
int check_int(int x, int y, string a);

int main()
{
    puts("Input many numbers separated by a blank..");
    printf("First, designate how many numbers (less than %d) you want to input.\n",MAX);
    string user_num;
    string user_num_arr_element;
    int int_arr[MAX];

    int check_i = 1;
    do {
        cout << endl << "Please input number less than " << MAX << " :";
        cin >> user_num;
        printf("\n");
        if(check_number(user_num)==false) {
            puts("Error.");
            continue;
        }
        check_i = check_int(0, MAX, user_num);
    } while ( check_i == 1);

    for (int i=0; i<stoi(user_num); i++) {
        while (1) {
            printf("Input a number: ");
            cin >> user_num_arr_element; 
            if(check_number(user_num_arr_element)==false) {
                puts("Error.");
                continue;
            } else
                break;
        }
        int_arr[i] = stoi(user_num_arr_element); 
    }

    for (int i=0; i<stoi(user_num);i++){
        printf("%d ",int_arr[i]);
    }
    puts("");
    get_biggest_difference(stoi(user_num), int_arr);
    exit(EXIT_SUCCESS);
}

/* This function checks if given parameter is all digit. */
bool check_number(string str) {
   for (int i = 0; i < str.length(); i++)
       if (isdigit(str[i]) == false)
          return false;
          return true;
}

/* This funcion checks if the number is in the range. */
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

/* This function shows the biggest difference of twe numbers from the int array. */
void get_biggest_difference(int num, int arr[MAX])
{
    int tmp = 0;
    int max_diff = 0;
    int k = 0;
    int element_of_first_number = 0;
    int element_of_second_number = 0;
    int first_number = 0;
    int first_number_fixed = 0;
    int second_number = 0;
    for (int i=0; i<num;i++){
        for (int j=k; j<num;j++){
            if (j == k)
                first_number = arr[j];
            else
                if ((arr[j] - first_number) > max_diff) {
                    max_diff = arr[j] - first_number;
                    element_of_first_number = k;
                    element_of_second_number = j;
                    first_number_fixed = first_number;
                    second_number = arr[j];
                }
        }
	k++;
    }
    puts("==== Result ====");
    printf("Max difference is %d .\n",max_diff);
    printf("Element of first number is %d and the number is %d.\n",element_of_first_number, first_number_fixed);
    printf("Element of second number is %d and the number is %d.\n",element_of_second_number, second_number);
}
