#pragma once

#include <iostream>
#include <math.h>

class complex {
private:
    double real;
    double imaginary;
public:
    complex() { 
        real = 0; 
        imaginary = 0; 
    }
    complex(double r, double i) { 
        real = r; 
        imaginary = i; 
    }
    complex(const complex& other) { 
        real = other.real; 
        imaginary = other.imaginary; 
    }

    complex& operator = (complex other) {
        this->real = other.real;
        this->imaginary = other.imaginary;
        return *this;
    }
    complex operator + (complex other) {
        complex result = complex(*this);
        result.real = this->real + other.real;
        result.imaginary = this->imaginary + other.imaginary;
        return result;
    }
    complex operator - (complex other) {
        complex result = complex(*this);
        result.real = this->real - other.real;
        result.imaginary = this->imaginary - other.imaginary;
        return result;
    }
    complex operator * (complex& other) {
        complex result = complex(*this);
        result.real = real * other.real - imaginary * other.imaginary;
        result.imaginary = real * other.imaginary + other.real * imaginary;
        return result;
    }
    complex operator / (complex& other) {
        double k;
        complex result = complex(*this);
        k = real * real + other.imaginary * other.imaginary;
        result.real = (real * other.real + imaginary * other.imaginary) / k;
        result.imaginary = (other.real * imaginary - real * other.imaginary) / k;
        return result;
    }
    complex& operator += (complex other) {
        real += other.real;
        imaginary += other.imaginary;
        return *this;
    }
    complex& operator -= (complex other) {
        real -= other.real;
        imaginary -= other.imaginary;
        return *this;
    }
   
    bool operator == (complex& other) {
        if (this->real == other.real && this->imaginary == other.imaginary)
            return 1;
        else
            return 0;
    }
    bool operator != (complex& other) {
        if (this->real != other.real || this->imaginary != other.imaginary){
            return 1;
        }
        else {
            return 0;
        }
    }
    bool operator > (complex& other) {
        if(sqrt(real * real + imaginary * imaginary) > sqrt(other.real * other.real + other.imaginary * other.imaginary)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    bool operator >= (complex& other) {
        if(sqrt(real * real + imaginary * imaginary) >= sqrt(other.real * other.real + other.imaginary * other.imaginary)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    bool operator < (complex& other) {
        if(sqrt(real * real + imaginary * imaginary) < sqrt(other.real * other.real + other.imaginary * other.imaginary)) {
            return 1;
        }
        else {
            return 0;
        }
    }
    bool operator <= (complex& other) {
        if(sqrt(real * real + imaginary * imaginary) <= sqrt(other.real * other.real + other.imaginary * other.imaginary)) {
            return 1;
        }
        else {
            return 0;
        }
    }

    friend std::ostream& operator << (std::ostream& stream, const complex& other) {
        if (other.imaginary == 0)
            stream << other.real;
        else if (other.imaginary >= 0)
            stream << other.real << " + " << other.imaginary << 'i';
        else
            stream << other.real << " - " << -other.imaginary << 'i';
        return stream; 
    }
};