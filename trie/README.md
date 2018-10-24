# Trie
Trie data structure, written in C. This trie is implemented as an interactive phone book with built-in auto-complete functionality. Tries are very interesting data structures. They typically require a large amount of memory but look-ups, insertions and deletions are very fast. See the [complexity section](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#complexity) for details.

My goal is to give you a use for these data structures, rather than some abstract concept that does nothing useful. See the [illustration section](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#illustration) below for the minimal requirements of a trie and then view the code to see how it can be useful in things like dictionaries, auto-complete, etc.

![Build Status](https://img.shields.io/badge/build-Unstable-red.svg)
![License](https://img.shields.io/badge/license-DO_WHATEVER_YOU_WANT-green.svg)
<br/><br/><br/>

## Contents
* [Prerequisites](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#prerequisites)
* [Installation](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#installation)
* [Testing](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#testing)
* [Illustration](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#illustration)
* [Usage](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#usage)
* [Authors](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#authors)
* [Contributing](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#contributing)
* [Acknowledgments](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#acknowledgments)
* [License](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#license)
<br/>

## Prerequisites
  * Some C compiler.


## Installation
```
  cd /path/to/where/you/want/it
  git clone https://github.com/chivingtoninc/Data-Structures-C.git
```

## Illustration
A trie only has a few key attributes that you need to remember. See **Figure 1-1**
  1. It is made of individual nodes.
  2. Each node stores
    * an array of (or mapping to) all of it's children
    * a boolean to indicate if it represents the end of a word, and
    * optionally, some additional data (ex: a phone number)
  3. Storage requirements typically are higher, but operations on the structure are very fast. See the [complexity section](https://github.com/chivingtoninc/Data-Structures-C/tree/master/trie#complexity) below.

  **Figure 1-1**
![Figure 1-1](singly.png?raw=true)
<br/>

## Complexity
The complexity of a Trie can be describe as follows, where "M" is the maximum string length and "N" is the number of keys stored in the tree.
  * lookup = O(M)
  * insert = O(M log(N))

![Figure 1-1](singly.png?raw=true)

## Testing
Navigate to an example in the Data-Structures-C directory and compile/run.

Assuming your C compiler is GCC and you're on Linux:
```
  cd /path/to/Data-Structures-C/singly
  gcc singly.c -o singly
  ./singly
```

Assuming your C compiler is GCC and you're on Windows:
```
  cd /path/to/Data-Structures-C/singly
  gcc singly.c -o singly
  singly
```

## Usage
Only real use is for learning about Tries but it is implemented as a phonebook. Instead of simply storing words, you will be able to store names (key) and a 10-digit number (value) associated with that name. Run with option "--help" or type "help" once running for options.
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
