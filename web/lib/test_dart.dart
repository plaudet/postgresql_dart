#import('psql.dart');

main() {
  var database = new Database('localhost', 'mbutler', 'test', 'test');

  if(database != null) {
    print('worked?');
  }
}