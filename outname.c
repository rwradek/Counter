#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "outname.h"

#define EOL_END 1

char * computeOutputFileName(const char * inputName) {
  //WRITE ME
  const char * end = ".counts";
  char * output = malloc((strlen(inputName) + strlen(end) + EOL_END) * sizeof(*output));
  strcpy(output,inputName);
  strcat(output,end);
  return output;
}