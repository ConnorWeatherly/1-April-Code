#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

/* code to make the header work */
#define public
#define TreeSort dummy0()

/* define helper functions for Java syntax display */
#define class void setSelf(String* this) {\
                  self = this;\
              }\
              void prntln(int typeCode, ...) {\
                va_list args;\
                va_start(args, typeCode);\
                String string;\
                switch(typeCode) {\
                  case 'c': printf("%c", (char) va_arg(args, int));\
                            break;\
                  case 'i': printf("%d", va_arg(args, int));\
                            break;\
                  case 's': vprintf(va_arg(args, char*), args);\
                            break;\
                  case 'f': printf("%f", va_arg(args, double));\
                            break;\
                  case 'd': printf("%lf", va_arg(args, double));\
                            break;\
                  case 'S': string = va_arg(args, String);\
                            setSelf(&string);\
                            vprintf(string.str, args);\
                            break;\
                }\
                va_end(args);\
                printf("\n");\
              }\
              void prnt(int typeCode, ...) {\
                va_list args;\
                va_start(args, typeCode);\
                String string;\
                switch(typeCode) {\
                  case 'c': printf("%c", (char) va_arg(args, int));\
                            break;\
                  case 'i': printf("%d", va_arg(args, int));\
                            break;\
                  case 's': vprintf(va_arg(args, char*), args);\
                            break;\
                  case 'f': printf("%f", va_arg(args, double));\
                            break;\
                  case 'd': printf("%lf", va_arg(args, double));\
                            break;\
                  case 'S': string = va_arg(args, String);\
                            setSelf(&string);\
                            vprintf(string.str, args);\
                            break;\
                }\
                va_end(args);\
              }\
              char charAtFunc(int idx) {\
                return self->str[idx];\
              }\
              int
#define main()    dummy1 = 0;\
                  return dummy1;\
                }\
                int main(int argc, char* argv[]) {\
                  char newLine = '\n';\
                  mainStruct System;\
                  System.out.println = prntln;\
                  System.out.print = prnt;\
                  if (1)

/* define structures for System.out.print... */
typedef struct {
  void (*println)(int, ...);
  void (*print)(int, ...);
} dummyStruct;

typedef struct {
  dummyStruct out;
} mainStruct;

//#define EXIT_SUCCESS sizeof(free(var)) | 1

/* make strings print properly */
typedef struct _String {
  char* str;
  int length;
  char (*charAt)(int);
  int dummy;
} String;

static String* self;

#define dataType(var) _Generic((var),\
  char:     'c',\
  int:      'i',\
  char*:    's',\
  float:    'f',\
  double:   'd',\
  String:   'S',\
  default:  'e')

#define println(args, ...) println(dataType(args), args, ##__VA_ARGS__)
#define print(args, ...) print(dataType(args), args, ##__VA_ARGS__)

#define new
#define String(arg) {.str = arg, .length = sizeof(arg)-1, .charAt = charAtFunc,\
                    .dummy = sizeof(free(malloc(sizeof(arg))))}

#define length()  length
