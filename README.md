# oddfibonacci
Calculates the value f(123456789012345678), where f is defined recursively as follows:
f(0) = 1,
f(1) = 1,
f(2n) = f(n),
f(2n+1) = f(n) + f(n-1)

Use make command to build, options: prep (creates output directories), debug, release, clean: default is release

Output file is generated in debug/ or release/ directory based on build type

The calculation takes ~11.5 seconds with gcc 4.8, -O3 optimization, 64bit ubuntu 14.04, core i5 CPU

If checks for 0 and 1 are combined in a single if statement, it runs some ~0.3 seconds faster (I didn't do it because the problem states to apply the given formula directly)

Also runs under windows, tested with Visual Studio 2015 (project and solution files are included)
