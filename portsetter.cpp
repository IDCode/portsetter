#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

void print(string file_name)
{
	string output;
	ifstream infile; // english	
	infile.open(file_name);
	if (infile.is_open()) {
		while (!infile.eof()) {
			if (infile.peek() == '\n')  
                  cout << '\n';
			infile >> output;
			cout << output << " ";
		}
	}
	infile.close();
}

void about(int lang)
{
	if (lang == 1) 
		print("portsetter.about_en.txt");
	else if (lang == -1)
		print("portsetter.about_es.txt");
}

void usage(int lang)
{	
	if (lang == 1)
		print("portsetter.usage_en.txt");
	else if (lang == -1)
		print("portsetter.usage_es.txt");
}

enum {
	DEFAULT_PORT, // "Listening on default port " 
	SET_PORT, // "Listening on port "
	EXCEED_LIMIT, // "error: too many arguments...   return 1"
	NO_PORT, // "error: no port given...   return 1"
	NO_FLAG, // "error: no arguments given...   return 0"
	INVALID_PORT, // "error: invalid port...  return 1"
	INVALID_FLAG, // "error: invalid flag...   return 1"
	VERSION,
};

string en[] = {
	"\nListening on default port ",
	"\n\tListening on port ",
	"error: too many arguments...   return 1", // errors
	"error: no port given...   return 1",
	"error: no arguments given...   return 0",
	"error: invalid port...  return 1",
	"error: invalid flag...   return 1",
	"\nportsetter.v_2.1"
};

string es[] = {
	"\nEscucha en el puerto por defecto",
	"\n\tEscuchando en el puerto",
	"Error: demasiados argumentos ... volver 1", // errors
	"Error: no determinado puerto ... volver 1",
	"Error: no hay argumentos dados ... volver 0",
	"Error: puerto no válido ... volver 1",
	"Error: El indicador no válido ... volver 1"
	"\nportsetter.v_2.1"
};

const int MIN_PORT = 1, MAX_PORT = 65536,
		  MY_PORT = 9999, YOUR_PORT = 1111;

int main(int argc, char *args[])
{
	string type_get, env_get; // flag, env
	char* def_env = getenv("PORT");
	int port;

	string* msg = en; // defualt
	int lang = 1; // default
	char* locale = getenv("LANGUAGE");
	
	if (locale == "es.MX" || locale == "es.UTF-8" || locale == "es.MX.UTF-8") {
		lang = -1;
		msg = es;
	}
	//else {
	//	cout << "Language defaulting to english." << endl;
	//}
	
	for (int i = argc - 1; i > 0; i--)
	{	
		if (argc >= 4) { // exceeds limit
		    cout << msg[EXCEED_LIMIT] << endl; 
			usage(lang);
			return 1;
		}
		else if (argc == 3) { // check for 3 - validate and process port
			type_get = string(args[1]); // flag, env
			env_get = string(args[2]);
		
			if (env_get == "-e") {
					 cout << msg[DEFAULT_PORT] << def_env << endl;
					 return 0;
			}
			
			port = atoi(args[2]);
			if (type_get == "--port" || type_get == "-p" // within port range - set
			&& port > MIN_PORT && port <= MAX_PORT) {
					cout << msg[SET_PORT] << port << endl;
					return 0;
			}
			else {
			    cout << msg[INVALID_PORT] << endl;
				usage(lang);
				return 1;
			}
		}
		else if (argc == 2) { // check for 2 - valid flag input
			type_get = string(args[1]); // flag
			
			if (type_get == "--about" || type_get == "-!") {
				about(lang);
				return 0;
			}
			else if (type_get == "--version" || type_get == "-v") {
				cout << msg[VERSION] << endl;
				return 0;
			}
			else if (type_get == "--help" || type_get == "-h" || type_get == "-?") {
				usage(lang);
				return 0;
			}
			else if (type_get == "--port" || type_get == "-p") { // no port given
			    cout << msg[NO_PORT] << endl; 
				usage(lang);
			    return 1;
			}
			else {
			    cout << msg[INVALID_FLAG] << endl;
			    usage(lang);
			    return 1;
			}
		}
		else { // only <1
		    cout << msg[NO_FLAG] << endl;
			usage(lang);
			return 0;
		}
	}
}
