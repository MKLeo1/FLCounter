<h1>FLCounter</h1>

<h2>Author's Note:</h2>

FilesLinesCounter is a form of exercise to gain practical coding skills and knowledge in the field of C ++.

M.K.

<h2>Overview</h2>

FLCounter is a program written in C++ that helps count the number of files, empty and non-empty lines in provided paths on your hard drive and their subfolders.
The library program uses Boost.Filesystem to search files on disk and calculate lines in each file.

<h2>Additional library added</h2>

<boost/filesystem.hpp>: provides operations on files and directories, such as path resolution, iteration, and manipulation.
  
<h2>Namespace</h2>
The code defines the fs namespace, which is an alias for the boost::filesystem namespace. The boost::filesystem library provides facilities for working with files and directories.
  
<h2>Structs</h2>
DataInput holds the entered paths, which are provided as command-line arguments. The constructor of DataInput takes a vector of fs::path objects as input.

DataOutput holds the results of the program execution. It has three members:

1. files_number: the total number of files found in the specified paths
2. num_non_empty: the total number of non-empty lines found in the specified paths
3. num_empty: the total number of empty lines found in the specified paths
  
<h2>Functions</h2>
  
The code defines three functions: 

countFiles

countLines

operator<<

countFiles function returns the number of files found in the specified directory and its subdirectories. If the specified path is not a valid directory, the function throws an invalid_argument exception.

countLines function returns a tuple containing the number of empty and non-empty lines found in the specified directory and its subdirectories. If the specified path is not a valid directory, the function throws an invalid_argument exception. If the file cannot be opened, the function throws a runtime_error exception.

operator<< function returns the output stream.

<h2>Manual compilation:</h2>
  
Some Boost libraries like filesystem need to be linked separately. Manual compilation example:
g++ -g -Wall -o FLCounter FLcounter.cpp -L/insert/here/lib/path -lboost_filesystem
  
  
  
