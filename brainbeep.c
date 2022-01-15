#include <stdio.h>

#define HARDCODED 65536

int main(int argc, char **argv) {
  FILE *f;
  size_t len;

  unsigned char prog[HARDCODED];
  size_t ip;

  unsigned char mem[HARDCODED] = {0};
  size_t addr = 0;

  int c;
  size_t depth;

  if (argc < 2)
    return 1;

  if ((f = fopen(argv[1], "rb")) == NULL)
    return 1;

  len = fread(prog, 1, HARDCODED, f);
  if (ferror(f) != 0 || feof(f) == 0 || fclose(f) != 0)
    return 1;

  for (ip = 0; ip < len; ip++) {
    switch (prog[ip]) {
    case '>':
      addr++;
      break;
    case '<':
      addr--;
      break;
    case '+':
      mem[addr]++;
      break;
    case '-':
      mem[addr]--;
      break;
    case '[':
      if (mem[addr] == 0) {
        depth = 0;
        for (;;) {
          c = prog[++ip];
          if (c == ']' && depth == 0)
            break;
          depth += c == '[';
          depth -= c == ']';
        }
      }
      break;
    case ']':
      if (mem[addr] != 0) {
        depth = 0;
        for (;;) {
          c = prog[--ip];
          if (c == '[' && depth == 0)
            break;
          depth -= c == '[';
          depth += c == ']';
        }
      }
      break;
    case ',':
      c = fgetc(stdin);
      if (ferror(stdin) != 0)
        return 1;
      mem[addr] = c;
      break;
    case '.':
      fputc(mem[addr], stdout);
      fflush(stdout);
      if (ferror(stdout) != 0)
        return 1;
      break;
    case ';':
      mem[addr] = feof(stdin) != 0;
      break;
    case ':':
      mem[addr] = feof(stdout) != 0;
      break;
    case '#':
      while (prog[++ip] != '\n')
        ;
      break;
    case ' ':
    case '\t':
    case '\r':
    case '\n':
      break;
    default:
      return 1;
    }
  }

  return 0;
}
