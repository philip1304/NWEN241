#include <iostream>

namespace Complex {
    class complex {
    private:
        int a;
        int b;

    public:
        // Default constructor
        complex() {
            a = 1;
            b = 1;
        }

        // Parameterized constructor
        complex(int real, int imag) {
            a = real;
            b = imag;
        }

        // Getter for 'a'
        int geta() {
            return a;
        }

        // Getter for 'b'
        int getb() {
            return b;
        }
    };
}

int main() {
    // Declare c1 using default constructor
    Complex::complex c1;

    // Declare c2 using parameterized constructor
    Complex::complex c2(5, 10);

    // Display the complex numbers
    std::cout << "Complex number 1: " << c1.geta() << " + " << c1.getb() << "i" << std::endl;
    std::cout << "Complex number 2: " << c2.geta() << " + " << c2.getb() << "i" << std::endl;

    return 0;
}
