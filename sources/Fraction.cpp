#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Fraction.hpp"
#include <stdio.h>
using namespace std;
namespace ariel{

    Fraction::Fraction(){
        this->denominator=1;
        this->numerator=0;
    }

    Fraction::Fraction(int numerator, int denominator):numerator(numerator) , denominator(denominator)
    {
        if (denominator == 0)
        {
            throw invalid_argument("error - canot divide by zero");
        }

        if(numerator>0 && denominator<0)
        {
           this->setNumerator(numerator*-1);
           this->setDenominator(denominator*-1);
        }

        if(numerator<0 && denominator<0){
              this->setNumerator(numerator*-1);
              this->setDenominator(denominator*-1);
        }
        }

    Fraction::Fraction(float number):numerator(number*1000),denominator(1000){
    }

        Fraction float_to_frac(float num){
        return Fraction(num*1000,1000);
       }
   
        int gcd(int numerator, int denominator) {
        while (denominator != 0) {
        int temp = denominator;
        denominator = numerator % denominator;
        numerator = temp;
        }
         return numerator;
        }
    //       void exeption(int a,int b,char c)
    // {
    //     switch(c) {
    //     case '+':
    //         if((a > 0 && b > 0 && (a+b < 0)) || (a < 0 && b < 0 && (a+b > 0)))
    //         {
    //             throw overflow_error("overflow error");
    //         }
    //         break;
    //     case '*':
    //         if(a != 0 && b != 0)
    //         {
    //             int temp = a*b;
    //             if((a != temp / b) || (b != temp / a))
    //             {
    //                 throw overflow_error("overflow error");
    //             }
    //         }
    //         break;
    //     }
    //     }

        Fraction operator+(const Fraction &frack1, const Fraction &frack2){
        int result_numerator;
        int result_denominator;
        int l;
         if (frack1.getDenominator()==frack2.getDenominator()){
            result_numerator= frack1.getNumerator()+frack2.getNumerator();
            return Fraction(result_numerator,frack1.getDenominator());
        }
         else{
            result_numerator = (frack1.getNumerator())*(frack2.getDenominator()) + (frack2.getNumerator())*(frack1.getDenominator());
            result_denominator = frack1.getDenominator()*frack2.getDenominator();
            l = gcd(result_numerator,result_denominator);
        }
          return Fraction(result_numerator/l,result_denominator/l);
        }
        

        Fraction operator-(const Fraction &frack1,const Fraction &frack2){
        int result_numerator;
        int result_denominator;
        int l;
        if (frack1.getDenominator()==frack2.getDenominator()){
            result_numerator= frack1.getNumerator()-frack2.getNumerator();
            return Fraction(result_numerator,frack1.getDenominator());
        }
        else{
            result_numerator = (frack1.getNumerator())*(frack2.getDenominator()) - (frack2.getNumerator())*(frack1.getDenominator());
            result_denominator = frack1.getDenominator()*frack2.getDenominator();
            l = gcd(result_numerator,result_denominator);
        }
        
         return Fraction(result_numerator/l,result_denominator/l);
        }
         
        Fraction operator*(const Fraction &frack1,const Fraction &frack2){
        int result_numerator;
        int result_denominator;
        int l;
        result_denominator = frack1.getDenominator()*frack2.getDenominator();
        result_numerator = frack1.getNumerator()*frack2.getNumerator();
        l = gcd(result_numerator,result_denominator);
         return Fraction(result_numerator/l,result_denominator/l);
        }
        Fraction operator/(const Fraction &frack1,const Fraction &frack2){
        int result_numerator;
        int result_denominator;
        int l;
        result_numerator = frack1.getNumerator()*frack2.getDenominator();
        result_denominator = frack1.getDenominator()*frack2.getNumerator();
        if((result_denominator)==0){
            throw runtime_error("error - canot divide by zero");
        }
        l = gcd(result_numerator,result_denominator);
        return Fraction(result_numerator/l,result_denominator/l);
        }

        Fraction operator+(const Fraction &frack,const float num){
        Fraction f = float_to_frac(num);
        return operator+(frack,f);
        }

        Fraction operator-(const Fraction &frack,const float num){
        Fraction f = float_to_frac(num);
        return operator-(frack,f);
        }
        Fraction operator*(const Fraction &frack,const float num){
        Fraction f = float_to_frac(num);
         return operator*(frack,f);
        }
        Fraction operator/(const Fraction &frack,const float num){
        Fraction f = float_to_frac(num);
         return operator/(frack,f);
        }

        Fraction operator+( float num, const Fraction &frack){
        Fraction f = float_to_frac(num);
        return operator+(f,frack);
        }
        Fraction operator-( float num, const Fraction &frack){
        Fraction f = float_to_frac(num);
        return operator-(f,frack); 
        }
        Fraction operator*( float num, const Fraction &frack){
        Fraction f = float_to_frac(num);
        return operator*(f,frack);
        }
        Fraction operator/( float num, const Fraction &frack){
        Fraction f = float_to_frac(num);
        return operator/(f,frack);
        }

        Fraction const & Fraction::operator++(){//++i
        Fraction f(1,1);
        *this = operator+(*this,f);
         return *this;
        }

        Fraction Fraction::operator++(int){//i++ // beacuse of lvalue
        Fraction f(1,1);
        Fraction frack = *this;
        *this = operator+(*this,f);
            return frack;
        } 
        
