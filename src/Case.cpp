#include "Case.hpp"


Case::Case(char c): symbole(c) {}

ostream& operator<<(ostream& out, Case c)
{
    out << c.symbole;
    return out;
}
