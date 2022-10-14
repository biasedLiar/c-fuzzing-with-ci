#include "utility.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  // char *test = charEncode("lik input men der &, < og > er erstattet");
  char *test1 = charEncode("");

  printf("%s\n", test1);
}

#pragma once

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replaceCharV2(char *message, char searchFor, char *replaceWith) {
  printf("%c\n", message[2]);
  int length = (int)strlen(message);
  int replaceLength = (int)strlen(replaceWith);

  int numReplacements = 0;
  for (int i = 0; i < length; i++) {
    if (message[i] == searchFor) {
      numReplacements++;
    }
  }

  char *outString = malloc(length + (replaceLength - 1) * numReplacements);

  int index = 0;
  for (int i = 0; i < length; i++) {
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
  return outString;
}

char *charEncode(char *message) {
  char *v1 = replaceCharV2(message, '&', "&amp");
  char *v2 = replaceCharV2(v1, '<', "&lt");
  char *v3 = replaceCharV2(v2, '>', "&gt");
  char *out = NULL;
  out = malloc((int)strlen(v3));
  strcpy(out, v3);
  return out;
}

#include "utility.h"
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size) {
  // Create a c string from fuzzer data (with an additional byte set to '\0')
  char *str = (char *)malloc(sizeof(char) * size + 1); // Create a c-string of length size + 1
  memcpy(str, data, size);                             // Copy fuzzer data to string
  str[size] = '\0';                                    // Set last byte of allocated string to '\0'

  char *test = charEncode(str);
  printf("%s\n", test);
  free(str);

  return 0;
}
