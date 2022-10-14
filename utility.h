#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replaceCharV2(char *message, char searchFor, char *replaceWith) {
  printf("FunctionStarting\n");
  int length = (int)strlen(message);
  printf("Inside start of function\n");
  int replaceLength = (int)strlen(replaceWith);

  int numReplacements = 0;
  for (int i = 0; i < length; i++) {
    if (message[i] == searchFor) {
      numReplacements++;
    }
  }

  char *outString = malloc(length + (replaceLength - 1) * numReplacements);
  printf("Midway through function, length=%d\n", length + (replaceLength - 1) * numReplacements);
  int index = 0;
  for (int i = 0; i < length; i++) {
    printf("Outstring: %s\n", outString);
    if (message[i] == searchFor) {
      for (int j = 0; j < replaceLength; j++) {
        outString[index] = replaceWith[j];
        index++;
      }
    } else {
      outString[index] = message[i];
      index++;
    }
  }
  printf("Outstring: %s", outString);
  return outString;
}

char *charEncode(char *message) {
  if ((int)strlen(message) < 4) {
    return message;
  }
  printf("beforetest1:\n%s\n", message);
  // int n = message[0] == 'O' && message[1] == 'd' && message[2] == 'o' && message[5] == '\0';
  printf("beforetest2:\n%s\n", message);
  char *v1 = replaceCharV2(message, '&', "&amp");
  printf("beforetest3:\n%s\n", v1);
  char *v2 = replaceCharV2(v1, '<', "&lt");
  free(v1);
  printf("beforetest3.5:\n%s\n", message);
  char *v3 = replaceCharV2(v2, '>', "&gt");
  free(v2);
  printf("beforetest4:\n%s\n", message);
  char *out = NULL;
  out = malloc((int)strlen(v3));
  printf("beforetest5:\n%s\n", message);
  strcpy(out, v3);
  free(v3);
  printf("beforetest6:\n%s\n", message);
  return out;
}

void charTest(char *message) {
  int n = message[0] == 'O' && message[1] == 'd' && message[2] == 'o' && message[5] == '\0';
  printf("%d", n);
}
