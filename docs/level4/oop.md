# Object Orientated Programming

In the previous lab, we saw how classes can be used to encapsulate data and functions, such that complexity is hidden, and a programming interface is exposed that is both safer and easier to use.

One of the benefits of class types is that code can be more easily shared and reused.

One of the ways we saw class objects being reused was with **composition**, where members of a class we also class-types. As long as the public interface is sufficient, this is an often preferred way to re-use code.

In this section, we will look at another more subtle way to re-use code in a class, and that is through **inheritance**. This is a subject that can get complex very quickly, to the point that it might be viewed as counter-productive (I really don't want to start a flame war here). 

**Contents**

* [Object Orientated Programming](#object-orientated-programming)

   * [Object Inheritance](#object-inheritance)

   * [Overriding Behaviour](#overriding-behaviour)

   * [Composition: Initialisation and Access](#composition-initialisation-and-access)

   * [Operator Overloading](#operator-overloading) 

   * [Challenges](#challenges)

* [Advanced Topics](#advanced-topics)

   * [Copy Constructors](#copy-constructors)

   * [Polymorphism](#polymorphism)

   * [Pure Virtual Functions](#pure-virtual-functions)

      * [Example - Dependency Injection (DI)](#example---dependency-injection-di)

    * [Lambda Functions and Closures](#lambda-functions-and-closures)

    * [Smart Pointers](#smart-pointers)

    * [Advanced Challenges](#advanced-challenges)

---
   
## Object Inheritance

We begin this discussion with what object inheritance is not - it is not composition. Consider the following example:

```C++
class Dog {
    private:
    string _name;
    int _age;

    public Dog(string name, int age) {
        _name = name;
        _age = age;
    }
    void bark() {
        cout << "Woof" << endl;
    }
};
```

The class `Dog` **has a** member called `name`, of type `string` and an age of type `int`. This is using composition. It reuses the code in `string` to make it easier to process string data. Access is limited to the public API of `string`.

Now consider the following class:

```C++
class Pet {
protected:
    string _name;
    int age_;

public:
    public Pet(string name, age) {
        _name = name;
        _age = age;
    }
};
```

This is more generic. It has some of the attributes of `Dog`, but nothing unique to `Dog`. It is noted that cats also have names and an age, as well as more specialist properties. This class models the generic properties of a pet (we might add more later).

> Note how `private` was changed to `protected`. These are similar, but difference will be explained below.

We can now create two other *more specialist* classes which **inherit** all the properties of `Pet`, and add some unique characteristics:

```C++
class Dog : public Pet 
{
public:
    public Dog(string name, int age) : Pet(name, age) {
    }
    void bark() {
        cout << name << " says Woof" << endl;
    }
}
```

The `Dog` class **inherits** all the properties of `Pet`, but **adds** the additional ability to bark. 

* The class declaration uses the `:` operator to designate any **parent class(es)**. 

```C++
   class Dog : public Pet
```

* The `Dog` class does not need to include a `name` or `age` property as it inherits both from `Pet`. 

* The `Dog` class is in effect **reusing** the properties and code in `Pet`, and adding additional functionality of it's own (`bark()`).

Similarly, cats are also pets. They differ from dogs in the sounds they make. We could therefore do something similar here:

```C++
class Cat : public Pet 
{
public:
    Cat(string name, int age) : Pet(name, age) {
    
    }

    void meow() {
        cout << name << " says Meow" << endl;
    }
}
```

Again, the `Cat` class **inherits** the all the properties of `Pet`, but adds the additional ability to make the sound *meow*.

**Important: the <u>is-a</u> relationship**

In the examples above, both `Cat` and `Dog` share a **parent class** `Pet`. They both inherit all the properties and functions of a `Pet`.

> Imagine you were playing a game of "guess what I am thinking of". The first question might be: "Does it have a name"?, to which the answer is "YES". The next question might be: "Does it have a biological age?", to which the answer is also "YES".
>
> With these two pieces of information, the player could equally say "It is a Cat", "It is a Dog" or "It is a Pet". Given this information, they are logically indistinguishable.

* A `Dog` inherits all the properties of `Pet`, so we can say that **`Dog` <u>is a</u> `Pet`**, as well as being a `Dog`
* A `Cat`  inherits all the properties of `Pet`, so we can say that **`Cat` <u>is a</u> `Pet`**, as well as being a `Cat`
* A `Pet` is NOT a dog or a cat, as it does not contain the specialist attributes that characterise specific animals.

When we think about the relationship between two objects, we can say the following:

* where one object **is a** special form of another, then this is a candidate for **inheritance**.
* where one **has a** property that is fulfilled by another, then this is a candidate for composition


### Protection in Class Inheritance

Let's look at an example of class **inheritance**. From this we will discover some fundamental mechanisms in object orientated programming.

| TASK | 01-Inheritance_and_Protection |
| - | - |
| 1. | Open the solution `OOP` and [watch this video](https://plymouth.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=77ff9aef-9842-445d-bff4-b0b300bd5c99)
| 2. | Make `01-Inheritance_and_Protection` the start up project |
| 3. | Build and debug as shown in the video. |
| 4. | In the `Pet` class, add a setter and getter function for the age |
| - | The age should only be changed if it is in the range of 0..30 |
| - | Write to the terminal to inform the user about the change |
| 5. | Write some code in `main` to test this API |
| 6. | A solution is provided |

**Key Points**
* A subclass inherits all members (variables and functions) from a parent class
   * A subclass has direct access to all `public` and `protected` member functions and variables
   * Where a parent member is `private`, the subclass will not have access
* Constructors need to be called from the top of the hierarchy down.
   * The `Pet` constructor runs first, then the subclass.
* As seen previously, only `public` members are accessible outside of the class hierarchy.
* Subclasses often **extend** the functionality of their parents by adding additional members

## Overriding Behaviour

So far we have seen how we can **extend** the functionality of a parent class by **inheritance**.

Sometimes we need to change the behaviour of a member function that we inherit. In the previous example, the `setAge` API checked the age was in the range 0..30. However, other animals will have other life spans.

| TASK | 02-OverridingBehaviour |
| - | - |
| 1. | Make `02-OverridingBehaviour` the startup project |
| 2. | Create another class `Tortoise` that inherits `Pet` |
| 3. | Add the following member function to the `Tortoise` class: |

```C++
void setAge(int a) {
    //Only update if in range.
    if ((a >= 0) && (a <= 250)) {
        cout << "Changing the age of " << _name << " from " << _age << " to " << a << endl;
        _age = a;
    }
}
```

| TASK |  |
| - | - |
| 4. | Uncomment the lines `//Tortoise t1("Speedy", 50);` and `//t1.setAge(101);` |
| 5. | Build and step into the `setAge` functions for `c1` and `t1` |
| - | As you step in, note where in the class hierarchy the function is written |
| - | A solution is provided |

Sometimes you want to call a version higher up in the hierarchy. To do this, you need to use the scoping operator `::` to specify the class. For example:

```C++
t1.Pet::setAge(101);
```

This would explicitly call the version in the `Pet` class, and not the `Tortoise` class.


**Key Points**
* When you inherit a parent class, you inherit all the member functions
* If you want to override the behaviour of a class in a parent class, you can write another version. 
   * You must use the exact same parameters, function name and return type.
* You can still explicitly call a version in a parent class by prefixing the function name with the classname and the scoping operator `::`

## Composition: Initialisation and Access


## Operator Overloading

## Challenges

# Advanced Topics

## Copy Constructors

## Polymorphism

## Pure Virtual Functions

### Example - Dependency Injection (DI)

## Lambda Functions and Closures

## Smart Pointers

## Advanced Challenges

---

[Back to Table of Contents](./README.md)