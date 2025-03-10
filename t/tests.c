#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struppercase.h"

void test_upcase_single_char() {
  char* word = strdup("a");
  struppercase(word);
  assert(memcmp(word, "A", 2) == 0);
  free(word);
}

void test_upcase_last_char() {
  char* word = strdup("aB");
  struppercase(word);
  assert(memcmp(word, "AB", 3) == 0);
  free(word);
}

void test_upcase_first_char() {
  char* word = strdup("Ab");
  struppercase(word);
  assert(memcmp(word, "AB", 3) == 0);
  free(word);
}

void test_upcase_whole_string() {
  char* word = strdup("ab");
  struppercase(word);
  assert(memcmp(word, "AB", 3) == 0);
  free(word);
}

void test_no_change_if_already_uppercase() {
  char* word = strdup("AB");
  struppercase(word);
  assert(memcmp(word, "AB", 3) == 0);
  free(word);
}

void test_noop_if_empty_string() {
  char* word = strdup("");
  struppercase(word);
  assert(memcmp(word, "", 1) == 0);
  free(word);
}

void test_must_not_upper_case_after_length() {
  char* word = strdup("abc");
  strnuppercase(word, 2);
  assert(memcmp(word, "ABc", 4) == 0);
  free(word);
}

void test_must_not_end_if_word_is_smaller_than_length() {
  char* word = strdup("abc");
  strnuppercase(word, 6);
  assert(memcmp(word, "ABC", 4) == 0);
  free(word);
}

void test_must_not_uppercase_if_length_is_zero() {
  char* word = strdup("abc");
  strnuppercase(word, 0);
  assert(memcmp(word, "abc", 4) == 0);
  free(word);
}

int main(void) {
  printf("test struppercase\n");
  test_upcase_single_char();
  test_upcase_last_char();
  test_upcase_first_char();
  test_upcase_whole_string();
  test_no_change_if_already_uppercase();
  test_noop_if_empty_string();
  test_must_not_upper_case_after_length();
  test_must_not_end_if_word_is_smaller_than_length();
  test_must_not_uppercase_if_length_is_zero();
  printf("done\n");
  return 0;
}
