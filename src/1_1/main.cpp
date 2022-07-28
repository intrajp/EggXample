#include <iostream>
#include <stdio.h>
#include <error.h>

//Replace an array element to 0 which is the biggest.
//

using namespace std;

//int int_arr[10] = {45,36,,52,34,18,0,34,199,65};
//int int_arr[10] = {199,45,36,3,52,34,18,0,34,65};
int int_arr[10] = {45,36,3,52,71,18,0,34,65,199};

bool check_number(string str);

//Replace array element 

void print_max(int a);
int check_int(int x, int y, string a);

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

    puts("==== Result ====");
    for (int i=0; i<stoi(user_num); i++)
        print_max(i);

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

// This function finds bigges number from an array and repead x times.
void print_max(int x)
{
    int max_number=0;
    int max_element=0;
    for (int i=0; i<10; i++){
        if (max_number < int_arr[i]) {
            max_number = int_arr[i]; 
            max_element = i; 
        }
    }
    cout << "max_number" << x+1 << ":" << max_number << endl;

    // First, we copy before the max_element to itself.
    for (int i=0; i<max_element;i++){
        int_arr[i] = int_arr[i];
    }
    // second, we set 0 to the max_element. 
    int_arr[max_element] = 0;
    // Thirdly, we copy after the max_element to itself.
    for (int i=max_element+1; i<10;i++){
        int_arr[i-1] = int_arr[i];
        if (i==9)
            int_arr[i] = 0;
    }
}
