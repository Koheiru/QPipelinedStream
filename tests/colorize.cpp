#include <windows.h>
#include <iostream>
#include <string>
#include <regex>
 
enum Color { blue=1, green, cyan, red, purple, yellow, grey, dgrey, hblue, hgreen, hcyan, hred, hpurple, hyellow, hwhite };
 
using namespace std;
 
void SetConsoleColor( Color color )
{
   SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (WORD) color);
}
WORD GetConsoleColor ()
{
   auto consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   CONSOLE_SCREEN_BUFFER_INFO con_info;
   GetConsoleScreenBufferInfo(consoleHandle, &con_info);
   return con_info.wAttributes;
}
 
class ColorGuard
{
public:
 ColorGuard() : m_color(GetConsoleColor())
 {}
 
 ~ColorGuard()
 {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), m_color);
 }
 
private:
 WORD m_color;
};
 
int main()
{
  string line;
 
  regex fail("(FAIL.*)");
  regex pass("(PASS.*)");
 
  while (getline(cin, line))
  {
    ColorGuard guard;
 
    if (regex_match(line, fail))
    {
      SetConsoleColor(hred);
    }
 
    if (regex_match(line, pass))
    {
      SetConsoleColor(hgreen);
    }
 
    cout << line << endl;
  }
 
  return 0;
}
