# C++

## First Steps in C++ for C Programmers

C++ is a subset of C programming language and was first designed as an extension of C. C++ supports object-oriented programming and thus features like classes, inheritance etc.

On the difference between C and C++ read: https://www.softwaretestinghelp.com/c-vs-cpp/

#### File Extension

In C++ files are not saved with .c but with .cpp.

#### Program Division

Whereas in C the program is divided into functions and modules, in C++ it is divided into classes and objects. 


#### Variables

Whereas in C variables need to be declared at the beginning of a function, they may be declared anywhere in C++ (but before used).

C++ does not allow multiple declarations of global variables. 

Additionally to pointers, C++ supports references (what is that?).

#### Structures

In C++ we can use functions as struct members. 

#### Data Types

In C++ you can use user-defined data types and boolean and string data types that are not supported in C.

#### Memory Managment

C: allocate memory with malloc (), calloc () etc,  and deallocate with free ()

c++: allocate memory with new () and deallocate memory with delete

#### Default Headers

In C:	<stdlib.h>

In C++:	<iostream>

#### Some new features to look up

- inline functions
- default arguments
- reference variables
- namespaces
- exception/error handling using the try-catch blocks
- templates


- classes
- inheritance
- access specifiers
- encapsulation: "C++ uses classes which bundle data and the functions operating on this data in a single unit. This is encapsulation."
- polymorphism


- differences in enumerations and strings


## Namespaces

Namespaces are used to group variable declarations and functions together which semantically belong together. 

In C you would group these functions together in a file or several files. In C++ you can use namespaces. One advantage is that you can use the same name for variables that are declared in different namespaces because the namespace's name is separating them. 

		namespace	Name
		{
			int	var = 1;
			int	function(void) {return 0;}
		}

		namespace	Another
		{
			int var = 0;
		}

You can also create a namespace by taking an existing namespace (for example if the name of the namespace you want to use is too long):

		namespace New = Another;

Namespaces "New" and "Another" are perfectly equivalent.

### Scope Resoultion Operator (::)

When referencing a variable or function of a namespace, you use the scope resolution operator (::). It is just as in structures in C, where you have to use dot (.) or arrow (->) to refer to a member of the struct. 

		Name::var
		Another:: var

Variables that have been declared outside a namespace can be referenced as in C:

		int	x;

		x = 0;

Or with an empty namespace:

		int x;

		::x = 0;

### Standard C++ Library

You can write namespaces yourself or use others. A namespace that oen often uses is the namespace **std**. It contains the whole standard C++ library. 

## Stdio Streams: Reading from Stdin & Writing to Stdout

In C there are scanf() & printf() or read() and write(). 

In C++ you use the standard library (std) and its functions cin() & cout().

		#include <iostream>

		int	main()
		{
			std::cout << "Hello World!" << std::endl;
			return (0);
		}

The string "Hello World!" is redirected (<<) to stdout (cout). As well as the newline character, which is is in Linux "\n" and in Windows "\r\n". The endl object takes care of this difference in the operating systems and redirects a newline to stdout.  

If you want to read user input use cin:

		#include <iostream>

		int	main()
		{
			char	buf[100];

			std::cout << "Input your name: " << std::endl;
			std::cin >> buf;
			std::cout << "Nice to meet you, " << buf << std::endl;
			return (0);
		}

First, we redirect (<<) the string "Input your name: " to stdout (cout) and redirect a newline (endl) to stdout. Then we wait for user input and redirect (>>) the input into the buffer (buf) with cin. After that we redirect (<<) a greeting message ("Nice to meet you, ") to stdout and the string saved in the buf as well as a newline. Note that for every object we redirect to stdin or stdout, we use the redirection operator (<< for cout and >> for cin).

More on: https://cplusplus.com/reference/iostream/


## File Naming Conventions


#### Header Files

The .c extension which is used in C for header files can also be used in C++. However, the editor of you choice may then handle the contents of the file as C code, which may be irritating for you. 

The C++ extension for header files is **.hpp**. If you declare a class in a header file, a convention is to add "class." to the extension. The name of the header file, should be the name of the class you declared in it. As class names should be written in UpperCamelCase the header file for a class named "ClassName" would look as follows:

		ClassName.class.hpp

This is the convention I will use, but at 42 we are also allowed to use:

		ClassName.hpp
		ClassName.h
		ClassName.class.h

... as long as it is consistent.

For the ifndef, however, we will still use the .h extension:

		#ifndef CLASSNAME_CLASS_H
		# define CLASSNAME_CLASS_H
		[...]
		#endif


#### Source Files

The same applies for the source files, which may end with the C extension .c or the C++ extension **.cpp**. 

		ClassName.cpp
		ClassName.c
		ClassName.class.cpp
		ClassName.class.c

## Classes

Classes are declared in a header file (specific for that class) and defined in a source file (also specific for that class).

