#pragma once

const int maxBufferSize = 1024;


class AdminSocket
{
private:
	SOCKET adminSocket;
	WSADATA wsaData;
	struct addrinfo *address;
	struct addrinfo hints;
	int result;
	char answerBuffer[maxBufferSize + 1];
	int answerLength;
	string request;
	string answer;
public:
	AdminSocket(const char* ipAddress, const char* port)
	{
		this->result = WSAStartup(MAKEWORD(2, 2), &wsaData);
		if (result != 0)
		{
			cout << "wsa start failed" << endl;
			system("pause");
		}
		this->adminSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		this->address = NULL;
		ZeroMemory(&hints, sizeof(hints));
		hints.ai_family = AF_INET; //сеть для работы с сокетом
		hints.ai_socktype = SOCK_STREAM; //потоковый сокет
		hints.ai_protocol = IPPROTO_TCP;// протокол tcp
		hints.ai_flags = AI_PASSIVE;
		this->result = getaddrinfo("127.0.0.1", "8000", &hints, &address);
		if (result != 0)
		{
			cout << "error getaddres info" << endl;
			system("pause");
		}
		this->result = connect(this->adminSocket, address->ai_addr, address->ai_addrlen);
	}

	~AdminSocket()
	{
		closesocket(this->adminSocket);
	}

	string sendRequestToGetListOfFilms()
	{
		this->request = "getListOfFilm|\0";
		this->result = send(this->adminSocket, request.c_str, request.length(), 0);
		if (result <= 0)
		{
			cout << "error sending request" << endl;
			return "error";
		}
		memset(answerBuffer, 0, maxBufferSize + 1);
		this->answerLength = recv(adminSocket, answerBuffer, maxBufferSize, 0);
		if(answerLength <= 0)
		{
			cout << "error getting answer" << endl;
			return "error";
		}
		this->answerBuffer[answerLength] = '\0';
		this->answer = this->answerBuffer;
		return answer;
	}
};