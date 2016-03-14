
#include <iostream>
#include <vector>

using namespace std;

void test_vecteur()
{
	std::vector<int> nombres = {34, 42, 54, 16, 27, 42};
	std::vector<int> nombres1 (10);

	cout << "Premier élément : " << nombres[0] << endl;
	cout << "Premier élément : " << nombres.at(0) << endl;
	try {
		cout << "élément�100�: " << nombres.at(100)<< endl;
	} catch (out_of_range e) {
		cout << "exception: il n'y a pas d'élément 100: "<< e.what() << endl;
	}
	cout << "Premier élément : " << nombres.front() << endl;
	cout << "Dernier élément : " << nombres.back() << endl;

	nombres.back() = nombres.at(1);
	nombres.at(4) = nombres.front();

	cout << "Nombre d'éléments : " << nombres.size() << endl;
	cout << "Aucun élément ? " << nombres.empty() << endl;

	nombres.clear();

	nombres.resize(3);
	nombres.resize(5);
	nombres.resize(7, 42);

	cout << "Capacité : " << nombres.capacity() << endl;
	cout << "Taille maximale : " << nombres.max_size() << endl;

	nombres.reserve(100);
	nombres.shrink_to_fit();
	//nombres.push_back(58);

	cout << "Nombre d'éléments : " << nombres.size() << endl;

	nombres.pop_back();

	cout << "Nombre d'éléments : " << nombres.size() << endl;

	std::vector<int> nombres2 = {42, 58};
	//nombres2.assign(12, 42);

	cout << "Nombre d'éléments : " << nombres.size() << endl;

	nombres2.swap(nombres);

	cout << "Premier élément : " << nombres.front() << endl;
	cout << "Dernier élément : " << nombres.back() << endl;
}

void test_vecteur2()
{
	std::vector<int> nombres = {34, 42, 54, 16, 27, 42};
	std::vector<int> nombres2 = {42, 58};

	/* vecteur seconde partie */

	std::vector<int> myvector (10);
	std::vector<int>::iterator it = myvector.begin(); 
	it = myvector.insert(it, 42);

	int n = 2;
	it = myvector.insert(it + n , 42);
	it = myvector.insert(it + n, nombres2.begin(), nombres2.end());
	it = myvector.insert(it + n, nombres2.begin() - 1, nombres2.end() + 1);
	
	int tableau[] = {1, 2, 3};
	it = myvector.insert(it + n, tableau, tableau + 3);
	
	nombres.erase(nombres.begin() + (n - 1));
	cout << "Nombre d'éléments : " << nombres.size() << endl;

	nombres2.assign(4, 0); // Réinitialisation du tableau (4 éléments)
	int* p = nombres2.data();
	
	*p = 42;
	p[0] += 100;
	p[1] = 16;
	p[2] = 34;
	p[3] = 54;
	
	p = nombres2.data();
	++p;
	*p += 18;
	++p;
	*p += 20;
	++p;
	*p += 22;

	cout << "0 : " << nombres2[0] << endl;
	cout << "1 : " << nombres2[1] << endl;
	cout << "2 : " << nombres2[2] << endl;
	cout << "3 : " << nombres2[3] << endl;
}

int main()
{
	test_vecteur();
	test_vecteur2();
	return 0;
}