In the header file, you declare the class you want to create by using the "class" keyword. The syntax is quite similar to the syntax when declaring a structure in C. But do not forget the semicolon at the end of the brackets. 

		//This is my header file for the class "Sample": Sample.class.hpp

		#ifndef SAMPLE_CLASS_H
		# define SAMPLE_CLASS_H

		class SAMPLE 
		{
		public:

			Sample( void );
			~Sample( void );

		};

		#endif

If you do not add a keyword in the beginning of the definition, the class will by default be "private". In the public area you should declare a constructor and a destructor. The constructor is the name of the class and the destructor tilde_nameofclass.

The constructor is a function which is used to instantiated a class. This way all the variables in the class can be private but still the class can be instantiated through the constructor because it is public. Note that constructors and destructors do not have a return type. 


		//This is the source file for the class "Sample"

		#include <iostream>
		#include "Sample.class.hpp"

		//This is the function for the constructor which in this case does not take any parameters.

		Sample::Sample( void )
		{
			std::cout<< "Constructor called" << std:endl;
			return ;
		}

		Sample::~Sample( void )
		{
			std::cout<< "Destructor called" << std:endl;
			return ;
		}

If you do not declare a constructor and destructor, the compiler will use a default constructor and destructor. In this case, however, all the variables need to be accessible (public).

Now, that we have defined our sample class we can use it as a variable in our main.

		//This is my main file: main.cpp

		#include "Sample.class.hpp"

		int	main(void)
		{
			Sample	test;

			return (0);
		}

If we run this code, the constructor will be called when defining an instance of the sample class which is in this case "test". When returning, the destructor will be called. As in C++ (as in C) all local variables will be destroyed when returning from a function. 

### Member Attributes and Functions and Keyword "this"

In C++ you cannot only declare variables in a class (as in C in structures) but also functions. 
A variable declared in a class is called a **member attribute**. 
A function declared in a class is called a **member function**. 
Let's take our sample code from before but add a member attribute and a member function.

		//This is my header file for the class "Sample": Sample.class.hpp

		#ifndef SAMPLE_CLASS_H
		# define SAMPLE_CLASS_H

		class SAMPLE 
		{
		public:

			int	x;

			Sample( void );
			~Sample( void );

			(void) some_function(void);

		};

		#endif

In the source file, we now have to define variable x and function some_function. We can do this in the constructor by using the keyword **this** which refers to the structure we are currently in. 

		//This is the source file for the class "Sample"

		#include <iostream>
		#include "Sample.class.hpp"

		//This is the function for the constructor.

		Sample::Sample( void)
		{
			std::cout<< "Constructor called" << std:endl;
			this->x = 42;
			std::cout << "x has the value: " << this->x << std::endl;
			return ;
		}

		Sample::~Sample( void )
		{
			std::cout<< "Destructor called" << std:endl;
			return ;
		}

		void	Sample::some_function(void)
		{
			std::cout << "You called a function" << std::endl;
			return;
		}

### Initialization List

If we have several member attributes and thus parameters for our constructor we can use a more concise way than using the keyword "this" and initializing every member attribute in a separate line. The more concise way is called initiliazation list. Let's say, we have three member attributes int a, b and c. 

		//This is my header file for the class "Sample": Sample.class.hpp

		#ifndef SAMPLE_CLASS_H
		# define SAMPLE_CLASS_H

		class SAMPLE 
		{
		public:

			int	a;
			int	b;
			int	c;

			Sample(int p1, int p2, int p3);
			~Sample( void );

			(void) some_function(void);

		};

		#endif

In the constructor in our source file, we can initialize the member attributes the following way:

		//This is the function for the constructor which in this case does not take any parameters.

		Sample::Sample(int p1, int p2, int p3) : a(p1), b(p2), c(p3)
		{
			std::cout<< "Constructor called" << std:endl;
			std::cout << "a has the value: " << this->a << std::endl;
			std::cout << "b has the value: " << this->b << std::endl;
			std::cout << "c has the value: " << this->c << std::endl;
			return ;
		}

		Sample::~Sample( void )
		{
			std::cout<< "Destructor called" << std:endl;
			return ;
		}

		void	Sample::some_function(void)
		{
			std::cout << "You called a function" << std::endl;
			return;
		}

### Const

Try to use **const** qualifier every time you can. This means, every time the variables or functions should not be changed in future code. 
For variables, you just use "const" as in C:

		type const	name;
	e.g. int const	i;

For functtions, you write "const" after the function declaration and before ";" or "{":

		void	some_function(int i) const;

		void some_function(int i) const
		{
			return (4);
		}

Using const, when possible prevents you from altering complex code in the aftermath in a bad way. It can save you hours of debugging. 
https://elearning.intra.42.fr/notions/piscine-c-d00-c-basics/subnotions/piscine-c-d00-c-basics-const/videos/const-c0f10448-8fd3-4a06-83ed-abcce68c18a1

