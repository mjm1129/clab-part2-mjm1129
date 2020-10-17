#include <stdio.h>
#include <assert.h>

#include <string.h>


// Return the length of the string pointed to by "s".
//
// Note: C standard library function strlen accomplishes
// exactly the same functionality as string_len. In this exercise,
// please do not use strlen. In subsequent exercises (list.c, htable.c),
// it is recommended that you use strlen instead of string_len
int string_len(char *s)
{
  int count = 0;
  while (*s) {
    count += 1;
    s += 1;
  }
  return count;

}

// Compare strings "s1" and "s2". It returns less than, equal to or great than zero
// if "s1" is found to be less than, match, or larger than "s2" alphabetically.
// For example, string_cmp("aa", "aaa") should return a negative number
// and string_cmp("aa", "a0") should return a positive number
// Note that we use the ASCII values of characters as basis for comparison.
// As the ascii value of 'a' is greater than the ascii value of '0',
// "aa" is considered to be greater than "a0".
//
// Note: C standard library function strcmp accomplishes
// exactly the same functionality as string_cmp. In this exercise,
// please do not use strcmp. In subsequent exercises (list.c, htable.c),
// it is recommended that you use strcmp instead of string_cmp.
int string_cmp(char *s1, char *s2)
{
  // printf("s1 = %s, s2 = %s which is %d | ", s1, s2, s1 > s2);

  // if (s1 > s2){
  //   return 1;
  // } else if (s1 < s2){
  //   return -1;
  // } else {
  //   return 0;
  // }
  
  int s1_num = 0;
  int s2_num = 0;
  
  while (*s1 && *s2){
    s1_num += *s1;
    s2_num += *s2;
    s1 += 1;
    s2 += 1;
  }
  
  if (s1_num == s2_num){
    if (string_len(&s1[0]) > string_len(&s2[0])){
      return 1;
    } else if (string_len(&s1[0]) < string_len(&s2[0])){
      return -1;
    }
    return 0;
  } else if (s1_num > s2_num){
    return 1;
  } else {
    return -1;
  }

}

// Convert integer x into hex format and store the resulting hex string to "str",
// e.g., if x=16, then str should be "00000010".
// If x=26, then str should be "0000001a";
// The resulting hex string should always have exactly 8 hex characters
// followed by the null character.
// We assume the caller has allocated an array of at least 9 characters for "str",
// Note: please do not use formatted output, such as sprintf
void int_to_hex(unsigned int x, char *str)
{
  int base[8] = {268435456, 16777216, 1048576, 65536, 4096, 256, 16, 1};
  char outputbuff[16] = "0123456789abcdef";

  int start_index = 0;

  while (x < base[start_index]){
      start_index += 1;
  }


  for (int i = 0; i < 8; i++){
    int temp = x / base[i];

    str[i] = outputbuff[temp];
    x -= base[i] * temp;
  }

}

