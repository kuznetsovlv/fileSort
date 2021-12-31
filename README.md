# File Sort
Home Work of C++ course from Skill Factory, module 11.

#Description
Creating and sorting text file of ints.

Main class is `FileArray` - reading and writing array in the file.

Because of `fs.eof()` is not relible to undestending end of file while reading ints, after open for reading first I read file char by char for calculating array's size.

Quick sort algorithm usually is the fastest, but it is required too many extra tmp files, and radix sort with base two allows to sort ints with `O(sN)` where `s = sizeof(int)`, and because of it is const, the algorithm complexity reduces to `O(N)`, so I used radix.