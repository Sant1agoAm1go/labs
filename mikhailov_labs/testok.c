#include <stdio.h>
int isEnd(char ch) { return ch == '\0' || ch == -1;
}
int isHave(char ch, const char* str) { if (str == NULL) return -1; for (size_t i = 0; !isEnd(str[i]); i++) if (str[i] == ch) return 1; return 0;
}
size_t strlen(const char* str) { if (str == NULL) return 0; size_t res = 0; for (size_t i = 0; !isEnd(str[i]); i++) res++; return res;
}
char* strtok(char* _String, const char* _Delimeter) { size_t len;  char* string; size_t position; if (_String) { printf("Hello!"); len = strlen(_String); position = 0; for (size_t i = 
                0; i < len; i++) {
                        printf("Hello2!"); if (isHave(_String[i], _Delimeter)) { printf("%ld", len); _String[i] = -1;
                        }
                }
                string = _String; printf("%s", string); return string;
        }
        while(string[0] != -1 && position < len) { position++; string++;
        }
        while (string[0] == -1 && position < len) { position++; string++;
        }
        return string;
}
int main () { char* str = "Haha hihi first";
 
  printf("123"); char * pch = strtok (str," "); // во втором параметре указаны разделитель (пробел, запятая, точка, тире)
 
  while (pch != NULL) { printf("%s", pch); pch = strtok (NULL, " ");
  }
  return 0;
}
