/*
Problem :
Day of the Week

Given a date, return the corresponding day of the week for that date.

The input is given as three integers representing the day, month and year respectively.

Return the answer as one of the following values 
{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}.


Detailed explaination : notes and this link :
https://leetcode.com/problems/day-of-the-week/solutions/417560/easy-to-understand-with-complete-explaination-c-solution/

*/
package Maths;

public class predict_day_of_week {

    public String dayOfTheWeek(int day, int month, int year) {
        // initially we take non-leap year
        int[] months = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        String[] dayOfWeek = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

        // initialize the count
        int sum = 4;

        // calc the number of days present between 1971 and year start 0
        for (int i = 1971; i < year; i++) {
            // leap year condition
            if (((i % 4 == 0) && (i % 100 != 0)) || (i % 400 == 0))
                sum += 366;
            else
                sum += 365;
        }

        // calc the no. of days present in the months till the curr month in the curr
        // year given
        for (int i = 1; i < month; i++) {
            // take care of leap year feb month
            // if(i==2 && ̐̐̐̐̐̐̐̐̐̐̐==0 && i%100!=0) || (i%400==0))
            if (i == 2 && ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)))
                sum += 1;
            sum += months[i];
        }

        // calc till the give day in input
        sum += day;

        return dayOfWeek[sum % 7];

    }
}
