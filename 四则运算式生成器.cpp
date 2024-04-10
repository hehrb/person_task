#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// ����ָ����Χ�ڵ������
int generateRand(int minVal, int maxVal) 
{
    return rand() % (maxVal - minVal + 1) + minVal;
}

// ���ɼӷ�����ʽ
string generateAdd() 
{
    int num1 = 0, num2 = 0;
    do
    {
        num1 = generateRand(1, 20);
        num2 = generateRand(1, 20);
    } while (num1 + num2 > 20);
    
    return to_string(num1) + " + " + to_string(num2);
}

// ���ɼ�������ʽ
string generateSub() 
{
    int num1 = 0, num2 = 0;
    do
    {
        num1 = generateRand(1, 20);
        num2 = generateRand(1, 20);
    } while (num1 - num2 < 0 || num1 - num2 > 20);

    return to_string(num1) + " - " + to_string(num2);
}

// ������������
char generateOperator(int admitOperator)
{
    char operators[] = { '+', '-', '*', '/' };
    return operators[generateRand(0, admitOperator)];
}

// ���ɶ��꼶�������ʽ
string generateTwoMixed(int numOperator, int maxVal)
{
    string expression;
    int result = 0;

    for (int i = 0; i < numOperator; ++i)
    {
        int num = generateRand(0, maxVal);
        char op;

        if (i == 0)
        {
            result = num;
            expression += to_string(num);
        }
        else
        {
            if (result + num > 50)
            {
                op = '-';
                result -= num;
            }
            else
            {
                op = '+';
                result += num;
            }

            expression += " " + string(1, op) + " " + to_string(num);
        }
    }

    return expression;
}

// �������꼶�������ʽ
string generateThreeMixed(int numOperator, int admitOperator, int maxVal) 
{
    string expression;
    for (int i = 0; i < numOperator; ++i)
    {
        if (i > 0) 
        {
            char op = generateOperator(admitOperator);
            expression += " " + string(1, op) + " ";
        }
        expression += to_string(generateRand(0, maxVal));
    }

    return expression;
}

// �����ġ��塢���꼶�������ʽ
string generateFourMixed(int numOperator, int admitOperator, int maxVal) {
    string expression;
    int result = 0;
    bool hasNegativeResult = false;

    for (int i = 0; i < numOperator; ++i) 
    {
        int num = generateRand(0, maxVal);
        char op = generateOperator(admitOperator);

        if (i > 0) 
        {
            expression += " " + string(1, op) + " ";
        }
        expression += to_string(num);

        if (op == '+')
            result += num;
        else if (op == '-')
            result -= num;
        else if (op == '*')
            result *= num;
        else if (num != 0)
            result /= num;

        if (result < 0)
            hasNegativeResult = true;

        // ����������
        if (generateRand(0, 1) == 1) 
            expression = "(" + expression + ")";
    }

    // ������Ϊ�������������ɻ������ʽ
    if (hasNegativeResult)
        return generateFourMixed(numOperator, admitOperator, maxVal);

    return expression;
}

// ������������ʽ
string generateExpression(int level) 
{
    switch (level) 
    {
    case 1:
        if (generateRand(0, 1))
            return generateAdd();
        else
            return generateSub();
    case 2:
        return generateTwoMixed(2, 50);
    case 3:
        return generateThreeMixed(3, 2, 1000);
    case 4:
    case 5:
    case 6:
        return generateFourMixed(3, 3, INT_MAX);
    default:
        return "Not Exist This Grade!";
    }
}

int main() 
{
    srand((unsigned)time(nullptr));

    int grade, num;
    cin >> grade;
    if (grade > 6)
    {
        cout << "Not Exist This Grade!" << endl;
        return 1;
    }
    cin >> num;

    cout << "���ɵ�����������Ŀ���£�" << endl;
    for (int i = 0; i < num; ++i) 
    {
        cout << generateExpression(grade) << endl;
    }

    return 0;
}