#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "counts.h"

counts_t * createCounts(void) {
  //WRITE ME
  counts_t * counts = malloc(sizeof(*counts));
  counts->arry = NULL;
  counts->arry_len = 0;
  counts->unknown_no = 0;
  return counts;
}

int key_index(counts_t * c, const char * key){
  for(size_t i=0;i<c->arry_len;i++){
    if(strcmp(c->arry[i].key,key)==0){
      return i;
    }
  }
  return -1;
}

void addCount(counts_t * c, const char * name) {
  //WRITE ME
  if (name == NULL){
    c->unknown_no++;
    return;
  }
  
  int i;
  if((i = key_index(c,name)) >=0) {
    c->arry[i].no++;
    return;
  }
  

  c->arry = realloc(c->arry,(c->arry_len + 1) * sizeof(*(c->arry)));
  c->arry[c->arry_len].no = 1;
  c->arry[c->arry_len].key = malloc((strlen(name) + 1) * sizeof(*name));
  strcpy(c->arry[c->arry_len].key,name);
  //ERROR HANDLING
  c->arry_len++;
}

void printCounts(counts_t * c, FILE * outFile) {
  //WRITE ME
  for(size_t i=0;i<c->arry_len;i++){
      fprintf(outFile,"%s: %lu\n",c->arry[i].key,c->arry[i].no);
    }
  if (c->unknown_no > 0){
    fprintf(outFile,"<unknown> : %lu\n",c->unknown_no);
  }
}

void freeCounts(counts_t * c) {
  //WRITE ME
  for(size_t i=0;i<c->arry_len;i++){
    free(c->arry[i].key);
    }
  free(c->arry);
  free(c);
}