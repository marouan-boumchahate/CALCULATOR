#pragma once

#include <vector>
#include "clsCalculator.h"

class clsMathErrors : public clsCalculator
{
private:
    static bool _isThereOnlyMathCharacters(string operation)
    {
        for (int i = 0; i < operation.length(); i++)
        {
            if (operation[i] != '+' && operation[i] != '-' && operation[i] != 'x' && operation[i] != '/' && operation[i] != ')' && operation[i] != '(' && operation[i] != '.')
            {
                if (!isdigit(operation[i]))
                    return false;
            }
        }

        return true;
    }

    static bool _isFirstCharacterCorrect(string operation)
    {
        if (operation[0] != '(' && operation[0] != '-')
        {
            if (!isdigit(operation[0]))
                return false;
        }

        return true;
    }

    static bool _isLastCharacterCorrect(string operation)
    {
        if (operation[operation.length() - 1] != ')')
        {
            if (!isdigit(operation[operation.length() - 1]))
                return false;
        }

        return true;
    }

    static bool _isTwoOperatorsTogether(string operation)
    {
        for (int i = 0; i < operation.length() - 1; i++)
        {
            if (operation[i] == '+' || operation[i] == '-' || operation[i] == 'x' || operation[i] == '/' || operation[i] == '.')
                if (operation[i + 1] == '+' || operation[i + 1] == '-' || operation[i + 1] == 'x' || operation[i + 1] == '/' || operation[i + 1] == '.' || operation[i + 1] == ')')
                    return false;

            if (operation[i] == '(')
                if (operation[i + 1] == '+' || operation[i + 1] == 'x' || operation[i + 1] == '/' || operation[i + 1] == '.' || operation[i + 1] == ')')
                    return false;

            if (operation[i] == ')')
            {
                if ((operation[i + 1] != ')' && isdigit(operation[i + 1])) || (operation[i - 1] != ')' && !isdigit(operation[i - 1])))
                    return false;
            }

            if (operation[i] == ')' && i != operation.size() - 1)
                if (operation[i] == ')' && operation[i + 1] == '(')
                    operation.insert(operation.begin() + i + 1, 'x');
        }

        return true;
    }

    static bool _isNumberOfOpenAndCloseParathensisEqual(string operation)
    {
        vector<char> parenthesis;

        for (int i = 0; i < operation.length(); i++)
        {
            if (operation[i] == '(')
                parenthesis.push_back('(');
            if (operation[i] == ')')
                if (!parenthesis.empty())
                    parenthesis.pop_back();
                else
                    parenthesis.push_back('(');
        }

        if (!parenthesis.empty())
            return false;

        parenthesis.clear();

        return true;
    }

public:
	static bool CheckErrorsInTheOperation(string operation)
    {
        return (_isThereOnlyMathCharacters(operation) && _isFirstCharacterCorrect(operation) &&
            _isLastCharacterCorrect(operation) && _isTwoOperatorsTogether(operation) &&
            _isNumberOfOpenAndCloseParathensisEqual(operation)
            );
    }
};

