#include <fstream>
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;
// TODO: simplify printing?
// change environment to accept a custom port variable

// look through all files and revise if nessessary /w 
// finalize
// submit

void print(string file_type)
{
	string output;
	ifstream infile; // english	
	infile.open(file_type);
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
	if (lang == 1) {
		print("portsetter.about_en.txt");
	}
	else if (lang == -1) {
		print("portsetter.about_es.txt");
	}
}

void usage(int lang)
{	
	/* // hardcoded
	cout << "Usage: -p, --port [PORT NUMBER]...\n" << endl;
	cout << "\tOPTIONS:\n\t--port " <<
			"\n\t\tOR\n\t-p\n" << "Listen on a port between 0 and 65536" << endl;
	*/
	if (lang == 1) {
		print("portsetter.usage_en.txt");
	}
	else if (lang == -1) { // spanish
		print("portsetter.usage_es.txt");
	}
}

enum {
	DEFAULT_PORT, // "Listening on default port " 
	SET_PORT, // "Listening on port "
	EXCEED_LIMIT, // "error: too many arguments...   return 1"
	NO_PORT, // "error: no port given...   return 1"
	NO_FLAG, // "error: no arguments given...   return 0"
	INVALID_PORT, // "error: invalid port...  return 1"
	INVALID_FLAG, // "error: invalid flag...   return 1"
};

string en[] = {
	"\nListening on default port ",
	"\n\tListening on port ",
	"error: too many arguments...   return 1", // errors
	"error: no port given...   return 1",
	"error: no arguments given...   return 0",
	"error: invalid port...  return 1",
	"error: invalid flag...   return 1"
};

string es[] = {
	"\nEscucha en el puerto por defecto",
	"\n\tEscuchando en el puerto",
	"Error: demasiados argumentos ... volver 1", // errors
	"Error: no determinado puerto ... volver 1",
	"Error: no hay argumentos dados ... volver 0",
	"Error: puerto no válido ... volver 1",
	"Error: El indicador no válido ... volver 1"
};

int main(int argc, char *args[])
{
	const int MIN_PORT = 0, MAX_PORT = 65536; // I know we don't usually put this here but I am doing it anyway
	
	string* msg = en; // defualt
	int lang = 1; // default
	char* locale = getenv("LANGUAGE");
	if (locale == "es" || locale == "es.MX" || locale == "es.UTF-8" || locale == "es.MX.UTF-8") {
		lang = -1;
		msg = es;
	}
	else {
		cout << "Language defaulting to english." << endl;
	}
	
	for (int i = argc - 1; i > 0; i--) // -1 because don't want ./file
	{	
		if (argc >= 4) { // check for more than four (exceeds possible limit)
		    cout << msg[EXCEED_LIMIT] << endl;
			usage(lang);
			return 1;
		}
		else if (argc == 3) { // check for 3
			string type_get = string(args[1]);
			char* def_port = args[2];
			int port = atoi(args[2]);
			
			if (def_port == (string)"-e") {
					 def_port = getenv("PORT");
					 cout << msg[DEFAULT_PORT] << def_port << endl;
					 return 0;
			}
			// correct flag and within port range
			if (type_get == "--port" || type_get == "-p" && port > MIN_PORT && port <= MAX_PORT) {
					cout << msg[SET_PORT] << port << endl;
					return 0;
			}
			else {
			    cout << msg[INVALID_PORT] << endl;
				usage(lang);
				return 1;
			}
		}
		if (argc == 2) { // check for 2
			string type_get = string(args[1]);

			if (type_get == "--about" || type_get == "-!") {
				about(lang);
				return 0;
			}
			else if (type_get == "--version" || type_get == "-v") {
				cout << "v_1.2.3" << endl;
				return 0;
			}
			else if (type_get == "--help" || type_get == "-h" || type_get== "-?") {
				usage(lang);
				return 0;
			}
			else if (type_get == "--port" || type_get == "-p") {  // error no port given
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