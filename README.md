# DuplicateFile

In order to start the assembly of the program, we use the command while in root: $ <cmake -S . -B build> 


next: 
$ cd build
  
to run: 
$ make

To run the tests, use the command: 
$ ./tests_app

To run the program, use the command with command line arguments:
$ ./app <name_patch_directory> <name_dir> <name_dir_two>

The first argument is the path to the directories in which duplicate files will be searched.

The second argument is the name of the first directory.
The third argument is the name of the second directory.
There is also a test of the program using google Test and mook test
