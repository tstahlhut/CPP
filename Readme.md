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

#### Pointer to Member Attributes

In your main, you can declare a pointer to a member attribute which you can then use to point to the same member attribute but in different instances.
If we have the following class with the member attribute *int x*:

	class	MyClass {

		public:
			
			int	x;
			MyClass( void );
			~MyClass( void );

			void	function( void ) const;
	}

We can create a pointer *p* that points to *int x*:

	int	main( void )
	{
		MyClass	instance1;
		MyClass	instance2;

		int	MyClass::*p = NULL;

		p = &MyClass::x;

		[...]

		return (0);
	}

This pointer can be used for any instance of the MyClass class:

	int	main( void )
	{
		[...]

		instance1.*p = 21;
		instance2.*p = 42;

		return (0);
	}

If you have a pointer to an instance, the syntax changes slightly:

	int	main( void )
	{
		MyClass		instance;
		MyClass*	instancep = &instance;

		[...]

		instancep->*p = 84;

		return (0);
	}

#### Pointer to Member Functions

As in the example above, we have the class MyClass:

	class	MyClass {

		public:
			
			int	x;
			MyClass( void );
			~MyClass( void );

			void	myFunction( void ) const;
	}

This time we create in our main a pointer to the function myFunction(). When creating the pointer to the member function, we have to specify the type of the function: *void ... ( void ) const*. Then we have to assign to that pointer *f* the function it should point to: *myFunction*. Now, we have a pointer to a member function and can use it on any instance of the class MyClass:

	int	main( void )
	{
		MyClass		instance;
		MyClass*	instancep = &instance;

		void	(MyClass::*f)( void ) const;

		f = &MyClass::myFunction;

		(instance.*f());
		(instance->*f());

		return (0);
	}
	


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

## Opening Files (fstream)

You could open and close files in C++ just as in C with fopen() and fclose(), however, in these exercises we are not allowed to. Another way of doing this, is ifstream() and ofstream().

Include the fstream header and the iostream header (to print error message) and use ifstream() to open the file. You have to check if it was successfully opened before performing any manipulations on it. 

	#include <fstream>

	std::ifstream inputFile("name.txt");
	if (!inputFile.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return (1);
	}
	//do something
	inputFile.close();

## Switch Statement

The switch statement is a multiway conditional from C.
Switch only compares integers. You can find an example in cpp01/ex06/main.cpp.

## Ad hoc Polymorphism

Ad hoc polymorphism is also referred to as function overloading. It means that you can define many functions in C++ with the same name but different parameters. For example:

	void	function( char const c ) const;
	void	function( int const n ) const;
	void	function( float const z ) const;
	void	function( MyClass const & i ) const;

Thus, I can pass either a char, an int, a float or a MyClass to the function *function*. This is pretty handy.

### Operator Overload

#### Arithmetic Notations

1. **Infix notation** = the operator (+, -, etc) is set between the operands, e.g. 1 + 1.

2. **prefix** or **function notation** = the operator is set before the operands, e.g. + 1 1. It is also called function notation because it looks a lot like a function: +(1, 1) or sum(1, 1). Or: 1.+( 1 )

3. **postfix notation** = the operator is behind the two operands, e.g. when calculating with stacks.

#### Syntax of Operator Overloads

As an example, we create an Integer class:

	class Integer {

		public:
		Integer( int const n );
		[...]
		Integer &	operator=( Integer const &rhs );
		Integer		operator+( Integer const & rhs ) const;
	}

As these two functions are member functions, a pointer to the current instance will always be passed to the function. This pointer will be the first operand. The instance passed as a parameter will be the second operand. In both examples, the second operand (rhs) will not be changed and is put therefore as "const".

In the first example, we use an assignment operator: the current instance is set equal to the instance rhs passed as a parameter. The current instance is changed and equals the instance rhs. Therefore, it returns a reference to the instance. It cannot return void because then operations like this one (a = b = c = d) would not be possible.

