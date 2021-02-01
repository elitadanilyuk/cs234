/**
 * A program that gathers the year and day of the week the year begins and outputs the
 * calendar for the year. (The program does account for leap-years).
 *
 * @author Elita Danilyuk, S02664865
 * @verson2021-01-31, CSC-234 Display Calendar
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

/* A function the get the number of days in a given month. */
int getDays(int numMonth, int year){
    // January, March, May, July, August, October, December
    if(numMonth == 0 || (numMonth == 2) || (numMonth == 4) || (numMonth == 6) ||
            (numMonth == 7) || (numMonth == 9) || (numMonth == 11)){
        return 31;
    }
    // April, June, September, November
    else if(numMonth == 3 || (numMonth == 5) || (numMonth == 8) || (numMonth == 10)){
        return 30;
    }
    // Februrary
    else{
        if ((year % 4) == 0) {
            if ((year % 100) == 0) {
                if ((year % 400) == 0)
                    return 29;
                else
                    return 28;
            }
            else
                return 29;
        }
        else
            return 28;
    }
} //end getDays()

/* Function to calculate the correct day of the week */
int getDayOfWeek(int day, int month, int year)
{
    static int t[] = { 0, 3, 2, 5, 0, 3,
                       5, 1, 4, 6, 2, 4 };
    year -= month < 3;
    return ( year + year / 4 - year / 100 +
             year / 400 + t[month - 1] + day) % 7;
} //end getDayOfWeek

int main(int argc, const char * argv[]) {
    // string array to output the months
    string month[] = {"January", "Februrary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    // Initializing variables to get input from user
    int year;
    int initialDay;;
    
    // Gathering user input
    printf("Enter a year: ");
    cin >> year;
    printf("Enter the first day of the year: ");
    cin >> initialDay;
    
    initialDay+= 1;
    
    int current = getDayOfWeek(1, 1, year);
        
    // for() to iterate through each month
    for (int i = 0; i < 12; i++) {
        
        int numDays = getDays(i, year);
        
        // Output for the month - year - days of the week banners
        printf("\n%18s  %d\n", month[i].c_str(), year);
        printf("-----------------------------------\n");
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        
    
        // int to track the day of the week
        int x;
        /* for() to output spaces until the first of the month
            on the correct day of the week */
        for(x = 0; x < current; x++)
            printf("%5s", " ");
        
        // for() to iterate through the days of the month
        for(int j = 1; j <= numDays; j++){
            // output the correct days of the month
            printf("%5d", j);
            
            // if() to print a new line at the end of a week
            if (++x > 6){
                x = 0; // resetting x for the next week
                printf("\n");
            }
        } //end for(numDays)
        
        // output a new line for the end of the month
        printf("\n");
        
        // resetting current to the next months first day of the week
        current = x;

    } //end for(12months)
    
} //end main()
