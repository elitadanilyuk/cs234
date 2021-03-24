//
//  main.cpp
//  ClassLab5.0
//
//  Created by Elita Danilyuk on 3/24/21.
//
//DISPLAY 11.8 Overloading << and >>
//Program to demonstrate the class Money.
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cctype>
using namespace std;

//Class for amounts of money in U.S. currency.
class Money
{
public:
    //TODO!!!!
    //Precondition: amount1 and amount2 have been given values.
    //Returns amount1 plus amount2.
    friend Money operator +(const Money& amount1, const Money& amount2);
        
    //Precondition: amount1 and amount2 have been given values.
    //Returns amount1 minus amount2.
    friend Money operator -(const Money& amount1, const Money& amount2);

    //Precondition: amount has been given a value.
    //Returns the negative of the value of amount.
    friend Money operator -(const Money& amount);

    //TODO!!!!
    //Precondition: amount1 and amount2 have been given values.
    //Returns a bool if amount1 and amount2 equal eachother.
    friend bool operator ==(const Money& amount1, const Money& amount2);

    // operator == ();
    
    Money(long dollars, int cents);
    
    Money(long dollars);

    Money();

    double get_value() const;
    void input(istream& ins);
    void output(ostream& outs);

    //Chanage to cinn (Don't need in_stream)
    friend istream& operator >>(istream& ins, Money& amount);
    friend ostream& operator <<(ostream& outs, const Money& amount);
    friend Money add(Money amount1, Money amount2);
    friend bool equal(Money amount1, Money amount2);
    
private:
    long all_cents;
};
int digit_to_int(char c);
//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int('3') returns 3.

int main()
{
    Money amount;
    ifstream in_stream;
    ofstream out_stream;

//    in_stream.open("infile.dat");
//    if (in_stream.fail())
//    {
//        cout << "Input file opening failed.\n";
//        exit(1);
//    }
//
//    out_stream.open("outfile.dat");
//    if (out_stream.fail())
//    {
//        cout << "Output file opening failed.\n";
//        exit(1);
//    }
//
//    in_stream >> amount;
//
//    cout << amount << " copied from the file infile.dat.\n";
//
//    out_stream << amount << " copied from the file infile.dat.\n";
//
//    cout << amount << " copied from the file infile.dat.\n";

    double amount1, amount2;
    
    // Get Inputs
    cout << "Please enter amount 1: ";
    cin >> amount1;

    cout << "Please enter amount 2: ";
    cin >> amount2;
    
    cout << "Added amounts: $" << (amount1 + amount2) << "\n";
    
    cout << "Subtracted amounts: S" << (amount1 - amount2) << "\n";
    
    
//    in_stream.close();
//    out_stream.close();

    return 0;
}

Money operator +(const Money& amount1, const Money& amount2){
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2){
    return (amount1.get_value() == amount2.get_value());
}

//Uses iostream, cctype, cstdlib:
istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point,
        digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.'
        || !isdigit(digit1) || !isdigit(digit2))
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

    amount.all_cents = dollars * 100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;


    return ins;
}

int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}

//Uses cstdlib and iostream:
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;
    outs << "\n";
    return outs;
}

Money add(Money amount1, Money amount2)
{
    Money temp;

    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool equal(Money amount1, Money amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0) //If one is negative and one is positive


    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100)
{
    //Body intentionally blank.
}

Money::Money() : all_cents(0)
{
    //Body intentionally blank.
}

//Precondition: The calling object has been given a value.
//Returns the amount of money recorded in the data of the calling object.
double Money::get_value() const
{
    return (all_cents * 0.01);
}

//Uses iostream, cctype, cstdlib:
//Precondition: If ins is a file input stream, then ins has already been
//connected to a file. An amount of money, including a dollar sign, has been
//entered in the input stream ins. Notation for negative amounts is -$100.00.
//Postcondition: The value of the calling object has been set to
//the amount of money read from the input stream ins.
void Money::input(istream& ins)
{
    char one_char, decimal_point,
        digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'

    ins >> dollars >> decimal_point >> digit1 >> digit2;

    if (one_char != '$' || decimal_point != '.'
        || !isdigit(digit1) || !isdigit(digit2))


    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

    all_cents = dollars * 100 + cents;
    if (negative)
        all_cents = -all_cents;
}

//Uses cstdlib and iostream:
//Precondition: If outs is a file output stream, then outs has already been
//connected to a file.
//Postcondition: A dollar sign and the amount of money recorded
//in the calling object have been sent to the output stream outs.
void Money::output(ostream& outs)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';

    if (cents < 10)
        outs << '0';
    outs << cents;
}
