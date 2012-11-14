// libpsql.cc
#include <string.h>
#include <stdio.h>
#include <libpq-fe.h>
#include "dart_api.h"

Dart_NativeFunction ResolveName(Dart_Handle name, int argc);

DART_EXPORT Dart_Handle psql_Init(Dart_Handle parent_library) {
  if (Dart_IsError(parent_library)) return parent_library;

  Dart_Handle result_code =
      Dart_SetNativeResolver(parent_library, ResolveName);
  if (Dart_IsError(result_code)) return result_code;

  return Dart_Null();
}

Dart_Handle HandleError(Dart_Handle handle) {
 if (Dart_IsError(handle)) Dart_PropagateError(handle);
 return handle;
}

void Connect(Dart_NativeArguments args) {
    Dart_EnterScope();
    PGconn *conn;
    const char *conninfo = "user=postgres password=postgres host=localhost port=5432";
    conn = PQconnectdb(conninfo);

    /* Check to see that the backend connection was successfully made */
    if (PQstatus(conn) != CONNECTION_OK)
    {
        fprintf(stderr, "Connection to database failed: %s",
                PQerrorMessage(conn));
        PQfinish(conn);
    }

  Dart_Handle result = HandleError(Dart_NewInteger((int64_t)0));
  Dart_SetReturnValue(args, result);

  Dart_ExitScope();
}

Dart_NativeFunction ResolveName(Dart_Handle name, int argc) {
  assert(Dart_IsString8(name));
  const char* cname;
  Dart_Handle check_error = Dart_StringToCString(name, &cname);
  if (Dart_IsError(check_error)) Dart_PropagateError(check_error);
  Dart_NativeFunction result = NULL;
  if (strcmp("Connect", cname) == 0) result = Connect;
  Dart_ExitScope();
  return result;
}
