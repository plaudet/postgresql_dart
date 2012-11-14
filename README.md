postgresql_dart
==============

Driver postgresql for Dart

Compile Command Line
====================

g++ -O2 -DDART_SHARED_LIB -I/home/<user>/dart/dart-sdk/include -rdynamic -fPIC -shared libpsql.cc -lpq -I/usr/include/postgresql -o libpsql.so

Test Command
============