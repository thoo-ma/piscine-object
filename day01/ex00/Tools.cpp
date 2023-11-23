#include "Tools.hpp"

Tool::Tool(): numberOfUses(0), user(NULL) { }
void Shovel::use() { std::cout << "Shovel use()" << std::endl; }
void Hammer::use() { std::cout << "Hammer use()" << std::endl; }
