# remove binary files before committing

OSX:

find . -type f -perm +111 -print | grep ex
find . -type f -perm +111 -print | grep ex | xargs rm -rf

Linux:

find . -type f -executable -print | grep ex
find . -type f -executable -print | grep ex | xargs rm -rf

TODO: make a shell script and a pre-commit hook to automate this doh
