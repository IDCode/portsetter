#include <iostream>
#include <stdlib.h>
using namespace std;
// Yes, I agree that this is a filthy way to test multiple things, but 
// it works.
int main()
{
    char* locale = getenv("LANGUAGE");
    // Positive Tests
    int statusCode = system("./portsetter") / 256;
    if (statusCode != 0) {
       cout << "\nPASS 1... (print usage)\n" << endl;
    }
    statusCode = system("./portsetter -h") / 256;
    if (statusCode != 0) {
       cout << "\nPASS 2... -h (print usage)\n" << endl;
    }
    statusCode = system("./portsetter --help") / 256;
    if (statusCode != 0) {
       cout << "\nPASS 3... --help (print usage)\n" << endl;
    }
    statusCode = system("./portsetter -p 40") / 256;
    if (statusCode != 0) {
       cout << "\nPASS 4... -p 40 (print port)\n" << endl;
    }
    statusCode = system("./portsetter --port 30") / 256;
    if (statusCode != 0) {
       cout << "\nPASS 5... --port 30 (print port)\n" << endl;
    }
    
    // Negative Tests
    statusCode = system("./portsetter help") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 1... help (flag incorrectly spelt)\n" << endl;
    }
    
    statusCode = system("./portsetter -help") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 2... -help (flag incorrectly spelt)\n" << endl;
    }
    
    statusCode = system("./portsetter --h") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 3... --h (too many dashes)\n" << endl;
    }
    
    statusCode = system("./portsetter -h --help") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 4... -h --help (too many flags)\n" << endl;
    }
    
    statusCode = system("./portsetter -hs") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 5... -hs (invalid flag)\n" << endl;
    }
    
    statusCode = system("./portsetter -p --port 9") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 6... -p --port 9 (too many flags)\n" << endl;
    }
    
    statusCode = system("./portsetter -p 70 33") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 7... -p 70 33 (too many ports given)\n" << endl;
    }
    
    statusCode = system("./portsetter -p -21") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 8... -p -21 (negative port... must be greater than 0)\n" << endl;
    }
    
    statusCode = system("./portsetter -p 0") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 9... -p 0 (port must be greater than 0)\n" << endl;
    }
    
    statusCode = system("./portsetter --port") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 10... --port (invalid port... no port given)\n" << endl;
    }
    
    statusCode = system("./portsetter -p 90642") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 11... -p 90642 (invalid port... port exceeds limit)\n" << endl;
    }
    
    statusCode = system("./portsetter -x 45321") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 12... -x 45321 (invalid flag)\n" << endl;
    }
    
    statusCode = system("./portsetter -P 714") / 256;
    if (statusCode != 0) {
       cout << "\nFAIL TEST 13... -P 714 (invalid flag)\n" << endl;
    }
    // Spanish check
    if (locale == "es" || locale == "es.MX" || locale == "es.UTF-8" || locale == "es.MX.UTF-8") {
		cout << "PASS TEST - Spanish found..." << endl;
	}
	else {
	    cout << "FAIL TEST - Spanish not found..." << endl;
	}
    
}