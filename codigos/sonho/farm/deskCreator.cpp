#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <fstream>
#include <cstdlib>

#define MAXPATHLEN 1000

using namespace std;

int main(int argc, char* argv[]) {
	string exec;
	exec += "farm/learncodecpp";
	
	string icon;
	icon += "farm/imagens/icon.png";
	
	string nome;
	nome += "learncodecpp";
	
	char path[MAXPATHLEN];
	getcwd(path, MAXPATHLEN);
	
	string path2;
	path2 += path;
	
	string script = "\
[Desktop Entry]\n\
Name=" + nome + "\n\
Exec=" + path2 + "/" + exec + "\n\
Icon=" + path2 + "/" + icon + "\n\
Type=Application\n\
Path=" + path2 + "/farm/\n\
";
	
	cout << script << endl;
	
	fstream file;
	string filename = nome + ".desktop";
	file.open(filename.c_str(), fstream::out);
	
	file << script;
	
	file.close();
	
	string perm;
	
	perm = "chmod +x " + nome + ".desktop";
	
	system(perm.c_str());
	
	cout << perm << endl;
	
	return 0;
}
