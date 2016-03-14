set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-O0 -ggdb -Wall -Werror -std=c++14")

add_executable(espace_nommage espace_nommage.cpp)
add_executable(iterateur iterateur.cpp)
add_executable(map map.cpp)
add_executable(pointeur pointeur.cpp)
add_executable(reference reference.cpp)
add_executable(tableaux tableaux.cpp)
add_executable(variable variable.cpp)
add_executable(vecteur vecteur.cpp)

