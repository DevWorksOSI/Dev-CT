#include <iostream>
#include <string>
#include <cstdlib>
#include <stdio.h>
#include "version.h"

int main()
{
    static char version[] = VERSION_MAJOR "." VERSION_MINOR "." VERSION_PATCH "." VERSION_BUILD;
    static char timestamp[] = __DATE__ " " __TIME__;
   
    using std::string;
    using std::cin;
    using std::cout;
    string projectname;

    printf("\n");
    printf("**** Created for Developers.****\n");
    printf("Coded by TweDev dot Com.\n");
    printf("Freedom in Open Source.\n");
    printf("********************************\n");


    std::cout << "Enter your project folders name: ";
    std::cin >> projectname;

    // Idea is to call tar, gzip and zip

    // add the different parts into a string
    // then convert to a char const* using c_str()

    // create the project folder
    printf("Creating your projects folders.\n");
    system(("mkdir projects/" + projectname).c_str());
    system(("mkdir projects/" + projectname + "/hash").c_str());
    system(("mkdir projects/" + projectname + "/hash/zip").c_str());
    system(("mkdir projects/" + projectname + "/hash/gzip").c_str());
    system(("mkdir projects/" + projectname + "/hash/sha1").c_str());
    system(("mkdir projects/" + projectname + "/hash/sha256").c_str());
    system(("mkdir projects/" + projectname + "/hash/bz2").c_str());

    printf("Compressing your application.\n");
    system(("tar -cf " + projectname + ".tar " + projectname + "").c_str());
    printf("Creating a gzip version.\n");
    system(("gzip -9 " + projectname + ".tar ").c_str());
    printf("Creating a zip version.\n");
    system(("zip -rq " + projectname + ".zip " + projectname).c_str());
    printf("Creating a bz2 version.\n");
    system(("tar -cf " + projectname + ".tar " + projectname + "").c_str());
    system(("bzip2 -zq --fast " + projectname + ".tar ").c_str());
    
    printf("\n\n");
    printf("Hashing your Compressed Files.\n");
    printf("\n\n");
    printf("MD5.\n");
    system(("md5sum " + projectname + ".zip > zip-md5.log").c_str());
    system(("md5sum " + projectname + ".tar.gz > gzip-md5.log").c_str());
    system(("md5sum " + projectname + ".tar.bz2 > bz2-md5.log").c_str());

    printf("\n\n");
    printf("SHA1.\n");
    system(("sha1sum " + projectname + ".zip > zip-sha1.log").c_str());
    system(("sha1sum " + projectname + ".tar.gz > gzip-sha1.log").c_str());
    system(("sha1sum " + projectname + ".tar.bz2 > bz2-sha1.log").c_str());

    printf("\n\n");
    printf("SHA256.\n");
    system(("sha256sum " + projectname + ".zip > zip-sha256.log").c_str());
    system(("sha256sum " + projectname + ".tar.gz > gzip-sha256.log").c_str());
    system(("sha256sum " + projectname + ".tar.bz2 > bz2-sha256.log").c_str());
   
    printf("\n\n");
    printf("Publishing your application to the projects folder.\n");
    system(("mv " + projectname + ".tar.gz projects/" + projectname + "/").c_str());
    system(("mv " + projectname + ".zip projects/" + projectname + "/").c_str());
    system(("mv " + projectname + ".tar.bz2 projects/" + projectname + "/").c_str());
    
    printf("\n\n");
    printf("Publishing your MD5, SHA1, and SHA256 Hash Sums to the hash folder for your project.\n");

    system(("mv zip-md5.log projects/" + projectname + "/hash/zip/").c_str());
    system(("mv gzip-md5.log projects/" + projectname + "/hash/gzip/").c_str());
    system(("mv bz2-md5.log projects/" + projectname + "/hash/bz2/").c_str());

    system(("mv zip-sha1.log projects/" + projectname + "/hash/sha1/").c_str());
    system(("mv gzip-sha1.log projects/" + projectname + "/hash/sha1/").c_str());
    system(("mv bz2-sha1.log projects/" + projectname + "/hash/bz2/").c_str());

    system(("mv zip-sha256.log projects/" + projectname + "/hash/sha256/").c_str());
    system(("mv gzip-sha256.log projects/" + projectname + "/hash/sha256/").c_str());
    system(("mv bz2-sha256.log projects/" + projectname + "/hash/bz2/").c_str());

    printf("\n\n");
    printf("ALL DONE!.\n");

    return 0;
}
