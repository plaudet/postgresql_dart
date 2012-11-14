postgresql_dart
==============

Driver postgresql for Dart

Compile Command Line
====================

g++ -O2 -DDART_SHARED_LIB -I/home/$USER/dart/dart-sdk/include -rdynamic -fPIC -shared libpsql.cc -lpq -I/usr/include/postgresql -o libpsql.so

Test Command
============

Execute buildntest.sh

Google Group
============

https://groups.google.com/forum/?hl=en&fromgroups#!forum/dart-connector-for-postgres