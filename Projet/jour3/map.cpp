
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <unordered_set>

void afficher_map(std::map<std::string, int> occurrences)
{
	for (auto &x: occurrences)
	{
		std::cout << x.first << " : " << x.second << std::endl;
	}
	std::cout << "occurrences contients " << occurrences.size() << " mots." << std::endl;
}

void test_map()
{
	std::map<std::string, int> occurrences;
	
	occurrences["mot"] = 42;
	occurrences["python"] = 34;
	
	std::cout << "NB d' occurrences de \"mot\": " << occurrences["mot"] << std::endl;
	std::cout << "NB d' occurrences de \"python\": " << occurrences["python"] << std::endl;
	std::cout << "NB d' occurrences de \"rugby\": " << occurrences["rugby"] << std::endl;


	afficher_map(occurrences);
	
	occurrences.emplace("ovale", 34);

	occurrences.emplace_hint(occurrences.end(), "ovale", 34);

	afficher_map(occurrences);

	std::map<std::string, int>::iterator it;

	it = occurrences.end();
	it = occurrences.emplace_hint(it, "rond", 31);
	it = occurrences.emplace_hint(it, "carré", 54);
	it = occurrences.emplace_hint(it, "point", 68);
	it = occurrences.emplace_hint(it, "triangle", 72);

	afficher_map(occurrences);

	occurrences.insert(std::pair<std::string,int>("ovale", 34));


	std::map<std::string, int>::iterator it1;
	std::map<std::string, int>::iterator it2;

	occurrences.erase("carré");

	it1 = occurrences.find("triangle");
	occurrences.erase(it1);

	it2 = occurrences.find("rond");
	it1 = occurrences.find("point");
	occurrences.erase(it1, it2);

	afficher_map(occurrences);
}

/////////////////////////////////////////////////////////////////

void afficher_set(std::unordered_set<std::string> langages)
{
	for (auto &x: langages)
	{
		std::cout << x << std::endl;
	}
}

void test_set()
{
	std::unordered_set<std::string> langages;
	langages.emplace("C++");
	langages.insert("Python");
	langages.insert({"Caml", "Ada"});

	afficher_set(langages);

	std::vector<std::string> vecteur = {"C", "Fortran"};
	langages.insert(vecteur.begin(), vecteur.end());

	langages.erase("Ada");

	afficher_set(langages);
}

int main()
{
	test_map();
	test_set();
	return 0;
}

