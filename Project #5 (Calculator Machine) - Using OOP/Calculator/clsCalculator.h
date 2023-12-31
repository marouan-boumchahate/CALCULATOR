#pragma once

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class clsCalculator
{
private:
	string _InfixMathExpression = "";
	string _PostfixMathExpression = "";
	double _Result = 0;

public:
	// Setters
	void SetInfixMathExpression(string InfixMathExpression)
	{
		_InfixMathExpression = InfixMathExpression;
	}
	void SetPostfixMathExpression(string PostfixMathExpression)
	{
		_PostfixMathExpression = PostfixMathExpression;
	}
	void SetResult(double Result)
	{
		_Result = Result;
	}

	// Getters
	string GetInfixMathExpression()
	{
		return _InfixMathExpression;
	}
	string GetPostfixMathExpression()
	{
		return _PostfixMathExpression;
	}
	double GetResult()
	{
		return _Result;
	}

	// Using Equal
	__declspec(property(get = GetInfixMathExpression, put = SetInfixMathExpression)) string infix;
	__declspec(property(get = GetPostfixMathExpression, put = SetPostfixMathExpression)) string postfix;
	__declspec(property(get = GetResult, put = SetResult)) double result;
};

