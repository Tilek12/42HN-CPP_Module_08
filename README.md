# :desktop_computer: 42Heilbronn :de:

<p align="center">
  <img src="https://github.com/Tilek12/42-project-badges/blob/main/badges/cppm.png">
</p>

<h1 align="center">
 Project - CPP Module 08 :card_index_dividers:
</h1>

<h2 align="center">
 :white_check_mark: 100/100
</h2>

## :clipboard: Project info: [subject](https://github.com/Tilek12/42HN-CPP_Module_08/blob/master/.git_docs/subject_cpp_08.pdf)

## :green_circle: **Exercise 00: Easy find**

**Turn-in directory :**   | ex00/
|:---|:---|
**Files to turn in :**    | Makefile, main.cpp, easyfind.{h, hpp} and optional file: easyfind.tpp
**Forbidden functions :** | None

A first easy exercise is the way to start off on the right foot.

Write a function template **easyfind** that accepts a type **T**. It takes two parameters.
The first one has type **T** and the second one is an integer.

Assuming **T** is a container **of integers**, this function has to find the first occurrence of the second parameter in the first parameter.

If no occurrence is found, you can either throw an exception or return an error value of your choice. If you need some inspiration, analyze how standard containers behave.

Of course, implement and turn in your own tests to ensure everything works as expected.

--------------------------------------------

## :green_circle: **Exercise 01: Span**

**Turn-in directory :**   | ex01/
|:---|:---|
**Files to turn in :**    | Makefile, main.cpp, Span.{h, hpp}, Span.cpp
**Forbidden functions :** | None

Develop a **Span** class that can store a maximum of **N** integers. **N** is an unsigned int variable and will be the only parameter passed to the constructor.

This class will have a member function called **addNumber()** to add a single number to the Span. It will be used in order to fill it. Any attempt to add a new element if there are already N elements stored should throw an exception.

Next, implement two member functions: **shortestSpan()** and **longestSpan()**

They will respectively find out the shortest span or the longest span (or distance, if you prefer) between all the numbers stored, and return it. If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.

Of course, you will write your own tests and they will be way more thorough than the ones below. Test your Span at least with a minimum of 10 000 numbers. More would be even better.

Running this code:

 ```
int main() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    return 0;
}
```

Should output:

```
$> ./ex01
2
14
$>
```

Last but not least, it would be wonderful to fill your Span using a **range of iterators**. Making thousands calls to **addNumber()** is so annoying. Implement a member function to add many numbers to your Span in one call.

--------------------------------------------

## :green_circle: **Exercise 02: Mutated abomination**

**Turn-in directory :**   | ex02/
|:---|:---|
**Files to turn in :**    | Makefile, main.cpp, MutantStack.{h, hpp} and optional file: MutantStack.tpp
**Forbidden functions :** | None

Now, time to move on more serious things. Let’s develop something weird.

The **std::stack** container is very nice. Unfortunately, it is one of the only STL Con- tainers that is NOT iterable. That’s too bad.

But why would we accept this? Especially if we can take the liberty of butchering the original stack to create missing features.

To repair this injustice, you have to make the **std::stack** container iterable.

Write a **MutantStack** class. It will **be implemented in terms of a std::stack**.
It will offer all its member functions, plus an additional feature: **iterators**.

Of course, you will write and turn in your own tests to ensure everything works as expected.

Find a test example below.

```
int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl; mstack.pop();

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;

    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }

    std::stack<int> s(mstack);

    return 0;
}
```

If you run it a first time with your MutantStack, and a second time replacing the MutantStack with, for example, a **std::list**, the two outputs should be the same. Of course, when testing another container, update the code below with the corresponding member functions (**push()** can become **push_back()**).

