# StringBuilder

A simple string building library for C.

# Install

Ideally clone this into your project:

```bash
git clone https://github.com/bbonsai21/StringBuilder path/to/your/project
```

Supposing the folder where you included the file is the same as where your **.c** file lives, simply include the header:

```C
#include "stringbuilder.h"
```

# Compile

Remember to include the .c file upon compilation:

```bash
cd StringBuilder/
gcc -O3 -o main stringbuilder.c
```

# Functioning

You can create any amount of StribgBuilder objects via `sb_new` or `sb_new_with_capacity_of`.
Append strings, integers and floats with, respectively, `sb_appends`, `sb_appendi`, `sb_appendf`.
Get the length of the yet-unbuilt string via `sb_length`.
Build the string and return it via `sb_build`.
Free all internal allocations of your StringBuilder instance via `sb_free`.

Memory pool allocation doubles every time capacity is insufficient.

Remember YOU have to free the StrigBuilder instance you created.

Also, notice functions tend to return nullptr if they fail. Beware of free-related errors: handle every function appropriately.

# Benchmarking

UPCOMING.

