#include <iostream>

#define INTERACTIVE

int main (int, char *[])
{
#ifdef INTERACTIVE
  std::cout << "ifdef interactive" << std::endl;
#endif
  
#if defined(INTERACTIVE)
  std::cout << "if defined(interactive)" << std::endl;
#endif

  return 0;
}

