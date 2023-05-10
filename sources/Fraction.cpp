#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Fraction.hpp"
#include <stdio.h>
using namespace std;
namespace ariel
{

    Fraction::Fraction()
    {
        this->denominator = 1;
        this->numerator = 0;
    }

    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator)
    {

        if (denominator == 0)
        {
            throw invalid_argument("error - canot divide by zero");
        }
      
        this->reduce();
    }
        void Fraction::reduce()
    {
         int x = gcd(this->numerator,this->denominator);
        this->numerator/= x;
        this->denominator/= x;
        if(this->denominator<0){
            this->numerator *= -1;
            this->denominator *= -1;
    }
    }
    Fraction::Fraction(float number) : numerator(number * 1000), denominator(1000)
    {
        this->reduce();
    }

    Fraction float_to_frac(float num)
    {
        return Fraction(num * 1000, 1000);
    }

    int gcd(int numerator, int denominator)
    {
        while (denominator != 0)
        {
            int temp = denominator;
            denominator = numerator % denominator;
            numerator = temp;
        }
        return numerator;
    }


    Fraction operator+(const Fraction &frack1, const Fraction &frack2)
    {


       long checkNum = (long)(frack1.getNumerator() * frack2.getDenominator() )+ (long)(frack1.getDenominator() * frack2.getNumerator());
        if (checkNum > numeric_limits<int>::max() ||checkNum < numeric_limits<int>::min())
        {
            throw overflow_error("overflow error");
        }

        int result_numerator;
        int result_denominator;
        int l;

        if (frack1.getDenominator() == frack2.getDenominator())
        {
            result_numerator = frack1.getNumerator() + frack2.getNumerator();
            return Fraction(result_numerator, frack1.getDenominator());
        }
        else
        {
            result_numerator = (frack1.getNumerator()) * (frack2.getDenominator()) + (frack2.getNumerator()) * (frack1.getDenominator());
            result_denominator = frack1.getDenominator() * frack2.getDenominator();
            l = gcd(result_numerator, result_denominator);
        }
        return Fraction(result_numerator / l, result_denominator / l);
    }

    Fraction operator-(const Fraction &frack1, const Fraction &frack2)
    {

       

    long check = (long)(frack1.getNumerator() * frack2.getDenominator() )- (frack1.getDenominator() * frack2.getNumerator());;
        if (check > numeric_limits<int>::max())
        {
            throw overflow_error("overflow error");
        }

        int result_numerator;
        int result_denominator;
        int l;
        if (frack1.getDenominator() == frack2.getDenominator())
        {
            result_numerator = frack1.getNumerator() - frack2.getNumerator();
            return Fraction(result_numerator, frack1.getDenominator());
        }
        else
        {
            result_numerator = (frack1.getNumerator()) * (frack2.getDenominator()) - (frack2.getNumerator()) * (frack1.getDenominator());
            result_denominator = frack1.getDenominator() * frack2.getDenominator();
            l = gcd(result_numerator, result_denominator);
        }

        return Fraction(result_numerator / l, result_denominator / l);
    }

    Fraction operator*(const Fraction &frack1, const Fraction &frack2)
    {
        int result_numerator;
        int result_denominator;
        int l;
     
        long checkNum = ((long)frack1.getNumerator() * frack2.getNumerator());
        long checkDen = ((long)frack1.getDenominator() * frack2.getDenominator());
        if (checkNum > numeric_limits<int>::max() || checkDen > numeric_limits<int>::max())
        {
            throw overflow_error("overflow error");
        }

        result_denominator = frack1.getDenominator() * frack2.getDenominator();
        result_numerator = frack1.getNumerator() * frack2.getNumerator();
        l = gcd(result_numerator, result_denominator);
        return Fraction(result_numerator / l, result_denominator / l);
    }
    Fraction operator/(const Fraction &frack1, const Fraction &frack2)
    {
        int result_numerator;
        int result_denominator;
        int l;
       
        long checkNum = ((long)frack1.getNumerator() * frack2.getDenominator());
        long checkDen = ((long)frack1.getDenominator() *  frack2.getDenominator());
        if (checkNum > numeric_limits<int>::max() || checkDen > numeric_limits<int>::max())
        {
            throw overflow_error("overflow error");
        } 
        result_numerator = frack1.getNumerator() * frack2.getDenominator();
        result_denominator = frack1.getDenominator() * frack2.getNumerator();
        if ((result_denominator) == 0)
        {
            throw runtime_error("error - canot divide by zero");
        }
        
        l = gcd(result_numerator, result_denominator);
        return Fraction(result_numerator / l, result_denominator / l);
    }

    Fraction operator+(const Fraction &frack, const float num)
    {
        Fraction f = float_to_frac(num);
        return operator+(frack, f);
    }

    Fraction operator-(const Fraction &frack, const float num)
    {
        Fraction f = float_to_frac(num);
        return operator-(frack, f);
    }
    Fraction operator*(const Fraction &frack, const float num)
    {
        Fraction f = float_to_frac(num);
        return operator*(frack, f);
    }
    Fraction operator/(const Fraction &frack, const float num)
    {
        Fraction f = float_to_frac(num);
        return operator/(frack, f);
    }

    Fraction operator+(float num, const Fraction &frack)
    {
        Fraction f = float_to_frac(num);
        return operator+(f, frack);
    }
    Fraction operator-(float num, const Fraction &frack)
    {
        Fraction f = float_to_frac(num);
        return operator-(f, frack);
    }
    Fraction operator*(float num, const Fraction &frack)
    {
        Fraction f = float_to_frac(num);
        return operator*(f, frack);
    }
    Fraction operator/(float num, const Fraction &frack)
    {
        Fraction f = float_to_frac(num);
        return operator/(f, frack);
    }

    Fraction const &Fraction::operator++()
    { //++i
        Fraction f(1, 1);
        *this = operator+(*this, f);
        return *this;
    }

    Fraction Fraction::operator++(int)
    { // i++ // beacuse of lvalue
        Fraction f(1, 1);
        Fraction frack = *this;
        *this = operator+(*this, f);
        return frack;
    }

    Fraction const &Fraction::operator--()
    { //--i // beacuse of lvalue
        Fraction f(1, 1);
        *this = operator-(*this, f);
        return *this;
    }
    Fraction Fraction::operator--(int)
    { // i--
        Fraction f(1, 1);
        Fraction frack = *this;
        *this = operator-(*this, f);
        return frack;
    }

    bool operator==(const Fraction &frack1, const Fraction &frack2)
    {
        int l;
        int ln;
        l = gcd(frack1.getNumerator(), frack1.getDenominator());
        ln = gcd(frack2.getNumerator(), frack2.getDenominator());
        if (frack1.getNumerator() / l == frack2.getNumerator() / ln && frack1.getDenominator() / l == frack2.getDenominator() / ln)
        {
            return true;
        }
        return false;
    }

    bool operator>(const Fraction &frack1, const Fraction &frack2)
    {
        int frack1_mone;
        int frack2_mone;
        if (frack1.getDenominator() == frack2.getDenominator() && frack1.getNumerator() > frack2.getNumerator())
            return true;
        else
        {
            frack1_mone = frack1.getNumerator() * frack2.getDenominator();
            frack2_mone = frack2.getNumerator() * frack1.getDenominator();
            if (frack1_mone > frack2_mone)
            {
                return true;
            }
        }
        return false;
    }
    bool operator<(const Fraction &frack1, const Fraction &frack2)
    {
        int frack1_mone;
        int frack2_mone;
        if (frack1.getDenominator() == frack2.getDenominator() && frack1.getNumerator() < frack2.getNumerator())
        {
            return true;
        }
        else
        {
            frack1_mone = frack1.getNumerator() * frack2.getDenominator();
            frack2_mone = frack2.getNumerator() * frack1.getDenominator();
            if (frack1_mone < frack2_mone)
            {
                return true;
            }
        }
        return false;
        ;
    }

    bool operator>=(const Fraction &frack1, const Fraction &frack2)
    {
        int frack1_mone;
        int frack2_mone;
        if (frack1.getDenominator() == frack2.getDenominator() && frack1.getNumerator() >= frack2.getNumerator())
            return true;
        else
        {
            frack1_mone = frack1.getNumerator() * frack2.getDenominator();
            frack2_mone = frack2.getNumerator() * frack1.getDenominator();
            if (frack1_mone >= frack2_mone)
            {
                return true;
            }
        }
        return false;
    }
    bool operator<=(const Fraction &frack1, const Fraction &frack2)
    {
        int frack1_mone;
        int frack2_mone;

        if (frack1.getDenominator() == frack2.getDenominator() && frack1.getNumerator() <= frack2.getNumerator())
            return true;
        else
        {
            frack1_mone = frack1.getNumerator() * frack2.getDenominator();
            frack2_mone = frack2.getNumerator() * frack1.getDenominator();
            if (frack1_mone <= frack2_mone)
            {
                return true;
            }
        }

        return false;
        ;
    }

    bool operator==(const Fraction &frack, float num)
    {

        Fraction f = float_to_frac(num);
        int l = gcd(f.getNumerator(), f.getDenominator());
        int g = gcd(f.getNumerator(), f.getDenominator());

        return operator==(frack / l, f / g);
    }

    bool operator>(const Fraction &frack, float num)
    {
        Fraction f = float_to_frac(num);
        return operator>(frack, f);
    }
    bool operator<(const Fraction &frack, float num)
    {
        Fraction f = float_to_frac(num);
        return operator<(frack, f);
    }
    bool operator>=(const Fraction &frack, float num)
    {
        Fraction f = float_to_frac(num);
        return operator>=(frack, f);
    }
    bool operator<=(const Fraction &frack, float num)
    {
        Fraction f = float_to_frac(num);
        return operator<=(frack, f);
    }

    bool operator==(float num, const Fraction &frack)
    {
        Fraction f = float_to_frac(num);

        int l = gcd(f.getNumerator(), frack.getDenominator());
        int g = gcd(f.getNumerator(), frack.getDenominator());

        return operator==(frack / l, f / g);
    }

    bool operator>(float num, const Fraction &frack)
    {
        Fraction f = float_to_frac(num);
        return operator>(f, frack);
    }
    bool operator<(float num, const Fraction &frack)
    {
        Fraction f = float_to_frac(num);
        return operator<(f, frack);
    }
    bool operator>=(float num, const Fraction &frack)
    {
        Fraction f = float_to_frac(num);
        return operator>=(f, frack);
    }
    bool operator<=(float num, const Fraction &frack)
    {
        Fraction f = float_to_frac(num);
        return operator<=(f, frack);
    }

    ostream &operator<<(ostream &output, const Fraction &frac)
    {
        return (output << frac.getNumerator()<< "/" << frac.getDenominator());
    }
 
    std::istream &operator>>(std::istream &stream, Fraction &frac)
    {
        int numer, denomer;
        stream >> numer >> denomer;
        if (stream.fail())
        {
            throw runtime_error("error with reading string");
        }
        if (denomer == 0)
        {
            throw runtime_error("invalid input");
        }
        Fraction temp(numer, denomer);
        frac.numerator = temp.numerator;
        frac.denominator = temp.denominator;
        return stream;
    }
}
