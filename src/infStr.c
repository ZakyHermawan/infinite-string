/**
 * @file
 * */
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "infstr.h"

int main() {
  infStr str;
  initStr(&str);
  fillStr(&str, "lmao", 4);
  append(&str, "wikwok", 6);
  printf("%s\n", str.str);
  deallocStr(&str);

  return 0;
}


/**
 * @brief Initialize infStr.
 *
 * This function should be called after infStr created.
 *
 * @return initialized str object.
 * @param str str object.
 */

infStr* initStr(infStr* str) {
  allocStr(str, 2);
  str->len = 0;
  str->start = str->str;
  str->end = str->str;
 return str;
}


/**
 * @brief fill the string from the beginning.
 * 
 * Will fill the function from the beginning of the pointer
 * Should be called when first time you want to fill in the function
 *
 * \warning Make sure the string is null terminated
 * if the input string is literal string, make sure you append + 1 to include the null byte
 *
 * @return initialized str object.
 * @param str str object.
 * @param chars input characters
 * @param num length of chars
 */

int fillStr(infStr* str, char* chars, int num) {
  if(num < 0) {
    fprintf(stderr, "string length cannot be negative");
    exit(-1);
  }
  int alloc = str->allocSize;
  while(alloc < num) {
    alloc = alloc * 2;
  }
  allocStr(str, alloc);
  char* ptr = chars;
  strncpy(str->str, chars, num);
  str->len = num;

  return num;
}

/**
 * @brief Append chars to the end of InfStr
 * @param str infStr object
 * @param chars new characters that need to be appended
 * @param num new character length
 * @todo clean and optimize allocation strategy
 *
 * */

infStr* append(infStr* str, char* chars, int num) {
  int alloc = 1;
  if(str->len + num >= str->allocSize) {
    
    alloc = str->allocSize;
    // allocate new memory
    while(alloc < num + str->len) {
      alloc = alloc * 2;
    }
    // simpan char lama, dealloc, balikin
    char* save = (char*) malloc(sizeof(char)*str->len+num+1);
    int old_len  = str->len;
    strncpy(save, str->str, str->len);
    strncat(save, chars, num);
   
    free(str->str);
    allocStr(str, alloc);
    str->str = save;
    str->len = old_len + num;
    str->allocSize = alloc;
    str->start = str->str;
    str->end = str->str + str->len;
    return str;
    
  }
  // string aman
  strncat(str->str, chars, num);
  str->len = str->len + num;
  return str;
}

/**
 *  @brief Clear the string
 *
 *  @return number of character that has been cleared
 *  @param str infStr object
 * */

int clear(infStr* str) {
  str->str = str->start;
  
  str->end = str->start;
  return str->len;
}


/**
 * @brief allocating memory
 * @return Number of character that has been allocated
 * @param str infStr obj
 * */
int allocStr(infStr* str, int num) {
  str->str = (char*) malloc(sizeof(char)*num);
  str->allocSize = num;
  return str->allocSize;
}


/**
 * @brief deallocating memory
 * should be called before lifetme of infStr end
 * @param str InfStr object
 * */
void deallocStr(infStr* str) {
  str->end = str->start = 0;
  str->len = 0;
  free(str->str);
}


