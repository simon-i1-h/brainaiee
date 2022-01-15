# Brainaiee programming language

Brainaiee is a dialect of the brainfuck programming language. Brainaiee was developed to resolve EOF problem of the brainfuck. Brainaiee has two new operators.

- `:`: Store 1 if the output stream is set to EOF, otherwise 0 in the cell at the pointer.
- `;`: Store 1 if the input stream is set to EOF, otherwise 0 in the cell at the pointer.

## Build

```
cc -o brainaiee brainaiee.c
```

## Run

```
./brainaiee source.ba
```
