#include <iostream>
#include <cmath>
#include <limits>


namespace
{

    void operations()
    {
        int a = 7, b = 1, c = 42;
        a = 2 * (1 + b * a) * b + 5 - c / 2;
        std::cout << "valeur de a après calcul: " << a << std::endl;
        std:: cout << "------------------------------------------------- " << std::endl;
        a++;
        c--;
        b += 3;
        b *= 4;
        b /= 2;
        b -= 1;
        std::cout << a << " / " << b << " = " << a / b << std::endl;
        float u = 1, v = 7;
        std::cout << u << " / " << v << " = " << u / v << std::endl;
        std:: cout << "------------------------------------------------- " << std::endl;
        std::cout << 42 << " % " << 5 << " = " << 42 % 5 << std::endl;
        c %= 5;
        std::cout << 41 << " % " << 5 << " = " << c << std::endl;

        short x = 42, y = 38;
        std:: cout << "------------------------------------------------- " << std::endl;
        std:: cout << "x      = " << x << ",  représenté 0b00101010" << std::endl;
        std:: cout << "~x     = " << ~x << ", représenté 0b11010101" << std::endl;
        std:: cout << "x >> 2 = " << (x >> 2) << ",  représenté 0b00001010" << std::endl;
        std:: cout << "x << 2 = " << (x << 2) << ", représenté 0b10101000" << std::endl;
        std:: cout << "------------------------------------------------- " << std::endl;
        std:: cout << "x      = " << x << ",  représenté 0b00101010" << std::endl;
        std:: cout << "y      = " << y << ",  représenté 0b00100110" << std::endl;
        std:: cout << "x & y  = " << (x & y) << ",  représenté 0b00100010" << std::endl;
        std:: cout << "------------------------------------------------- " << std::endl;
        std:: cout << "x      = " << x << ",  représenté 0b00101010" << std::endl;
        std:: cout << "y      = " << y << ",  représenté 0b00100110" << std::endl;
        std:: cout << "x | y  = " << (x | y) << ",  représenté 0b00101110" << std::endl;
        std:: cout << "------------------------------------------------- " << std::endl;
        std:: cout << "x      = " << x << ",  représenté 0b00101010" << std::endl;
        std:: cout << "y      = " << y << ",  représenté 0b00100110" << std::endl;
        std:: cout << "x ^ y  = " << (x ^ y) << ",  représenté 0b00001100" << std::endl;
        std:: cout << "------------------------------------------------- " << std::endl;
    }

    const double PI = acos(-1);

    void fonctions()
    {
        double valeur = 42.42;

        std::cout << "Valeur:              " << valeur << std::endl;
        std::cout << "Arrondi supérieur:   " << ceil(valeur) << std::endl;
        std::cout << "Arrondi inférieur:   " << floor(valeur) << std::endl;
        std::cout << "Racine:              " << sqrt(valeur) << std::endl;
        std::cout << "Carré:               " << pow(valeur, 2) << std::endl;
        std::cout << "Puissance:           " << pow(valeur, 2.1) << std::endl;
        std::cout << "Exponentielle:       " << exp(valeur) << std::endl;
        std::cout << "Logarithme népérien: " << log(valeur) << std::endl;
        std::cout << "Logarithme base 10:  " << log10(valeur) << std::endl;

        std::cout << "------------------------------------------------" << std::endl;

        std::cout << "Valeur de pi/4:      " << PI / 4 << std::endl;

        std::cout << "------------------------------------------------" << std::endl;

        std::cout << "Cosinus pi/4:        " << cos(PI / 4) << std::endl;
        std::cout << "Sinux pi/4:          " << sin(PI / 4) << std::endl;
        std::cout << "Tangeante pi/4:      " << tan(PI / 4) << std::endl;

        std::cout << "Acosinus pi/4:       " << acos(7.07107) << std::endl;
        std::cout << "Asinux pi/4:         " << asin(7.07107) << std::endl;
        std::cout << "Atangeante pi/4:     " << atan(1) << std::endl;

        std::cout << "------------------------------------------------" << std::endl;

        std::cout << "Opération incorrecte " << asin(42) << std::endl;

        std::cout << "------------------------------------------------" << std::endl;
    }

    namespace balle
    {
        double centre_x = 50, centre_y = 0;
        int rayon = 5;

        int vitesse = 4;
        double angle = PI / 4;

        void deplacer()
        {
            centre_x += vitesse * cos(angle);
            centre_y += vitesse * sin(angle);
        }

        void afficher()
        {
            std::cout << "<Balle (" << centre_x << ", " << centre_y << ")>" << std::endl;
        }

    }
}


typedef std::numeric_limits< double > dbl;


void test_nombres()
{
    operations();

    fonctions();

    std::cout.precision(dbl::max_digits10);
    std::cout << "PI = " << PI << std::fixed << std::endl;

    balle::afficher();
    balle::deplacer();
    balle::afficher();
}
