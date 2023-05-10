#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;

namespace ariel{

    class Fraction {

    private:
    int numerator;
    int denominator;
    
    public:
    Fraction(int numerat, int denomin);
    Fraction(float number);
    Fraction();

    void setNumerator(int numerator1) {
        numerator = numerator1;
    }

    int getNumerator() const {
        return numerator;
    }

    void setDenominator(int denom) {
        denominator = denom;
    }

    int getDenominator() const {
        return denominator;
    }
    
      friend int gcd(int numerator, int denominator);//ensures that the Fraction object is in its simplest form, where the numerator and denominator have no common factors other than 1.
        friend Fraction float_to_frac(float num);

        // im compering and doing operetion numbers with objects because the exemple in the demo 
        friend Fraction operator+(const Fraction& frack1, const Fraction& frack2);
        friend Fraction operator-(const Fraction& frack1, const Fraction& frack2);
        friend Fraction operator*(const Fraction& frack1, const Fraction& frack2);
        friend Fraction operator/(const Fraction& frack1, const Fraction& frack2);

        friend Fraction operator+(const Fraction& frack, float num);
        friend Fraction operator-(const Fraction& frack, float num);
        friend Fraction operator*(const Fraction& frack, float num);
        friend Fraction operator/(const Fraction& frack, float num);

        friend Fraction operator+(float num, const Fraction& frack);
        friend Fraction operator-(float num, const Fraction&frack);
        friend Fraction operator*(float num, const Fraction&frack);
        friend Fraction operator/(float num, const Fraction&frack);
    
        Fraction const & operator++(); // pre-increment
        Fraction operator++(int); // post-increment
        Fraction const & operator--(); // pre-decrement
        Fraction operator--(int); // post-decrement

        friend bool operator==(const Fraction &frack1, const Fraction &frack2);
        friend bool operator>(const Fraction &frack1, const Fraction &frack2);
        friend bool operator<(const Fraction &frack1, const Fraction &frack2);
        friend bool operator>=(const Fraction &frack1, const Fraction &frack2);
        friend bool operator<=(const Fraction &frack1, const Fraction &frack2);

        friend bool operator==(const Fraction &frack, float num);
        friend bool operator>(const Fraction &frack, float num);
        friend bool operator<(const Fraction &frack, float num);
        friend bool operator>=(const Fraction &frack, float num);
        friend bool operator<=(const Fraction &frack, float num);

        friend bool operator==( float num, const Fraction &frack);
        friend bool operator>( float num, const Fraction &frack);
        friend bool operator<( float num, const Fraction &frack);
        friend bool operator>=( float num, const Fraction &frack);
        friend bool operator<=( float num, const Fraction &frack);

        operator string() const{
            return to_string(this->numerator)+"/"+to_string(this->denominator);
        }

        // The << operator to print
        friend std::ostream& operator<<(std::ostream &stream, const Fraction &frac);

        // The >> operator to read 
        friend std::istream& operator>>(std::istream &strem, Fraction& frac);
        
    };
}

