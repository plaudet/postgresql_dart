#library("psql");

#import("dart-ext:psql");

class Database {
  var mDb;
  var mUser;
  var mDbname;
  var mPasswd;
  var mHost;
  var mPort;
  var mTable;

  //String toString() => "<PostgreSQL: $user@$_host:$_port/$_table>";
  Database(host,user,passwd,dbname) : this.mUser = user, this.mHost = host, this.mPasswd = passwd, this.mDbname = dbname  {
    //mDb = _connect(host,user,passwd,dbname);
    _connect(host,user,passwd,dbname);
  }

}
_connect(host,user,passwd,dbname) native 'Connect';