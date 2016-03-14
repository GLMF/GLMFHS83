#include <iostream>

using namespace std;
//using namespace std::string_literals; /** Fonctionne avec la norme C14 */


/**
 * Test sur les littéraux nombres
 */
void test_nombres()
{
    std::cout << 123 << std::endl;
    std::cout << 12345 << std::endl;
    std::cout << 123456789 << std::endl;
    std::cout << 123456789123456789 << std::endl;
    std::cout << 123456789123456789123456789123456789 << std::endl; /**< Trop long */
}


/**
 * Test sur les littéraux chaînes de caractères
 */
void test_chaines()
{
    cout << "Hello world!" << endl; /**< Correct */
    cout << 'Hello world!' << std::endl; /**< Incorrect */

    // cout << "Hello world!"s << std::endl; /** Fonctionne avec la norme C14 */

    char s1[] = "Hello world!"; /**< Tableau de caractères */
    const char *s2 = "Hello world!"; /**< Pointeur vers un tableau de caractères */
    string s3 = "Hello world!"; /**< Chaîne de caractère objet */
    cout << s1 << endl << s2 << endl << s3 << endl;
}


/**
 * Hello world classique + tests
 */
int main()
{

    cout << "Hello world!" << endl;

    test_nombres();
    test_chaines();

    return 0;
}
