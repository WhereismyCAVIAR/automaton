#include <stdio.h>
#include <regex.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  regex_t preg;
  int result, match_count;
  regmatch_t match;
  char *target = "bibbidibobbidiboo";

  // Compile the regular expression pattern
  result = regcomp(&preg, "(b|a)ib*", REG_EXTENDED);
  if (result != 0) {
    printf("fail to compile regex\n");
    return 1;
  }

  // Perform the pattern matching
  match_count = 0;
  result = regexec(&preg, target, 1, &match, 0);
  while (result == 0) {
    printf("pattern match succeeded\n");
    printf("Match: %.*s\n", (int)(match.rm_eo - match.rm_so), target + match.rm_so);
    target += match.rm_eo;
    match_count++;
    result = regexec(&preg, target, 1, &match, 0);
  }
  if (result != REG_NOMATCH) {
    printf("fail to execute regrex\n");
    return 1;
  }

  regfree(&preg);

  return 0;
}