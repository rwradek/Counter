#define  _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "kv.h"

kvarray_t * readKVs(const char * fname) {
  //WRITE ME
  FILE * f = fopen(fname,"r");
  if(f == NULL) {
    perror("Connot open file");
    return NULL;
  }

  //#####################################
  kvarray_t * kva = malloc(sizeof(*kva));
  kva->arry = NULL;
  kva->arry_len = 0; 

  char * line = NULL;
  size_t sz = 0;
  size_t i = 0;

  char * val_p = NULL;
  char * enter_p = NULL;
  while(getline(&line,&sz,f) >= 0){

    kva->arry = realloc(kva->arry, (i + 1) * sizeof(*(kva->arry)));
    //val_p = strtok(line,"=");
    //val_p = strtok(NULL,"=");
    enter_p = strchr(line,0x0A);
    if (enter_p) {
      *enter_p = 0;  
    }
    val_p = strchr(line,'=');
    *val_p = 0;
    val_p++;
    //printf(">> %s",val_p);
    kva->arry[i].key = line;
    kva->arry[i].value = val_p;  
    kva->arry_len = (i + 1);
    i++;
    line = NULL;

  }
  free(line);

  if(fclose(f)!=0) {
    perror("Cannot close file");
    return NULL;
  }
  return kva;
}

void freeKVs(kvarray_t * pairs) {
  //WRITE ME
  for(size_t i=0;i<pairs->arry_len;i++){
      free(pairs->arry[i].key); // value - is same location as key, but invalid
  }
  //#########################
  free(pairs->arry);
  free(pairs);
}

void printKVs(kvarray_t * pairs) {
  //WRITE ME
  for(size_t i=0;i<pairs->arry_len;i++){
    printf("key = '%s' value = '%s'\n",
      pairs->arry[i].key,
      pairs->arry[i].value);
  }
}

char * lookupValue(kvarray_t * pairs, const char * key) {
  //WRITE ME
  for(size_t i=0;i<pairs->arry_len;i++){
      if (strcmp(pairs->arry[i].key,key) == 0) {
        return pairs->arry[i].value;
      }
  }
  return NULL;
} 