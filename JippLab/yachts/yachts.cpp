

#include <iostream>
#include "interface.h"

int main()
{
    std::cout << "Yacht app\n\n";
    YachtPort yachtPort("popielno", "popielno");
    UserInterface interface(yachtPort);
    interface.run();
}


