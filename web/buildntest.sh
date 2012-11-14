#!/bin/bash
cd src/
g++ -O2 -DDART_SHARED_LIB -I$HOME/work/tools/dart/dart-sdk/include -rdynamic -fPIC -shared libpsql.cc -lpq -I/usr/include/postgresql -o libpsql.so
mv libpsql.so ../lib/
cd ../lib/
$HOME/work/tools/dart/dart-sdk/bin/dart test_dart.dart
