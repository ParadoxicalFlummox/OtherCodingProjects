#include <iostream>
#include <cmath>
using namespace std;

class Complex{
public:
    int real, imaginary;
    Complex(){
        real = 0;
        imaginary = 0;}

    Complex(int r, int i){
        real = r;
        imaginary = i;}

    float getMagnitude(){
        return sqrt(pow(real, 2) + pow(imaginary, 2));}
    
    float getAngle(){
        return atan(imaginary / float(real));}

    bool operator==(Complex &obj){return (real==obj.real && imaginary==obj.imaginary);}

    Complex operator+(Complex &obj){
        Complex res;
        res.real = real + obj.real;
        res.imaginary = imaginary + obj.imaginary;
        return res;}

    Complex operator-(Complex &obj){
        Complex res;
        res.real = real - obj.real;
        res.imaginary = imaginary - obj.imaginary;
        return res;}

    Complex operator*(Complex &obj){
        Complex res;
        res.real = ((real * obj.real) - (imaginary * obj.imaginary));
        res.imaginary = ((imaginary * obj.real) + (real * obj.imaginary));
        return res;}

    Complex operator/(Complex &obj){
        Complex res;
        res.real = real / obj.real - imaginary / obj.imaginary;
        res.imaginary = imaginary / obj.real + real / obj.imaginary;
        return res;}};

ostream& operator<<(ostream& out, Complex c){
    out<<c.real<<" + "<<c.imaginary<<"i";
    return out;}

int main(){
    Complex c1(2, 3), c2(4, 5);
    cout << c1.getMagnitude() << endl;
    cout << c2.getMagnitude() << endl;
    cout << c1.getAngle() << endl;
    cout << c2.getAngle() << endl;
    cout<<"c1 + c2 = "<<(c1+c2)<<endl;
    cout<<"c1 - c2 = "<<(c1-c2)<<endl;
    cout<<"c1 * c2 = "<<(c1*c2)<<endl;
    cout<<"c1 / c2 = "<<(c1/c2)<<endl;
    if(c1==c2){cout<<"c1 and c2 are equal"<<endl;}
    else{cout<<"c1 and c2 are not equal"<<endl;}
	return 0;}