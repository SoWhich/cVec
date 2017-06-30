# cVec
A set of macros to create a system of functions to grow and shrink arrays in
the style of a vector.

## Usage

Move the header file to your source (or include) directory and `#include
"cvec.h"`.

To establish cvec with relation to your target type initialize it with
`CVEC("type")` (substituting "type" with your chosen type without quotes). No
semicolon is needed afterwards. The macro creates a struct called `"type"_vec`
(substituting type with your chosen type) which contains a `"type" * vec` and
an `unsigned int len`.

It also has the following functions:
- `"type"_vec* "type"VecInit(unsigned int count)` which creates and allocates the
struct (this can be done by hand pretty easily if you want to).
- `void "type"VecRemove("type"_vec* vec, unsigned int index)` which removes the
item at the designated index
- `void "type"VecPrepend("type"_vec* vec, "type" val, unsigned int index)` which
inserts the value designated before the specified index
- `void "type"VecAppend("type"_vec* vec, "type" val, unsigned int index)` which
inserts the value designated *after* the specified index
- `void "type"VecFinish("type"_vec* vec)` which frees all memory associated with
the struct (this can also easily be done by hand).

Note that the vector cannot work for pointers or structs unless they have been
typedef'd.
