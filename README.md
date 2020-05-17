
`libcdata` - basic data structures in C (`libstdc++` wrapper)
-----------------------------------------------------------

`libcdata` is a small library that offers basic data structures (`list`, `set`, `map`...) in a pure C API. It uses
`libstdc++` as a backend engine. Key features:

* Easy to use and portable
* No MACROs
* No need to modify your data structures (except, perhaps for `__attribute__((packed))`)
* Reasonable performance


Example
-------
```c
int x, val=0;
cdata_list_t* my_list = cdata_list_create(sizeof(int));

//Add to list {10, 11, 5, 5}
x=10;
cdata_list_push_back(my_list, &x);
x=11;
cdata_list_push_back(my_list, &x);
x=5;
cdata_list_push_back(my_list, &x);
cdata_list_push_back(my_list, &x);

//Get element in position 1
cdata_list_get(my_list, 1, &val);
assert(val == 11);

//Remove duplicates {10,11,5}
cdata_list_unique(my_list);
assert(cdata_list_size(my_list) == 3);

//Add {10, 11, 5, 11}
x=11;
cdata_list_push_back(my_list, &val);

//Remove all 11s
cdata_list_remove(my_list, &val);
assert(cdata_list_size(my_list) == 2);

//Traverse list
cdata_list_traverse(my_list, my_iterator_func, opaque);
```

More examples for `map` and `set` here.

Documentation
-------

`libcdata` supports structures as keys (values for lists) of 1-256 bytes, but
will perform better if they are aligned to {1,2,4,8,32,64,128,256} bytes.

Support for larger objects will come soon.

Detailed documentation and examples:

* `list`
* `map`
* `set`


NOTE: `libcdata` is designed to be as easy to use as possible, and might NOT
be optimal in performance, just good (or as good as `libstc++`). If you have
_hard_ performance requirements, or you cannot afford the extra padding the
library adds to the keys to align them to a power of 2 bytes, you should
consider other libraries or writing your own custom data structures.

`libcdata` (as `libstdc++`) is not thread-safe.

Installation
------------

Requirements:

* POSIX system
* C and C++ gcc compatible compilers (gcc, icc, clang...)
* Automake
* Autoconf
* Libtool
* libstdc++ (C++98)
