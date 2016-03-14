#include <iostream>

using namespace std;

namespace
{

    void langues()
    {
        cout << "Grec : Ελληνικά" << endl;
        cout << "Hébreux : עִבְרִית" << endl;
        cout << "Japonnais : 日本" << endl;
        cout << "Hindi : भारत गणराज्य" << endl;
        cout << "Chinois simplifié; 中华人民共和国" << endl;
        cout << "Chinois traditionnel : 中華人民共和國" << endl;
    }

    void operations()
    {
        string s = "Hello world!";
        cout << s << " : (" << s.size() << ")" << endl;

        string s1 = "Hello";
        string s2 = "world";
        s = s1 + " " + s2 + '!';
        cout << s << " : (" << s.size() << ")" << endl;

        s.clear();
        s += s1;
        s += ' ';
        s.append(s2);
        s.append(",;:!?./§", 3, 1);
        cout << s << " : (" << s.size() << ")" << endl;

        cout << "\"grand\" <= \"petit\") =>" << ("grand" <= "petit") << endl;
    }

    void conversions()
    {
        string s = to_string(42);
        cout << s << " : (" << s.size() << ")" << endl;

        int i = stoi(s);
        long int l = stol(s);
        unsigned int ul =stoul(s);
        long long ll = stoll(s);
        unsigned long long ull = stoull(s);
        float f = stof(s);
        double d = stod(s);
        long double ld= stold(s);
    }

    void recherche()
    {
        string s = "** abcba **";
        cout << "b est dans \"** abcba **\" ? " << s.find( 'b' ) << endl;  // 4
        cout << "b est dans \"** abcba **\" (après le 5ème caractère) ? " << s.find( 'b', 5 ) << endl;  // 6
        cout << "ba est dans \"** abcba **\" ? " << s.find( "ba" ) << endl;  // 6
        cout << "b est dans \"** abcba **\" ? " << s.find_first_of( 'b' ) << endl;  // 4
        cout << "b ou a est sont dans \"** abcba **\" ? " << s.find_first_of( "ba" ) << endl;  // 3
        cout << "z est dans \"** abcba **\" ? " << s.find( 'z' ) << endl;  // -1
        cout << "za est dans \"** abcba **\" ? " << s.find( "za" ) << endl;  // -1
        cout << "z est dans \"** abcba **\" ? " << s.find_first_of( 'z' ) << endl;  // -1
        cout << "z ou a sont dans \"** abcba **\" ? " << s.find_first_of( "za" ) << endl;  // 3
    }

    void comparaison()
    {
        cout << "\"a\" < \"b\": " << ("a" < "b") << endl;
        cout << "\"a\" < \"B\": " << ("a" < "B") << endl;
        cout << "\"a\" < \"A\": " << ("a" < "A") << endl;
        cout << "\"A\" < \"a\": " << ("A" < "a") << endl;
        cout << "\"grand\" <= \"petit\": " << ("grand" <= "petit") << endl;
        cout << "\"petit\" <= \"grand\": " << ("petit" <= "grand") << endl;
        cout << "\"Petit\" <= \"grand\": " << ("Petit" <= "grand") << endl;
        cout << "\"petit\" < \"Petit\": " << ("petit" < "Petit") << endl;
        cout << "\"Petit\" < \"petit\": " << ("Petit" < "petit") << endl;
    }
}


void test_strings()
{
    langues();
    operations();
    conversions();
    recherche();
    comparaison();
}
