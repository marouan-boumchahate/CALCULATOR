#pragma once
#include "clsCalculator.h"

class clsCalculatePostfix
{
private:
    static void _SplitStringIntoOptAndOpd(vector<double>* opd, vector<char>* opt, string Postfix)
    {
        string* Part = new string;

        for (int i = 0; i < Postfix.length() - 1; i++)
        {
            if (Postfix[i] == '|')
            {
                i++;
                while (Postfix[i] != '|')
                {
                    Part->push_back(Postfix[i]);
                    i++;
                }

                i--;
                if (Part->size() > 1)
                {
                    (*opd).push_back(stod(*Part));
                    (*opt).push_back('0');
                }
                else
                {
                    if (Postfix[i] == 'x' || Postfix[i] == '+' || Postfix[i] == '-' || Postfix[i] == '/')
                    {
                        (*opt).push_back(Postfix[i]);
                        (*opd).push_back(0);
                    }
                    else
                    {
                        (*opd).push_back(stod(*Part));
                        (*opt).push_back('0');
                    }
                }
            }

            Part->clear();
        }

        delete Part;
    }

    static double _CalculateTwoOperands(double operand_1, double operand_2, char op)
    {
        double Result = 0;

        switch (op)
        {
        case 'x':
            return(operand_1 * operand_2);

        case '/':
            return(operand_1 / operand_2);

        case '+':
            return(operand_1 + operand_2);

        case '-':
            return(operand_1 - operand_2);
        }
    }

    static double _PerformingCalculation(vector<double>* opd, vector<char>* opt)
    {
        double Result = 0;
        int i = 0;

        while (opt->at(i) != '=')
        {
            if (opt->at(i) != '0')
            {
                // Calculate part by part
                Result = _CalculateTwoOperands(opd->at(i - 2), opd->at(i - 1), opt->at(i));

                // Add Result as an operand
                opd->insert(opd->begin() + (i + 1), Result);
                opt->insert(opt->begin() + (i + 1), '0');

                // Remove data that I have  been done with
                opt->erase(opt->begin() + (i - 2), opt->begin() + (i + 1));
                opd->erase(opd->begin() + (i - 2), opd->begin() + (i + 1));

                i = 0;
                continue;
            }

            i++;
        }

        return Result;
    }

public:
    static double CalculateThePostfix(string Postfix)
    {
        double Result = 0;

        vector<double>* operands = new vector<double>;
        vector<char>* operators = new vector<char>;

        // Take the random data from postfix expression and seperate them to operators and operands
        _SplitStringIntoOptAndOpd(operands, operators, Postfix);

        // Add "=" at the final of the operators
        operands->push_back(0);
        operators->push_back('=');

        // Start Calculating DATA I've seperated
        Result = _PerformingCalculation(operands, operators);

        delete operands;
        delete operators;

        return Result;
    }
};

