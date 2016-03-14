#include <iostream>

using namespace std;

class Base
{
    public:
        void a(int i);
        virtual void b(int i);
        void c(int i);
        virtual void d(int i);
        void e(int i);
        virtual void f(int i);
        void g(int i);
        virtual void h(int i);
};

void Base::a(int i)
{
    cout << "Base::a(" << i << ")" << endl;
}

void Base::b(int i)
{
    cout << "Base::b(" << i << ")" << endl;
}

void Base::c(int i)
{
    cout << "Base::c(" << i << ")" << endl;
}

void Base::d(int i)
{
    cout << "Base::d(" << i << ")" << endl;
}

void Base::e(int i)
{
    cout << "Base::e(" << i << ")" << endl;
}

void Base::f(int i)
{
    cout << "Base::f(" << i << ")" << endl;
}

void Base::g(int i)
{
    cout << "Base::g(" << i << ")" << endl;
}

void Base::h(int i)
{
    cout << "Base::h(" << i << ")" << endl;
}


class Derived : private Base
{
    public:
        void a(int i);             // Redéfinition
        virtual void b(int i);     // Redéfinition
        void a(double i);          // Surcharge
        virtual void b(double i);  // Surcharge
        using Base::c;             // Déplacement
        using Base::d;             // Déplacement
        using Base::e;             // Déplacement
        using Base::f;             // Déplacement
        void g(int i);             // Redéfinition
        virtual void h(int i);     // Redéfinition
};

void Derived::a(int i)
{
    cout << "Derived::a(" << i << ")" << endl;
}

void Derived::b(int i)
{
    cout << "Derived::b(" << i << ")" << endl;
}

void Derived::a(double i)
{
    cout << "Derived::a(" << i << ".0)" << endl;
}

void Derived::b(double i)
{
    cout << "Derived::b(" << i << ".0)" << endl;
}

void Derived::g(int i)
{
    cout << "Derived::g(" << i << ") > ";
    Base::g(i);
}

void Derived::h(int i)
{
    cout << "Derived::h(" << i << ") > ";
    Base::h(i);
}


int main()
{
    Derived derived;
    derived.a(42);
    derived.b(42);
    derived.a(42.0);
    derived.b(42.0);
    derived.c(42);
    derived.d(42);
    derived.e(42);
    derived.f(42);
    derived.g(42);
    derived.h(42);

    return 0;
}
