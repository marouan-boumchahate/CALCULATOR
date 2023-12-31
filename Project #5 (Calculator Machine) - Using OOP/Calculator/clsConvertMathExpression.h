#pragma once

#include "clsCalculator.h"

class clsConvertMathExpression
{
private:
    static void _ConvertInfixToPostfix(vector<double>* operators, string InfixExpression, string& Postfix_Expression)
    {
        for (int i = 0; i < InfixExpression.length(); i++)
        {
            if ((i == 0 && InfixExpression[i] == '-') || (InfixExpression[i] == '-' && InfixExpression[i - 1] == '(') || isdigit(InfixExpression[i]))
            {
                do
                {
                    Postfix_Expression.push_back(InfixExpression[i]);
                    i++;
                } while (isdigit(InfixExpression[i]) || InfixExpression[i] == '.');

                Postfix_Expression.push_back('|');
            }

            if (InfixExpression[i] == '(')
            {
                (*operators).push_back(InfixExpression[i]);
                continue;
            }

            if (InfixExpression[i] == '+' || InfixExpression[i] == '-')
            {
                while (!((*operators).empty()) && ((*operators).back() == 'x' || (*operators).back() == '/' || (*operators).back() == '+' || (*operators).back() == '-'))
                {
                    Postfix_Expression.push_back((*operators).back());
                    Postfix_Expression.push_back('|');
                    (*operators).pop_back();
                }

                (*operators).push_back(InfixExpression[i]);
                continue;
            }

            if (InfixExpression[i] == 'x' || InfixExpression[i] == '/')
            {
                while (!((*operators).empty()) && ((*operators).back() == 'x' || (*operators).back() == '/'))
                {
                    Postfix_Expression.push_back((*operators).back());
                    Postfix_Expression.push_back('|');
                    (*operators).pop_back();
                }

                (*operators).push_back(InfixExpression[i]);
                continue;
            }

            if (InfixExpression[i] == ')')
            {
                while ((*operators).back() != '(')
                {
                    Postfix_Expression.push_back((*operators).back());
                    Postfix_Expression.push_back('|');
                    (*operators).pop_back();
                }

                (*operators).pop_back(); // To remove the open parenthis
            }

        }
    }

    static void _PushRestOperators(vector<double>* operators, string& Postfix_Expression)
    {
        while (!(*operators).empty())
        {
            Postfix_Expression.push_back((*operators).back());
            Postfix_Expression.push_back('|');
            (*operators).pop_back();
        }
    }

public:
    static string ConvertInfixToPostfix(string InfixExpression)
    {
        vector<double>* operators = new vector<double>;
        string Postfix_Expression;

        Postfix_Expression.push_back('|');

        _ConvertInfixToPostfix(operators, InfixExpression, Postfix_Expression);

        _PushRestOperators(operators, Postfix_Expression);

        delete operators;

        return Postfix_Expression;
    }
};