In the second example, neither of the two instances is changed (1 + 1 = 2) but a new instance created and a copy of the result is returned. Therefore, the function is also set as const. 

Of couse, you can also have pre- or postincrementations. There you do not need a parameter because it is a unary operation (e.g. i++;).

	Integer &	Integer::operator=( Integer const & rhs ) {

		this->_n = rhs.getValue();
		return *this;
	}

	Integer		Integer::operator+( Integer const &rhs ) const {

		return Integer( this->_n + rhs.getValue() );
	}

#### Syntax of Operator Overloads with ostream

As the first operand has to be an std::ostream, we cannot use the << operator on member functions but only on "normal" functions:

	std::ostream &	operator<<( std::ostream & o, Integer const & rhs);

	std::ostream &	operator<<( std::ostream & o, Integer const &rhs) {

		o << rhs.getValue();
		return o;
	}

When we have implemented the << operator for our Integer class, we can easily output the value of any integer of that class:

	int	main( void ) {

		Integer	x( 21 );
		Integer	y( 42 );
		Integer	z( 0 );

		std::cout << "Value of x: " << x << std::endl;
		return 0;
	}

**<< x** calls the ostream function implemented before and thus we can output the private int _n.

## Orthodox Canonical Form

The Orthodox Canonical Form refers to the standard norm of declaring a class in C++. From CPP02 onwards, 42 students are obliged to use the canonical form. This standard prescribes that a class should have at least:

	- A default constructor
	- A copy constructor
	- A copy assignment operator
	- A destructor

As I already wrote about what a constructor and a destructor is, I will only explain what a copy constructor an dwhat a copy assignment operator is. 

In the **copy constructor** a new instance is created:

	MyClass( MyClass const & src );

In the **copy assignment operator** the current instance is changed by assigning another instance (as a parameter) to it:

	MyClass &	operator=( MyClass const & rhs);

## Fixed-Point Numbers

