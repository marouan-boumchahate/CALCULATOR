#pragma once

#include <iostream>
#include "clsUtil.h"

class clsScreen
{
private:
	static void _CalculatorStyle()
	{
		cout << clsUtil::Tabs(6) << clsUtil::Design('-', 31) << endl;

		cout << clsUtil::Tabs(6) << "|" << "     " << "|" << "     " << "|" << "     " << "|" << "     |" << "     |" << endl;
		cout << clsUtil::Tabs(6) << "|" << "  1  " << "|" << "  2  " << "|" << "  3  " << "|" << "  +  |" << "  .  |" << endl;
		cout << clsUtil::Tabs(6) << "|" << "     " << "|" << "     " << "|" << "     " << "|" << "     |" << "     |" << endl;

		cout << clsUtil::Tabs(6) << clsUtil::Design('-', 31) << endl;

		cout << clsUtil::Tabs(6) << "|" << "     " << "|" << "     " << "|" << "     " << "|" << "     |" << endl;
		cout << clsUtil::Tabs(6) << "|" << "  4  " << "|" << "  5  " << "|" << "  6  " << "|" << "  -  |" << endl;
		cout << clsUtil::Tabs(6) << "|" << "     " << "|" << "     " << "|" << "     " << "|" << "     |" << endl;

		cout << clsUtil::Tabs(6) << clsUtil::Design('-', 25) << endl;

		cout << clsUtil::Tabs(6) << "|" << "     " << "|" << "     " << "|" << "     " << "|" << "     |" << endl;
		cout << clsUtil::Tabs(6) << "|" << "  7  " << "|" << "  8  " << "|" << "  9  " << "|" << "  x  |" << endl;
		cout << clsUtil::Tabs(6) << "|" << "     " << "|" << "     " << "|" << "     " << "|" << "     |" << endl;

		cout << clsUtil::Tabs(6) << clsUtil::Design('-', 25) << endl;

		cout << clsUtil::Tabs(6) << "|" << "     " << "|" << "     " << "|" << "     " << "|" << "     |" << endl;
		cout << clsUtil::Tabs(6) << "|" << "  (  " << "|" << "  0  " << "|" << "  )  " << "|" << "  /  |" << endl;
		cout << clsUtil::Tabs(6) << "|" << "     " << "|" << "     " << "|" << "     " << "|" << "     |" << endl;

		cout << clsUtil::Tabs(6) << clsUtil::Design('-', 25) << endl;
	}

protected:
	static void _DrawCalculatorInteface(string Title)
	{
		system("cls");

		cout << clsUtil::Tabs(4) << clsUtil::Design('_', 60) << endl << endl;
		cout << clsUtil::Tabs(7) << Title << endl;
		cout << clsUtil::Tabs(4) << clsUtil::Design('_', 60) << endl << endl << endl;

		_CalculatorStyle();

		cout << endl << endl;
	}

	static void _DrawResult(string expression, double result, string Title)
	{
		_DrawCalculatorInteface(Title);

		short length = expression.length();

		cout << clsUtil::Tabs(4) << clsUtil::Design('_', (length + 14)) << endl << endl;
		cout << clsUtil::Tabs(5) << expression << endl;
		cout << clsUtil::Tabs(4) << clsUtil::Design('_', (length + 14)) << endl << endl;

		cout << clsUtil::Tabs(4) << "=  " << result << endl << endl;
	}
};

