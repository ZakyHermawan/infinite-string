/** \file */

/**
 * @brief struct for infinite string
 * */
struct infStr { /// <Docs for struct
  char* str; /// <Docs for str
  int len; /// <Docs for len
  int allocSize; /// <Docs for allocSize
  char* start; /// <Docs for start
  char* end; /// <Docs for end
};

// type definition
typedef struct infStr infStr;



infStr* initStr(infStr* str);
int fillStr(infStr* str, char* chars, int num);
infStr* append(infStr* str, char* chars, int num);
int clear(infStr* str);
int allocStr(infStr*str, int num);
void deallocStr(infStr*str); 


