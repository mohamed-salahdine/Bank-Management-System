#pragma warning(disable:4996)
#pragma once
#include <iostream>
#include<string>
#include<vector>
#include"ClsString.h"
using namespace std;


class ClsDate
{
 private:
	 short _day = 1;
	 short _month = 1;
	 short _year = 1900;

 public:
	 ClsDate()
	 {
		 time_t t = time(0);
		 tm* now = localtime(&t);

		 _day = now->tm_mday;
		 _month = now->tm_mon + 1;
		 _year = now->tm_year + 1900;
	 }
	 ClsDate(string sDate)
	 {
		 vector<string>VDate;
		 VDate = ClsString::SplitString(sDate, "/");

		 _day = stoi(VDate[0]);
		 _month = stoi(VDate[1]);
		 _year = stoi(VDate[2]);

	 }
	 ClsDate(short day,short month,short year)
	 {
		 _day = day;
		 _month = month;
		 _year = year;

	 }
	 ClsDate(short DateOrdeInYear,short year)
	 {
		 ClsDate date = GetDateFromDayOrderInYear(DateOrdeInYear, year);

		 _day = date._day;
		 _month = date._month;
		 _year = date._year;



	 }


	 ClsDate GetDateFromDayOrderInYear(short orderDay, short year)
	 {
		 ClsDate date;
		
		 short DayMonth = 0;
		 short remainder = orderDay;

		 while (true)
		 {
			 DayMonth = NumberOfDayInTheMonth(year, date._month);
			 if (DayMonth < remainder)
			 {
				 remainder -= DayMonth;
				 date._month++;

			 }
			 else
			 {
				 date._day = remainder;
				 break;
			 }


		 }

		 return date;
	 }

	 static short NumberOfDayInTheMonth(short year, short month)
	 {
		 if (month < 1 || month>12)
		 {
			 return 0;
		 }

		 short NumberOfDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		 return (month == 2) ? (IsLeapYear(year) ? 29 : 28) : NumberOfDay[month];


	 }
	 short NumberOfDayInTheMonth()
	 {
		 return NumberOfDayInTheMonth(_year, _month);
	 }

	 static bool IsLeapYear(short year)
	 {
		 return (year % 400 == 0) || ((year % 4 == 00) && (year % 100 != 00));
	 }
	 bool IsLeapYear()
	 {
		 return IsLeapYear(_year);
	 }

	 void SetDay(short day)
	 {
		 _day = day;
	 }
	 short Day()
	 {
		 return _day;
	 }

	 void SetMonth(short month)
	 {
		 _month = month;
	 }
	 short Month()
	 {
		 return _month;
	 }

	 void SetYear(short year)
	 {
		 _year = year;
	 }
	 short Year()
	 {
		 return _year;
	 }

	 __declspec(property(get=Day,put=SetDay))short day;
	 __declspec(property(get = Month, put = SetMonth))short month;
	 __declspec(property(get=Year,put=SetYear))short year;

	 static string DateToString(ClsDate date)
	 {
		 return(to_string(date._day) + "/" + to_string(date._month) + "/"+to_string(date._year));
	 }
	 string DateToString()
	 {
		 return  DateToString(*this);
	 }

