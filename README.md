# StringBuilder

A simple, lightweight, efficient string building library for C.

# Installation

You can clone this to your project:

```bash
git clone https://github.com/bbonsai21/StringBuilder path/to/your/project
```

Include the header in your file:

```C
#include "stringbuilder.h"
```

# Compile

Compile by including stringbuilder.c:

```bash
cd StringBuilder/
gcc -o main stringbuilder.c your-main.c -march=native -O3 -Wall -Wextra
```

Notice the repo comes with a `test-main.c` file, containing both an example of the library functioning and a benchmark.
You can compile it with the same command as above, just by replacing "`your-main.c`" with `test-main.c`.

# Functioning

Usage example:

```C
StringBuilder* sb = sb_new_capacity_of(64);

sb_appends(sb, "Hello, World! ");
sb_appendf(sb, 3.14159);
sb_appendi(sb, 42);

char* result = sb_build(sb);
printf("%s\n", result);

sb_free(sb);
// remember you must MANUALLY free sb and the result of the build!
free(result)
free(sb);
```

Also, notice many functions return nullptr if they fail. Beware of free-related errors: handle every function appropriately.

# Benchmarking

Uncomment, or add on top of the file, the line `#define BENCHMARKING`.
For this purpose, compilation was done with flag `-march=native`.
Follows:

```bash
sudo cpupower -frequency-set -g performance
hyperfine --warmup 5 --min-runs 20 "./main"
```

On my system (see section below for more details), the benchmarking loops in the file (easily identifiable by reading the code in `test-main.c`) have scored the following:

No further optimisation flag:

```
Time (mean ± σ):     686.5 ms ±   5.5 ms    [User: 671.8 ms, System: 14.4 ms]
Range (min … max):   681.6 ms … 708.1 ms    20 runs
```

-O3:

```
Time (mean ± σ):     663.3 ms ±  45.4 ms    [User: 648.6 ms, System: 14.6 ms]
Range (min … max):   644.6 ms … 815.0 ms    20 runs
```

# Relevant benchmark hardware/software conditions

The benchmarks above were ran on the following hardware, at the following conditions (full system infos obtained via `inxi -Fxxxz`):

```
System:
  Kernel: 6.17.0-22-generic
  arch: x86_64
  bits: 64
  Distro: Linux Mint 22.2 Zara
  base: Ubuntu 24.04 noble

Machine:
  Type: Laptop
  System: LENOVO
  product: 81F4
  v: Lenovo ideapad 330S-14IKB
  
CPU:
	dual core
	model: Intel Core i3-8130U
	bits: 64
	type: MT MCP
    smt: enabled
    arch: Coffee Lake
    rev: A
    cache:
    	L1: 128 KiB
    	L2: 512 KiB
    	L3: 4 MiB
    
Memory:
	total: 8 GiB
	available: 7.67 GiB
	used: 2.94 GiB (38.4%)
```

At the moment of the benchmark, these were swap memory conditions:

```
Swap:
  type: file
  size: 2 GiB
  used: 0 KiB
```
