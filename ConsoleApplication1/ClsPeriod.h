#pragma warning(disable:4996)
#pragma once
#include <iostream>
#include<string>
#include"ClsString.h"
#include"ClsData.h"


class ClsPeriod
{
public:
	ClsDate StarDate;
	ClsDate EndDate;

	ClsPeriod(ClsDate StarDate,ClsDate EndDate)
	{
		this->StarDate = StarDate;
		this->EndDate = EndDate;


	}



	static bool IsOverLapPeriods(ClsPeriod Period1, ClsPeriod  Periode2)
	{
		if ((ClsDate::CompareDates(Period1.EndDate, Periode2.StarDate) == ClsDate::enComparDat::Befor) || (ClsDate::CompareDates(Period1.StarDate, Periode2.EndDate) == ClsDate::enComparDat::After))
			return false;
		return true;

	}
	bool IsOverLapPeriods( ClsPeriod  Periode2)
	{
		return   IsOverLapPeriods(*this,  Periode2);
	}

	static bool IsDatWithinPeriod(ClsPeriod Period, ClsDate Dat)
	{
		return!((ClsDate::CompareDates(Dat, Period.StarDate) == ClsDate::enComparDat::Befor) || (ClsDate::CompareDates(Dat, Period.EndDate) == ClsDate::enComparDat::After));

	}
	bool IsDatWithinPeriod( ClsDate Dat)
	{
		return  IsDatWithinPeriod(*this, Dat);
	}


	void print()
	{
		cout << "Period Star:\n";
		StarDate.Print();
		cout << "\nPeriod End:\n";
		EndDate.Print();
	}






};

