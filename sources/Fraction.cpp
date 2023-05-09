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
    Fraction::Fraction(int numerator, int denominator)
    {
        if (denominator == 0)
        {
            throw __EXCEPTION__("error - canot divide by zero");
        }
        this->numerator = numerator;
        this->denominator = denominator;
    }
   
    void Fraction::gcd(){}

        Fraction operator+(const Fraction &frack1,const Fraction &frack2){
        Fraction fraction1;
         return fraction1;
        }
         Fraction operator+(const Fraction &frack,const float num){
         Fraction fraction1;
         return fraction1;
         }
         Fraction operator+( float num, const Fraction &frack){
         Fraction fraction1;
         return fraction1;
        }

        Fraction operator-(const Fraction &frack1,const Fraction &frack2){
        Fraction fraction1;
         return fraction1;
         }
        Fraction operator*(const Fraction &frack1,const Fraction &frack2){
         Fraction fraction1;
         return fraction1;
        }
        Fraction operator/(const Fraction &frack1,const Fraction &frack2){
         Fraction fraction1;
         return fraction1;
        }
       
        Fraction operator-(const Fraction &frack,const float num){
         Fraction fraction1;
         return fraction1;
        }
        Fraction operator*(const Fraction &frack,const float num){
         Fraction fraction1;
         return fraction1;
        }
        Fraction operator/(const Fraction &frack,const float num){
         Fraction fraction1;
         return fraction1;
        }

       
        Fraction operator-( float num, const Fraction &frack){
         Fraction fraction1;
         return fraction1;
        }
        Fraction operator*( float num, const Fraction &frack){
         Fraction fraction1;
         return fraction1;
        }
        Fraction operator/( float num, const Fraction &frack){
         Fraction fraction1;
         return fraction1;
        }

        Fraction& Fraction::operator++(){
            return *this;
        }
        Fraction Fraction::operator++(int){
            return Fraction(1,2);
        } 
        Fraction& Fraction::operator--(){
            return *this;
        } 
        Fraction Fraction::operator--(int){
            return Fraction(1,2);
        } 

        bool operator==(const Fraction &frack1, const Fraction &frack2){
            return false;
        }
        bool operator!=(const Fraction &frack1, const Fraction &frack2){
            return false;
        }
        bool operator>(const Fraction &frack1, const Fraction &frack2){
            return false;
        }
        bool operator<(const Fraction &frack1, const Fraction &frack2){
            return false;
        }
        bool operator>=(const Fraction &frack1, const Fraction &frack2){
            return false;
        }
        bool operator<=(const Fraction &frack1, const Fraction &frack2){
            return false;
        }

        bool operator==(const Fraction &frack, float num){
            return false;
        }
        bool operator!=(const Fraction &frack, float num){
            return false;
        }
        bool operator>(const Fraction &frack, float num){
            return false;
        }
        bool operator<(const Fraction &frack, float num){
            return false;
        }
        bool operator>=(const Fraction &frack, float num){
            return false;
        }
        bool operator<=(const Fraction &frack, float num){
            return false;
        }

        bool operator==(float num, const Fraction &frack){
            return false;
        }
        bool operator!=(float num, const Fraction &frack){
            return false;
        }
        bool operator>(float num, const Fraction &frack){
            return false;
        }
        bool operator<(float num, const Fraction &frack){
            return false;
        }
        bool operator>=(float num, const Fraction &frack){
            return false;
        }
        bool operator<=(float num, const Fraction &frack){
            return false;
        }

     // The << operator to print a fraction
    std::ostream &operator<<(std::ostream &stream, const Fraction &fruc){
        //need to perform
        return stream;
    }

    // The >> operator to read a fraction 
    std::istream& operator>>(std::istream& stream, Fraction& frac){
        //need to perform
        return stream;
    }
}

