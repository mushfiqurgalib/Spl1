
#include"node.h"
#include <windows.h>
#include <wininet.h>
#include <iostream>
#include <cstring>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

int gethtml()
{
std::fstream fs_obj;
  fs_obj.open("b.html",ios::out );

  string ap;
  cin>>ap;
  char * cstr = new char [ap.length()+1];
  std::strcpy (cstr, ap.c_str());

  HINTERNET hInternet = InternetOpenA("InetURL/1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0 );

  HINTERNET hConnection = InternetConnectA( hInternet, cstr, 80, " "," ", INTERNET_SERVICE_HTTP, 0, 0 ); //enter url here

  HINTERNET hData = HttpOpenRequestA( hConnection, "GET", "/", NULL, NULL, NULL, INTERNET_FLAG_KEEP_CONNECTION, 0 );

  char buf[ 2048 ] ;

  HttpSendRequestA( hData, NULL, 0, NULL, 0 ) ;
  string total;
  DWORD bytesRead = 0 ;
  DWORD totalBytesRead = 0 ;

  while( InternetReadFile( hData, buf, 2000, &bytesRead ) && bytesRead != 0 )
  {
    buf[ bytesRead ] = 0 ; // insert the null terminator.
    total=total+buf;
   // printf( "%d bytes read\n", bytesRead ) ;

    totalBytesRead += bytesRead ;
  }

  fs_obj<<total<<" ";
  fs_obj.close();
  printf( "\n\n END -- %d bytes read\n", bytesRead ) ;
  printf( "\n\n END -- %d TOTAL bytes read\n", totalBytesRead ) ;

  cout<<endl<<total<<endl; //it will save source code to (temp.txt) file
  InternetCloseHandle( hData ) ;
  InternetCloseHandle( hConnection ) ;
  InternetCloseHandle( hInternet ) ;
  system("pause");
}
