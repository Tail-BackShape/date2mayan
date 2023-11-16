#include <stdio.h>
#include <math.h>

// GregorianDay to JulianDay
int clcltJulianDay(int year, int month, int day)
{
    int a = (14 - month) / 12;
    int y = year + 4800 - a;
    int m = month + 12 * a - 3;
    int julianDay = day + (153 * m + 2) / 5 + 365 * y + y / 4 - y / 100 + y / 400 - 32045;

    return julianDay;
}

// JulianDay to MayanDay
int clcltMayanDay(int julianDay)
{
    int mayanDay = julianDay - 584283;

    return mayanDay;
}

// GregorianDay to LongMayanDay
void toLongCalendar(int mayanDay, int longMayan[5])
{

    int baktun = mayanDay / 144000; // 1 Baktun = 144,000 day
    longMayan[0] = baktun;
    mayanDay = mayanDay % 144000;

    int katun = mayanDay / 7200; // 1 Katun = 7,200 day
    longMayan[1] = katun;
    mayanDay = mayanDay % 7200;

    int tun = mayanDay / 360; // 1 Tun = 360day
    longMayan[2] = tun;
    mayanDay = mayanDay % 360;

    int uinal = mayanDay / 20; // 1 Uinal = 20 day
    longMayan[3] = uinal;

    int kin = mayanDay % 20; // 1 Kin = 1 day
    longMayan[4] = kin;
}

// MayanDay to TzolkinDayName
char *toTzolkinDayName(int kin)
{
    char *dayList[20] = {
        "Ahau",
        "Imix",
        "Ik",
        "Akbal",
        "Kan",
        "Chicchan",
        "Cimi",
        "Manik",
        "Lamat",
        "Muluc",
        "Oc",
        "Chuen",
        "Eb",
        "Ben",
        "Ix",
        "Men",
        "Cib",
        "Caban",
        "Etzunab",
        "Cauac",
    };

    return dayList[kin];
}

// MayanDay to TzolkinDayNumber
int toTzolkinDayNum(int mayanDay)
{
    int tzolkinDayNum;
    tzolkinDayNum = ((mayanDay + 3) % 13) + 1;
    return tzolkinDayNum;
}

// MayanDay to HaabMonth
char *toHaabMonth(int mayanDay)
{
    int hCff = (mayanDay + 348) % 365;
    int Hm = (hCff / 20);
    char *hMonthList[19] = {
        "Pop",
        "Uo",
        "Zip",
        "Zotz",
        "Tzec",
        "Xul",
        "Yaxkin",
        "Mol",
        "Ch'en",
        "Yax",
        "Zac",
        "Ceh",
        "Mac",
        "Kankin",
        "Muan",
        "Pax",
        "Kayab",
        "Cumku",
        "Uayeb",
    };

    return hMonthList[Hm];
}

// MayanDay to HaabDay
int toHaabDay(int mayanDay)
{
    int hCff = (mayanDay + 348) % 365;
    int Hd = hCff % 20;
    return Hd;
}

int main()
{
    int year, month, day, julianDay, mayanDay, tzolkinDayNum, haabDay, select;
    int longMayan[5];
    char *tzolkinDayName, *haabMonth;

    // Do at least one conversion program
    do
    {
        // input year,month,day
        printf("Enter a date you want to know(YYYY MM DD)>");
        scanf("%d %d %d", &year, &month, &day);

        // Calculate each value with a function
        julianDay = clcltJulianDay(year, month, day);
        mayanDay = clcltMayanDay(julianDay);
        toLongCalendar(mayanDay, longMayan);
        tzolkinDayName = toTzolkinDayName(longMayan[4]);
        tzolkinDayNum = toTzolkinDayNum(mayanDay);
        haabMonth = toHaabMonth(mayanDay);
        haabDay = toHaabDay(mayanDay);

        // output basic Julian day and Mayan day
        printf("\nJulianDay\t%d\n", julianDay);
        printf("MayanDay\t%d\n", mayanDay);

        printf("\n----------Mayan Calendar----------\n");
        // output Mayan calendar
        printf("\t\t\tBaktun\tKatun\tTun\tUinal\tKin\n");
        printf("Long calendar\t:\t%d.\t%d.\t%d.\t%d.\t%d\n",
               longMayan[0], longMayan[1], longMayan[2], longMayan[3], longMayan[4]);
        printf("\nTzolkinDay\t:\t%d\t%s\n", tzolkinDayNum, tzolkinDayName);
        printf("\nHaabDay\t\t:\t%d\t%s\n", haabDay, haabMonth);

        // Select to continue or exit
        printf("\nRun the program again?(no=>0/yes=>1)>");
        scanf("%d", &select);
    } while (select);

    return 0;
}

/*
　 （　・∀・）　|　|　
　  　　　　）　 |　|
　　Ｙ  / ノ　　 人
　　　 / ) 　 < 　>
　   /  '　 ／／∧＿∧
　__/        （　´∀｀）＜ error: 'nurupo' undeclared (first use in this function)
(__            /    |
            ==========
*/
