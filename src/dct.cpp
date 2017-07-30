#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <sys/stat.h>
#include <string>
#include "version.h"

int main() {

	static char version[] = VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH "." VERSION_BUILD;
	static char timestamp[] = __DATE__ " " __TIME__;
	
    printf("Checking root directory structure\n");
    struct stat projbuff;
    int projects = 0;
	struct stat pubbuff;
    int publish = 0;
	
    if (stat("projects", &projbuff) != -1) {
       if (S_ISDIR(projbuff.st_mode)) {
          projects = 1;
       }
    } else {
       system(("mkdir projects"));
    }
	
    if (stat("publish", &pubbuff) != -1) {
       if (S_ISDIR(pubbuff.st_mode)) {
          publish = 1;
       }
    } else {
       system(("mkdir publish"));
    }
	
	printf("Directory structure confirmed!\n\n");
	
	using std::string;
    using std::cin;
    using std::cout;
	string projectname;
	
	printf("\n");
    printf("**** Created for Developers.***********************************\n");
    printf("Coded by DevWorks OSI dot Com.                                *\n");
    printf("Freedom in Open Source.                                       *\n");
	printf("Please use versioning, IE: yourproject-1.1.0.                 *\n");
	printf("The last number in your projects version is the recent build. *\n");
	printf("Version 1.1.0 becomes 1.1.1 and so forth on each new build.   *\n");
	printf("***************************************************************\n");
	
	// Let's begin work
	std::cout << "Enter your project folders name: ";
	std::cin >> projectname;
	
	// Create the projects folder in the publish directory
	printf("Creating your projects folders.\n");
	system(("mkdir publish/" + projectname).c_str());
	system(("mkdir publish/" + projectname + "/hash").c_str());
	system(("mkdir publish/" + projectname + "/hash/zip").c_str());
	system(("mkdir publish/" + projectname + "/hash/gzip").c_str());
	system(("mkdir publish/" + projectname + "/hash/sha1").c_str());
	system(("mkdir publish/" + projectname + "/hash/sha256").c_str());
	system(("mkdir publish/" + projectname + "/hash/bz2").c_str());

	printf("Compressing your application.\n");
	system(("tar -cf " + projectname + ".tar " + projectname).c_str());
	system(("tar -czf " + projectname + ".tar.gz " + projectname).c_str());
	system(("zip -rq " + projectname + ".zip " + projectname).c_str());
	system(("bzip2 -zq --fast " + projectname + ".tar ").c_str());
	
	printf("Hashing your application.\n");
	system(("md5sum " + projectname + ".zip > zip-md5.log").c_str());
    system(("md5sum " + projectname + ".tar.gz > gzip-md5.log").c_str());
	system(("md5sum " + projectname + ".tar.bz2 > bz2-md5.log").c_str());
	system(("sha1sum " + projectname + ".zip > zip-sha1.log").c_str());
    system(("sha1sum " + projectname + ".tar.gz > gzip-sha1.log").c_str());
	system(("sha1sum " + projectname + ".tar.bz2 > bz2-sha1.log").c_str());
	system(("sha256sum " + projectname + ".zip > zip-sha256.log").c_str());
    system(("sha256sum " + projectname + ".tar.gz > gzip-sha256.log").c_str());
	system(("sha256sum " + projectname + ".tar.bz2 > bz2-sha256.log").c_str());
	
	printf("Publishing your application.\n");
	system(("mv " + projectname + ".tar.gz publish/" + projectname + "/").c_str());
    system(("mv " + projectname + ".zip publish/" + projectname + "/").c_str());
	system(("mv " + projectname + ".tar.bz2 publish/" + projectname + "/").c_str());
	system(("mv zip-md5.log publish/" + projectname + "/hash/zip/").c_str());
    system(("mv gzip-md5.log publish/" + projectname + "/hash/gzip/").c_str());
	system(("mv bz2-md5.log publish/" + projectname + "/hash/bz2/").c_str());
	system(("mv zip-sha1.log publish/" + projectname + "/hash/sha1/").c_str());
    system(("mv gzip-sha1.log publish/" + projectname + "/hash/sha1/").c_str());
	system(("mv bz2-sha1.log publish/" + projectname + "/hash/bz2/").c_str());
	system(("mv zip-sha256.log publish/" + projectname + "/hash/sha256/").c_str());
    system(("mv gzip-sha256.log publish/" + projectname + "/hash/sha256/").c_str());
	system(("mv bz2-sha256.log publish/" + projectname + "/hash/bz2/").c_str());
	
	printf("Cleaning up.\n");
	system(("rm -Rf " + projectname + ".tar").c_str());
	system(("mv " + projectname + " projects/").c_str());
	
	printf("\n\n");
	printf("All done.\n");
	printf("Your application can be found in the publish directory.\n");
	printf("\n\n");
	
	return 0;
}