        Fraction const & Fraction::operator--(){//--i // beacuse of lvalue
        Fraction f(1,1);
        *this = operator-(*this,f);
         return *this;
        } 
        Fraction Fraction::operator--(int){//i--
        Fraction f(1,1);
        Fraction frack = *this;
        *this = operator-(*this,f);
            return frack;
        } 

        bool operator==(const Fraction &frack1, const Fraction &frack2){
       
        int l;
        int ln;
        l = gcd(frack1.getNumerator(),frack1.getDenominator());
        ln = gcd(frack2.getNumerator(),frack2.getDenominator());
            if(frack1.getNumerator()/l==frack2.getNumerator()/ln && frack1.getDenominator()/l==frack2.getDenominator()/ln){
            return true;
            }
            return false;
        }

        bool operator>(const Fraction &frack1, const Fraction &frack2){
            int frack1_mone;
            int frack2_mone;
           // if (operator==(frack1,frack2)==false){
                if(frack1.getDenominator()==frack2.getDenominator() && frack1.getNumerator()> frack2.getNumerator())
                    return true;
                else{
                frack1_mone = frack1.getNumerator()*frack2.getDenominator();
                frack2_mone = frack2.getNumerator()*frack1.getDenominator();
                if(frack1_mone>frack2_mone){
                    return true;
                }
                }
           // }
            return false;
        }
        bool operator<(const Fraction &frack1, const Fraction &frack2){
            int frack1_mone;
            int frack2_mone;
            //if (operator==(frack1,frack2)==false){
                if(frack1.getDenominator()==frack2.getDenominator() && frack1.getNumerator()< frack2.getNumerator()){
                    return true;
                }
                else{
                frack1_mone = frack1.getNumerator()*frack2.getDenominator();
                frack2_mone = frack2.getNumerator()*frack1.getDenominator();
                if(frack1_mone<frack2_mone){
                    return true;
                }

                }
           // }
            return false;;
        }

        bool operator>=(const Fraction &frack1, const Fraction &frack2){
            int frack1_mone;
            int frack2_mone;
                if(frack1.getDenominator()==frack2.getDenominator() && frack1.getNumerator()>= frack2.getNumerator())
                    return true;
                else{
                frack1_mone = frack1.getNumerator()*frack2.getDenominator();
                frack2_mone = frack2.getNumerator()*frack1.getDenominator();
                if(frack1_mone>=frack2_mone){
                    return true;
                }
                }
            return false;
                }
        bool operator<=(const Fraction &frack1, const Fraction &frack2){
               int frack1_mone;
            int frack2_mone;
       
                if(frack1.getDenominator()==frack2.getDenominator() && frack1.getNumerator()<= frack2.getNumerator())
                    return true;
                else{
                frack1_mone = frack1.getNumerator()*frack2.getDenominator();
                frack2_mone = frack2.getNumerator()*frack1.getDenominator();
                if(frack1_mone<=frack2_mone){
                    return true;
                }
                }
          
            return false;;
        }
      
        bool operator==(const Fraction &frack, float num){
        
        Fraction f = float_to_frac(num);
        int l = gcd(f.getNumerator(),f.getDenominator());
        int g = gcd(f.getNumerator(),f.getDenominator());

        return operator==(frack/l,f/g);
        }

        bool operator>(const Fraction &frack, float num){
        Fraction f = float_to_frac(num);
        return operator>(frack,f);
        }        
        bool operator<(const Fraction &frack, float num){
         Fraction f = float_to_frac(num);
        return operator<(frack,f);
        }  
        bool operator>=(const Fraction &frack, float num){
        Fraction f = float_to_frac(num);
        return operator>=(frack,f);
        }  
        bool operator<=(const Fraction &frack, float num){
        Fraction f = float_to_frac(num);
        return operator<=(frack,f);
        }  

        bool operator==(float num, const Fraction &frack){
        Fraction f = float_to_frac(num);

        int l = gcd(f.getNumerator(),frack.getDenominator());
        int g = gcd(f.getNumerator(),frack.getDenominator());

        return operator==(frack/l,f/g);
        }

        bool operator>(float num, const Fraction &frack){
        Fraction f = float_to_frac(num);
        return operator>(f,frack);
        }        
        bool operator<(float num, const Fraction &frack){
        Fraction f = float_to_frac(num);
        return operator<(f,frack);
        } 
        bool operator>=(float num, const Fraction &frack){
       Fraction f = float_to_frac(num);
        return operator>=(f,frack);
        } 
        bool operator<=(float num, const Fraction &frack){
         Fraction f = float_to_frac(num);
        return operator<=(f,frack);
        } 

     // The << operator to print a fraction
    std::ostream &operator<<(std::ostream &stream, const Fraction &frac){
        return stream << frac.getNumerator() << '/' << frac.getDenominator();
    }

    // The >> operator to read a fraction 
    std::istream& operator>>(std::istream& stream, Fraction& frac){
    int numer,denomer;
    stream >> numer >> denomer;

    if(stream.fail()){
        throw runtime_error("error with reading string");
    }
    if(denomer==0){
        throw runtime_error("invalid input");
    }
     Fraction temp(numer,denomer);
        frac.numerator = temp.numerator;
        frac.denominator = temp.denominator;
    return stream;

    }
}