### Visibility: public, private and protected

By default classes are private. This means that the member attributes and functions are only accessible and visible inside the class. A convention is put an underscore before the name of a private member attribute or function.

		class	Sample
		{
			public:
				int	x;

				Sample(void);
				~Sample(void);

			private:
				int	_x;
		}

To be more precise, the constructor and destructor (as parts of the class) can access (this means for example change) the public and private members. In a constructor you can assign a value to int _x. But you cannot access Sample::_x from the main function. Only Sample::x which is public. 

It makes sense to put the constructor and destructor into a public section, so that you can build a new instance from outside the class. In some advanced cases it makes sense to put them private but for the beginning it is more logical to have them public. 

Structures in C++ have the same syntax as classes. The big difference is that by default structures are public, whereas classes are private by default. 

### Accessors & Proxy Functions

If we set variables in a class as private, we may still want users to access the value of the variable or even give them the possibility to change the variable in a certain range. This we can do by writing proxy functions.

		int	Sample::getX( void ) const
		{
			return (this->_x);
		}

		void	Sample::setX(int i)
		{
			if (i >= 0)
				this->_x = i;
			return ;
		}	

As a convention proxy functions that return the value of a variable are called "get" + the name of the variable. As they only return the value of the variable, you should set them as constant. 
Proxy functions that allow you to access the variable and change it, are named "set" + the name of the variable. 

Note: The proxy functions need to be public to be accessed by users. The variable is private. 

### Non-member functions and non-member attributes

There exist also functions and attributes in classes that are not passed to the instances created from this class. They are called non-member functions and attributes or class functions and attributes in contrast to member or instance functions and attributes that we have seen before. 

Non-member functions and attributes can, for example, be used to count the number of instances made from the class. 

They are preceded by the attribute **static**.

Note that no pointers to the class are passed to these non-member functions so that the keyword "this" does not work in them. 

As you want to initialize non-member attributes before you create the first instance, you do not initalize non-member attributes in a constructor. Very simple, you just initialize the variable in the class.cpp file as you would normally do but with the type specified (without the attribute "static"):

		int	Sample::_x = 0;

Do not forget to specify the class (here: Sample::)! Otherwise you get error messages while linking.

### Pointers to Members 

watch intranet video again and fill out

## Manipulators for cout and cin

### setprecision, fixed, showpoint

Setprecision is used to adjust the number of digits that are printed of a number. As default, 6 digits are printed.

	double number = 107.567;

	std::cout << std::setprecision(3) << number << std::endl;

	output: 107

If you want to print a specific number of decimal digits, you can add std::fixed which limits the number of decimals to the number given in std::setprecision.

	cout << std::fixed << std::setprecision(2) << number << std::endl;

	output: 107.56.

If, however, you always want to show a decimal point, you use std::showpoint. It fills out the field length with zeros. But then you can adjust the field lenght again with std::setprecision. 

	double x = 5;

	cout << std::showpoint << std::setprecision(2) << x << std::endl;

	output: 5.0

However, this will show the first 2 digits and not 2 decimals. In that case it is better to use std::fixed and std::setprecision.

Setprecisionhas to only be used once to set a certain limit length. The same goes for std::fixed and showpoint. So, you can just set it at the beginning once:

	std::cout << setprecision(2) << fixed;

To set it back to the default, just type:

	std::cout << std::setprecision(6);
	std::cout.unset(ios::fixed);

### setw

The default width of a field is 8 characters. If you have more, C++ expands the field width automatically. 

By default, they are printed right justified.

	std::cout << std::left << std::setw(10) << str << std::endl;

Other than setprecision, fixed, showpoint and left and right, which are only set once, setw has to be set for every field. 

# CPP01

## Memory Management

When allocating and deallocating classes in C++, malloc() and free() won't work properly, because they do not call the constructor/ destructor. Therefore, you use new() and delete(). For example:

		MyClass	*instance = new MyClass();
		...
		delete instance;

If you want to allocate an array of instances, you can do it as follows:

		MyClass *instances = new MyClass[10];
		...
		delete [] instances;

If you allocate an array, you pass the number of instances to be created in square brackets. Unfortunately, you cannot pass parameters to the constructor and have to find workarounds. Do not forget the square brackets after the delete when deallocating the array.

## References

# CPP02

## The Orthodox Canonical Class Form

From module CPP02 on The Orthodox Canonical Class Form is required. It prescribes that every class has a default constructor, a copy constructor, an assignement constructor and a destructor.

1. **Default Constructor**: initializes object - for internal use when no other value is available
2. **Copy Constructor**: used in the implementation of call-by-value parameters
3. **Assignment Operator**: used to assign one value to another
4. **Destructor**: deletes object

