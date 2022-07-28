#include <iostream>
#include "vec.class.h"

using std::string;

int main()
{
    // Create vector
    Vec<string> foods({"🍎", "🍜", "🍉", "🎂"});

    // Print vector
    foods.print();

    // Vector indexing
    string noodle = foods.value[1];
    std::cout << noodle << std::endl;

    // Find function
    string cake = foods.find([](string food)
                             { return food == "🎂"; });
    std::cout << cake << std::endl;

    // Filter function
    Vec<string> fruits = foods.filter([](string food)
                                      { return food == "🍎" || food == "🍉"; });
    fruits.print();

    // Map function
    Vec<string> pooPoo = foods.map<string>([](string food)
                                           { return food + " => 💩"; });
    pooPoo.print();

    // Push function
    foods.push("🍥");
    foods.print();

    return 0;
}