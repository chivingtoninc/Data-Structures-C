# Doubly-Linked List
Doubly-Linked List data structure, written in C. This linked list is implemented as an interactive grocery list, to show how we can use these data structures. As such, there is a little more to it than you might see in other implementations.

My goal is to give you a use for these data structures, rather than some abstract concept that does nothing useful. See the [illustration section](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#illustration) below for the minimal requirements of a linked list and then view the code to see how it can be useful in things like grocery lists, to-do lists, etc.

![Build Status](https://img.shields.io/badge/build-Stable-green.svg)
![License](https://img.shields.io/badge/license-DO_WHATEVER_YOU_WANT-green.svg)
<br/><br/><br/>

## Contents
* [Prerequisites](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#prerequisites)
* [Installation](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#installation)
* [Testing](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#testing)
* [Illustration](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#illustration)
* [Usage](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#usage)
* [Authors](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#authors)
* [Contributing](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#contributing)
* [Acknowledgments](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#acknowledgments)
* [License](https://github.com/chivingtoninc/Data-Structures-C/tree/master/linked-lists/doubly#license)
<br/>

## Prerequisites
  * Some C compiler.


## Installation
```
  cd /path/to/where/you/want/it
  git clone https://github.com/chivingtoninc/Data-Structures-C.git
```

## Illustration
A doubly-linked list only has a few key attributes that you need to remember. See **Figure 1-1**
  1. It is made of individual nodes.
  2. Each node stores some data, and a pointer to the next and previous nodes in the list.
  3. You can insert, delete and view nodes from the list at a given index in linear time. That is, the longer the list, the longer it takes to insert/delete/view a node near the end.

  **Figure 1-1**
![Figure 1-1](doubly.png?raw=true)

## Testing
Navigate to an example in the Data-Structures-C directory and compile/run.

Assuming your C compiler is GCC and you're on Linux:
```
  cd /path/to/Data-Structures-C/doubly
  gcc doubly.c -o doubly
  ./doubly
```

Assuming your C compiler is GCC and you're on Windows:
```
  cd /path/to/Data-Structures-C/doubly
  gcc doubly.c -o doubly
  doubly
```

## Usage
Only real use is for learning about Linked Lists. You can copy into a bigger project, but this should not be considered production-ready in any way. Simply follow the steps in **Testing** to use.

Note that this implementation is a slight deviation from most implementations you might see in that there is no specific "append" or "prepend" method. Instead of having multiple methods for insertion, there is only one. You are shown the list as it currently is before insertion and can choose where to insert. This is cleaner to me than having mostly-redundant insertion methods. Likewise, there are no redundant deletion methods.

The characteristics of a linked list do not specify explicit methods for insertion/deletion, only how insertion/deletion is accomplished. A doubly-linked list must use it's "next" pointer to traverse the list for insertion/deletion, which this implementation does.

Also note that the "save" method is not a standard method of a linked list. It is only here as an added feature.
<br/><br/><br/>


## Authors
* **Johnathan Chivington:** [GitHub](https://github.com/chivingtoninc) | [Twitter](https://twitter.com/chivingtoninc) | [Facebook](https://facebook.com/chivingtoninc) | [LinkedIn](https://www.linkedin.com/in/johnathan-chivington/)

## Contributing
Not currently accepting outside contributors, but feel free to clone, fork, modify and use as you wish.

## Acknowledgments
Thanks to [Gayle Laakmann McDowell](https://youtu.be/shs0KM3wKv8) for her brilliant explanations of these data structures.

## License
This project is licensed under the DO_WHATEVER_YOU_WANT License - see the [LICENSE](https://github.com/chivingtoninc/Data-Structures-C/blob/master/LICENSE) file for details
<br/><br/>
