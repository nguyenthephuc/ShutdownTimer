#include <iostream>
#include <windows.h>
#include <sstream>
#include <string>

#define SHUT_DOWN "\\shutdown /s /t "
#define DEFAULT_TIME 20

using namespace std;

string intToString(int a);
int stringToInt(string str);
void shutdown(int m);

int main() {
  string str = "";
  int m;
  cout << "Ban muon tat may sau bao nhieu phut?" << endl;
  cout << "#1 Nhap so phut ban muon (0 de tat may ngay lap tuc)." << endl;
  cout << "#2 Nhap so am de huy/thoat chuong trinh." << endl;
  cout << "#3 Enter de tat may sau " << DEFAULT_TIME << " phut." << endl << endl;
  do {
    getline(cin, str);
    if (str.length() != 0) {
      m = stringToInt(str);
      //cout << "m = " << m << endl;
      if (m >= 0) {
        shutdown(m);
        return 0;
      } else {
        return 0;
      }
    }
  } while (str.length() != 0);
  shutdown(DEFAULT_TIME);
  return 0;
}

string intToString(int k) {
  stringstream ss;
  ss << k;
  string s;
  ss >> s;
  return s;
}

int stringToInt(string str) {
  stringstream ss;
  ss << str;
  int m;
  ss >> m;
  return m;
}

void shutdown(int m) {
  string strCmd = "", strTime = intToString(m * 60);
  stringstream ss;
  char windir[MAX_PATH];
  GetSystemDirectoryA(windir, MAX_PATH);
  ss << windir;
  ss >> strCmd;
  strCmd = strCmd + SHUT_DOWN + strTime;
  //cout << strCmd << endl;
  system(const_cast < char * > (strCmd.c_str()));
}
