#pragma once

#include "clsScreen.h"
#include "clsMathErrors.h"
#include "clsConvertMathExpression.h"
#include "clsCalculatePostfix.h"

#include "clsInputValidate.h"

class clsCalculatorManager : protected clsScreen
{
private:
	static string _ReadMathExpression()
	{
		bool isTrue;
		string Expression;

		do
		{
			Expression = clsInputValidate::ReadString(clsUtil::Tabs(4) + "Enter a mathematic operation (Using Table Above): ");

			if (!(isTrue = clsMathErrors::CheckErrorsInTheOperation(Expression)))
				cout << "Wrong Operation\nTry Again\n\n";

		} while (!isTrue);

		return Expression;
	}

	static void _Calculate()
	{
		string Title = "Calculator";

		_DrawCalculatorInteface(Title);

		clsCalculator Calc;

		Calc.infix = _ReadMathExpression();

		Calc.postfix = clsConvertMathExpression::ConvertInfixToPostfix(Calc.infix);

		Calc.result = clsCalculatePostfix::CalculateThePostfix(Calc.postfix);

		_DrawResult(Calc.infix, Calc.result, Title);
	}

public:
	static void StartTheCalculator()
	{
		do
		{
			_Calculate();

		} while (clsUtil::isYes(clsUtil::Tabs(4) + "Do you wanna do more operations (Y/N): "));
	}
};

