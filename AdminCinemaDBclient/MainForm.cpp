#define _WIN32_WINNT 0x501

#include <WinSock2.h>
#include <WS2tcpip.h>
#include<winsock.h>
#pragma comment(lib, "Ws2_32.lib")

#include<iostream>
#include <typeinfo>
#include <stdio.h>  
#include <conio.h>  
#include "icrsint.h"  
#include <string>
#include"Function.h"
#include<list>
#include "MainForm.h"
#include"AdminSocket.h"
#include"Film.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	AdminCinemaDBclient::MainForm form; //WinFormsTest - имя вашего проекта
	Application::Run(%form);
}