"In computing, fixed-point is a method of representing fractional (non-integer) numbers by storing a fixed number of digits of their fractional part." ([Wikipedia](https://en.wikipedia.org/wiki/Fixed-point_arithmetic))

Fixed-point numbers are often used in graphics where efficiency is more important than precision. Fixed-point numbers are **stored as integers**, where a fixed part of the bits represents the **fractional bits**. 

As fixed-point numbers are stored as integers, the only difference is what the bits represent. For a 32-bit signed integer, the bits represent:

$-2^{31}, 2^{30}, 2^{29}, ... , 2^2, 2^1, 2^0$

There are no fractional bits. In a fixed-point number, the bit places represent not only integral bits but also fractional bits. This is how the bits of a fixed-point number with 8 fractional bits is interpreted:

$-2^{23} , 2^{22}, 2^{21}, ... , 2^1, 2^0, 2^{-1}, ... , 2^{-7}, 2^{-8}$

Thus, the fixed-point number cannot represent MAX_INT (because it lacks integral bits for this) but it can represent decimal numbers, e.g. 2.5.

So, when you want to **convert an integer to a fixed-point number** and vice versa, you have to use **bit shifting**.

In order to store an int as a fixed-point number, you shift the number number_of_fractional_bits times to the left:

	int fixedPoint = int i << fractionalBits;

When you want to reverse it (fixed-point to int), you just shift it to the right:

	int i = int fixedPoint >> fractionalBits;


Fixed-point numbers are not as precise as floating point numbers because they only have a limited amount of fractional bits. 


For example: When you want to store numbers for a currency, you only need to have a fractional part that can respresent numbers from 0 to 99. For this range you would need 7 fractional bits(is this correct?).

So, you would not be able to represent 10.257 with the fixed-point number but would have to round it. Therefore, when storing a [floating point number](#Floating-Point-Numbers) as a fixed-point number you have to round it (roundf()).

	int fixedPoint = roundf( float_f * (1 << fractionalBits));

which is the same as: fixedPoint = float_f * 2^(fractionalBits).

If you want to **convert a fixed-point number to a float** you do the reverse and divide:

	float f = (float)fixedPoint / (1 << fractionalBits)


### Floating Point Numbers

- 4-byte floating point number can hold fewer distinct values than a 4-byte integer

#### Accuracy vs. Precision

Accuracy = how close to the true value
Precision = how precise ( 5 / 2)

Integers are 100% accurate: 2 is 2, not more not less. So, whatever arithmetic operations we do with integers, there will be no overflow.

However, integers are not precise. If we divide 5 by 2 or 4 by 2, both will be 2.

Floating point numbers have a good precision (never discard info: 5 / 2 = 2.5) but low accuracy (e.g. 1/3).

#### Representation of Floating Numbers
Bits representing an integer are interpreted literally as a binary number.

Info from: https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html

# CPP03
## Inheritance

Classes can inherit from one another. This means that the class which inherits from another class (a **derived class**) inherits all the member variables and member functions from the **base class**. 

	class Cat : public Animal

The Cat class will inherit all the members of the Animal class. On top of that, it can add its own members. However, it does **not inherit** the constructors and destructors, the assignment operator memebers (=), the friends and private members. They have to be declared again. 

But the constructors and destructors of the base class will be called automatically, when the derived class is constructed or destructed. By default, the default constructor of the base class will be called. If you want another constructor of the base class to be called (i.e. one taking parameters), you have to specify it in the following way:

	Cat ( int a ) : Animal ( a ) // Constructor

The keyword after the colon specifies the accessibility the inherited members will have. If it is **public**, the derived class will have the same accessibily to the inherited members as the base class has: public members of the base class, will be public members in the derived class, too; protected members, will be protected. If it is set to **protected**, the public members of the base class, will be protected members in the derived class. If no keyword is specified, the compiler will assume the keyword to be **private**. This means that all inherited members will be private automatically. So, the keyword after the colon specifies the **less restrictive access level** of the members to be inherited. It is most common to use the **public** keyword. 

## Multiple Inheritance

A class can inherit from multiple base classes. After the colon you just classify the base classes separated by commas:

	class Cat : public Predator, public Pet;

### Diamond Problem

When a class inherits from two classes which are based on the same base class, it is called a diamon-shaped inheritance structure.

		A
	  /   \
	B		C
	  \   /
	    D

This can lead to ambiguity issues because the derived class effectively inherits two copies of the base class due to the multiple paths through the inheritance hierarchy. When we construct an object D, A will be constructed two times: 1 time to construct B and 1 time to construct C:

	Constructor A
	Constructor B
	Constructor A
	Constructor C
	Constructor D

This problem can be solved by **virtual inheritance**. Class B and C inherit virtual class A:

	class B: virtual public A;
	class C: virtual public A;
	class D: public B, public C;

This means, that as soon as C will be created, the compiler knows that there already is a copy of A and will not create it again:

	Constructor A
	Constructor B
	Constructor C
	Constructor D

### Ambiguity Problems of Mulitple Inheritance

When B and C are the base classes of D and both, B and C, have the same member function or variable, D will inherit both. When we then want to call that function or set that variable in our main, the compiler will throw an error. We have to specify which of these two functions D inherited should be used. We can just specify in the main which function to call, e.g.:

	D	derived;
	derived.B::function();

It might, however, make more sense to choose which member function or variable should be inherited when declaring D. Then only one of the functions will be inherited. To do so, use the following syntax:

	class D: public B, public C{

		public:
			void function(){
				B::function();
			}
	}

A more readable and shorter way, would be to use the keyword **using** to specify which of the inherited functions to use. Then you do not have to re-declare the function:

	class D: public B, public C {

		public:
			using B::function;
	}

# CPP04

## Polymorphism

Building on the part of inheritance in cpp03, cpp04 introduces polymorphism. 

What is polymorphism?

If you have a base class (Animal) and a derived class (Cat), which both have the same function makeSound() and create a pointer of type Animal which points to a Cat, you will get a message from the compiler warning you about **polymorphism**.

	class Animal {
		//Constructors & Destructor

		void	makeSound() {
			std::cout << "animal sound" << std::endl;
		}
	}

	class Cat : public Animal {
		// Constructors & Destructor

		void	makeSound() {
			std::cout << "meow" << std::endl;
		}
	}

	int	main ( void ) {

		Animal*	A = new Cat();

		A->makeSound();

		return 0;
	}

To solve this problem and make A act like a cat and not like an animal, we can use the keyword **virtual** (similar to the Diamond Problem above). We put "virtual" in front of the function makeSound() in both classes. Now the function will not be linked static but **dynamic**. This means that the compiler will look at the point of **execution** (and not compilation) which function to use: it will go down the whole inheritance tree and pick the right function (in this case the function of Cat). Otherwise (at the point of compilation), it would statically link the function of the type (in this case Animal) and the Cat A would make an animal sound instead of a cat sound. 

A virtually linked member function is called a **method**.

	class Animal {
		//Constructors & Destructor

		virtual void	makeSound() {
			std::cout << "animal sound" << std::endl;
		}
	}

	class Cat : public Animal {
		// Constructors & Destructor

		virtual void	makeSound() {
			std::cout << "meow" << std::endl;
		}
	}

	int	main ( void ) {

		Animal*	A = new Cat();

		A->makeSound();

		return 0;
	}

## Array of Objects

To declare an array of objects of the same class, use the following syntax:

	ClassName	ObjectName[number of objects];

	Animal		array[10];

If however, you want the array to contain different objects (for example dogs AND cats), you have to use a pointer:

	Animal*		array[2];

	array[0] = new Dog();
	array[1] = new Cat();

You may then delete the objects by simply looping through the array:

	for (int i = 0; i < 2; i++)
		delete array[i];

## Copies: Shallow vs. Deep Copy

If you copy an instance and you have not declared a copy constructor yourself, the compiler will use a default copy constuctor which will create a **shallow copy**. 

	Animal1 = Animal2;

This shallow copy is totally sufficient if the Animal class only has variables, e.g. strings and integers:

	class	Animal {

		public:
			// Constructors & Destructor

		private:
			std::sting	_name;
			int			age;
	}

Animal1 will have the same name and age as Animal2. The copy worked all fine. However, this does not work for pointers. If you have a pointer, the default copy constructor will copy the memory address that pointer points to.

	class	Animal {

		public:
			// imagine Constructors here

			~Animal() {

				free(age);
			}

			int	*		age;

		private:
			std::sting	_name;
	}

 Thus, Animal1 and Animal2 will point to the exact same memory address. Animal2's age pointer will point to the same allocated memory on the heap as the Animal1's age pointer. And so, if you change Animal1's age, Animal2's age will be changed, too.
 
	Animal1 = Animal 2;

	*(Animal1.age) = 5;

The other problem is that the program will crash at the end of main() because both destructors for Animal1 and Animal2 will try to free the same pointer. In this case (when dealing with pointers), you need a **deep copy** and have to implement your own copy constructor where you define how instances of the Animal class should be copied. 

	Animal( const Animal& otherAnimal ) {
		
		age = (int*) malloc(sizeof(int));
		*age = *(otherAnimal.age);
	}

Therefore, it is important to use the Orthodox Canonical Form where you specify in your copy assignment operator and copy constructor how an instance of this class should be copied. 

## Additional Notes

For style, see: https://google.github.io/styleguide/cppguide.html

In cpp00/ex01: Don't mix methods. The setter functions of the Contact class should only set the info and not std::cin -> this is part of the phonebook class.

Use one style: either function( void ); function(void); or function()

