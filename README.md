# Brainbeep programming language

Brainbeep is a dialect of the brainfuck programming language. Brainbeep was developed to resolve EOF problem of the brainfuck. Brainbeep has two new operators.

- `:`: Store 1 if the output stream is set to EOF, otherwise 0 in the cell at the pointer.
  - It's similar to a glyph of the `.` (output) operator.
- `;`: Store 1 if the input stream is set to EOF, otherwise 0 in the cell at the pointer.
  - It's similar to a glyph of the `,` (input) operator.

Brainbeep also has the `#` (line comment) operator.

## Build and Run

```
cc -o brainbeep brainbeep.c
./brainbeep source.bbp
```

## Extensions or Dialects

I have some ideas of extensions or dialects. Of course you can create extensions or dialects as you like.

### Traditional behavior

Some Brainbeep's behavior is different from traditional behavior of the brainfuck. You can create extensions or dialects for traditional behavior.

- Remove the `#` (line comment) operator.
- Ignore all characters other than the operators.

### Error handling

You can create extensions or dialects for flexible error handling.

| **Error value** | **Iteration 1**    | **Iteration 2**    | **...** |
| --------------- | ------------------ | ------------------ | ------- |
| **0**           | no error           | something error... | ...     |
| **1**           | EOF                | something error... | ...     |
| **2**           | something error... | ...                | ...     |
| **...**         | ...                | ...                | ...     |
| **255**         | next iteration     | ...                | ...     |

### Large cells

Brainbeep's size of a cell is unsigned char (0\~255). You can create extensions or dialects for large cells (such as int).