	 static string GetSystemDateTimeString()
	 {
		 time_t t = time(0);
		 tm* now = localtime(&t);

		 short Day, Month, Year, Hour, Minute, Second;

		 Day = now->tm_mday;
		 Month = now->tm_mon + 1;
		 Year = now->tm_year + 1900;
		 Hour = now->tm_hour;
		 Minute = now->tm_min;
		 Second = now->tm_sec;

		 return(to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - " + to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second));

	 }


	 void Print()
	 {
		 cout << DateToString() << endl;
	 }

	 static ClsDate GetSystemDate()
	 {
		 ClsDate date;
		 time_t t = time(0);
		 tm* now = localtime(&t);

		 date._day = now->tm_mday;
		 date._month = now->tm_mon + 1;
		 date._year = now->tm_year + 1900;

		 return date;
	 }

	 static bool IsValidDate(ClsDate date)
	 {
		 if (date._year < 1)
		 {
			 return false;
		 }
		 if (date._day < 1 || date._day>31)
		 {
			 return false;
		 }
		 if (date._month==2)
		 {
			 if (IsLeapYear(date._year))
			 {
				 if (date._day > 29)
					 return false;
			 }
			 else
			 {
				 if(date._day>28)
					 return false;
			 }

		 }
		 else
		 {
			 short DaysInMonth = NumberOfDayInTheMonth(date._year, date._month);
			 if (date._day>DaysInMonth)
			 {
				 return false;
			 }
		 }
		 
		 
		 

	 }
	 bool IsValidDate()
	 {
		 return IsValidDate(*this);
	 }

	 static string NameOfTheMonth(short Month)
	 {
		 string MonthName[] = { "","jan","fev","mar","avr","mai","jui","juil","aout","sep","oct","nov","dec" };

		 return MonthName[Month];
	 }
	 string NameOfTheMonth()
	 {
		 return NameOfTheMonth(_month);
	 }

	 static short DayOrderOfWeek(short year, short Month, short Day)
	 {


		 short a, y, m;

		 a = (14 - Month) / 12;
		 y = year - a;
		 m = Month + 12 * a - 2;

		 return (Day + y + (y / 7) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;


	 }
	 short DayOrderOfWeek()
	 {
		 return DayOrderOfWeek(_year, _month, _day);
	 }
	 static short DayOrderOfWeek(ClsDate dat)
	 {
		 return  DayOrderOfWeek(dat._year,dat._month,dat._day);
	 }

	 static void MonthCalendar(short year, short Month)
	 {
		 short NumberDayes = NumberOfDayInTheMonth(year, Month);
		 short beginningOftheMonth = DayOrderOfWeek(year, Month, 1);

		 printf("\n  ______________%s_________________\n\n", NameOfTheMonth(Month).c_str());

		 printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
		 int i;


		 for (i = 0; i < beginningOftheMonth; i++)

			 printf("     ");


		 for (int j = 1; j <= NumberDayes; j++)
		 {
			 printf("%5d", j);


			 if (i++ == 6)
			 {
				 cout << "\n";
				 i = 0;

			 }


		 }
		 printf("\n  __________________________________\n");


	 }
	 void MonthCalendar()
	 {
		 return MonthCalendar(_year, _month);
	 }

	 static void PrintYearCalendar(short year)
	 {
		 printf("\n  __________________________________\n");
		 printf("            Calender -%d      ", year);
		 printf("\n  __________________________________\n");

		 for (int i = 1; i <= 12; i++)
		 {
			 MonthCalendar(year, i);


		 }


	 }
	 void PrintYearCalendar()
	 {
		  PrintYearCalendar(_year);
	 }

	 static void SwapDates(ClsDate &date1,ClsDate &date2)
	 {
		 ClsDate swap;
		 swap = date1;
		 date1 = date2;
		 date2 = swap;

	 }
	 void SwapDates( ClsDate& date2)
	 {
		 SwapDates(*this, date2);
	 }

	 static bool Is_Last_Month_In_Year(short Month)
	 {
		 return (Month == 12);

	 }
	 bool Is_Last_Month_In_Year()
	 {
		 return Is_Last_Month_In_Year(_month);
	 }

	 static bool Is_Last_Day_In_Month(ClsDate dat)
	 {
		 return (dat._day == NumberOfDayInTheMonth(dat._year, dat._month));

	 }
	 bool Is_Last_Day_In_Month()
	 {
		 return  Is_Last_Day_In_Month(*this);
	 }


	 static ClsDate IncreaseDatByOneDay(ClsDate dat)
	 {
		 if (Is_Last_Day_In_Month(dat))
		 {
			 if (Is_Last_Month_In_Year(dat._month))
			 {
				 dat._day = 1;
				 dat._month = 1;
				 dat._year++;

			 }
			 else
			 {
				 dat._day = 1;
				 dat._month++;

			 }

		 }
		 else
		 {
			 dat._day++;
		 }

		 return dat;
	 }
	 void IncreaseDatByOneDay()
	 {
		 *this = IncreaseDatByOneDay(*this);
	 }

	 static bool IsDate1BeforeDate2(ClsDate Dat1, ClsDate Dat2)
	 {

		 return (Dat1._year < Dat2._year) ? true : ((Dat1._year == Dat2._year) ? ((Dat1._month < Dat2._month) ? true : (Dat1._month == Dat2._month) ? (Dat1._day < Dat2._day) : false) : false);

	 }
	 bool IsDate1BeforeDate2( ClsDate Dat2)
	 {
		 return  IsDate1BeforeDate2(*this, Dat2);
	 }


	 static int GetDifferenceInDays(ClsDate dat1, ClsDate dat2, bool includingDay = false)
	 {
		 int NumberDay = 0;


		 while (IsDate1BeforeDate2(dat1, dat2))
		 {
			 NumberDay++;
			 dat1 = IncreaseDatByOneDay(dat1);
		 }

		 return includingDay ? ++NumberDay : NumberDay;
	 }
	 int GetDifferenceInDays( ClsDate dat2, bool includingDay = false)
	 {
		 return  GetDifferenceInDays(*this, dat2,includingDay);
	 }

	 static ClsDate IncreaseDatByOneWeek(ClsDate& Dat)
	 {
		 for (int i = 1; i <= 7; i++)
		 {
			 Dat = IncreaseDatByOneDay(Dat);

		 }

		 return Dat;

	 }
	 void IncreaseDatByOneWeek()
	 {
		  IncreaseDatByOneWeek(*this);
	 }

	 static ClsDate IncreaseDatByOneMonth(ClsDate &Dat)
	 {
		 if (Dat._month == 12)
		 {
			 Dat._month = 1;
			 Dat._year++;

		 }
		 else
		 {
			 Dat._month++;

		 }
		 short NumberOfDayesInCurrentMonth = NumberOfDayInTheMonth(Dat._year, Dat._month);
		 if (Dat._day > NumberOfDayesInCurrentMonth)
		 {
			 Dat._day = NumberOfDayesInCurrentMonth;
		 }


		 return Dat;
	 }
	 void IncreaseDatByOneMonth()
	 {
		 IncreaseDatByOneMonth(*this);
	 }

	 static bool IsEndOfWeek(ClsDate dat)
	 {
		 short OrderDay = DayOrderOfWeek(dat);

		 return(OrderDay == 6);

	 }
	 bool IsEndOfWeek()
	 {
		 return  IsEndOfWeek(*this);
	 }

	 static bool IsWeekEnd(ClsDate dat)
	 {
		 short OrderDay = DayOrderOfWeek(dat);

		 return(OrderDay == 5 || OrderDay == 6);

	 }
	 bool IsWeekEnd()
	 {
		 return IsWeekEnd(*this);
	 }

	 static bool IsBusinessDay(ClsDate dat)
	 {
		 return(!IsWeekEnd(dat));

	 }
	 bool IsBusinessDay()
	 {
		 return  IsBusinessDay(*this);
	 }

	 static short CulculatBusinessDayes(ClsDate dateFrom,ClsDate datTo)
	 {
		 short Dayes = 0;
		 while (IsDate1BeforeDate2(dateFrom,datTo))
		 {
			 if (IsBusinessDay(dateFrom))
			 {
				 Dayes++;
			 }
			 dateFrom = IncreaseDatByOneDay(dateFrom);
		 }
		 return Dayes;
	 }
	 short CulculatBusinessDayes( ClsDate datTo)
	 {
		 return CulculatBusinessDayes(*this, datTo);
	
	 }

	 static bool Check_If_Dat1_Equals_To_Dat2(ClsDate Dat1, ClsDate Dat2)
	 {

		 return (Dat1._year == Dat2._year) ? ((Dat1._month == Dat2._month) ? ((Dat1._day == Dat2._day) ? true : false) : false) : false;

	 }
	 bool Check_If_Dat1_Equals_To_Dat2(ClsDate Dat2)
	 {
		 return Check_If_Dat1_Equals_To_Dat2(*this, Dat2);
	 }


	 enum enComparDat { Befor = -1, Equal = 0, After = 1 };

	 static enComparDat CompareDates(ClsDate dat1, ClsDate dat2)
	 {
		 if (ClsDate::IsDate1BeforeDate2(dat1, dat2))
			 return enComparDat::Befor;

		 if (ClsDate::Check_If_Dat1_Equals_To_Dat2(dat1, dat2))
			 return enComparDat::Equal;

		 return enComparDat::After;


	 }
	 enComparDat CompareDates( ClsDate dat2)
	 {
		 return  CompareDates(*this, dat2);
	 }

	 
	static bool IsDat1AfterDat2(ClsDate Dat1, ClsDate Dat2)
	 {
		 return(!IsDate1BeforeDate2(Dat1, Dat2) && !Check_If_Dat1_Equals_To_Dat2(Dat1, Dat2));

	 }
	bool IsDat1AfterDat2( ClsDate Dat2)
	{
		return  IsDat1AfterDat2(*this, Dat2);
	}






};

